/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Assignment 1 - Structs - Planes
# Date:             June 28, 2024 (redo on Sun, July 7, 2024)
# Description:      Example: This menu-driven program loads data from a text 
                    file that holds data on planes. Each plane is a struct, and
                    then within an array. User can choose to view the plane
                    inventory, add a plane, view all planes, remove a plane by
                    the index, or quit the program. Program includes data 
                    validation for user error.
# Input:            result (bool): T/F based on result of opening the file
                    ADD MORE HERE
# Output:           ADD MORE HERE
# Sources:          Lab 1 specifications, theZoo example, Zybooks Ch. 15
#                   
#******************************************************************************/

#include "airplane.h"

int main() {

    // create variables / arrays
    char choice = ' ';
    Airplane planes[ARR_SIZE];
    ifstream inFile; 
    bool result = false;
    bool success = false;
    int count = 0; // how many types of planes
    int newIndex = -1; // Index of newly added plane

    // set result to results of opened file, false = fail
    result = openTheFile(inFile);

    // if statement for result(true)
    if (result) {
    // then set COUNT (types of planes) to = loadPlanes(reads array             of structs)
        count = loadPlanes(planes, inFile);
        inFile.close();
        cout << endl << count << " planes were loaded from the file.\n";
        printPlanes(planes, count);
    }

    // Menu-driven loop
    do {
        cout << "\nWhat would you like to do?\n" << 
        "(A)dd a plane\n" << "(L)ist all planes\n" << "(R)emove a plane by index\n" <<
        "(S)earch for a plane\n" << "List all planes by (M)ake\n" <<
        "or (Q)uit?\n";
        cin >> choice;
        cin.ignore();
        choice = toupper(choice); // convert to uppercase
        switch(choice) {
            case 'A': {
                success = addPlane(planes, count, newIndex);
                if(success && newIndex != -1) {
                    cout << "\n\nSuccessfully added " << planes[newIndex].model << " "
                        << planes[newIndex].make << " plane to the database." << endl;
                } else {
                    cout << "Not added, the array is out of room." << endl;
                }
                break;
            }
            case 'L':
                printPlanes(planes, count);
                break;
            case 'R':
                int index;
                cout << "Enter the index of the plane to remove: ";
                cin >> index;
                while (cin.fail() || index < 1 || index > count) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid index. Please enter a valid index between 1 and " << count << ": ";
                    cin >> index;
                }
                index--; // Adjust to 0-based index
                for (int i = index; i < count - 1; i++) {
                    planes[i] = planes[i + 1];
                }
                count--;
                cout << "\nSuccessfully removed plane at index " << index + 1 << "." << endl;
                break;
            case 'S':
                searchByModel(planes, count);
                break;
            case 'M':
                listByMake(planes, count);
                break;
            case 'Q':
                cout << "Database file updated. Terminating program." << endl;
                return 0;
            default:
                cout << "\nOption not recognized.\n" << endl;
        }
    } while(choice != 'Q');
    writePlane(planes, count);
    cout << "\nDatabase file updated. Terminating Program.\n";
    return 0;
}
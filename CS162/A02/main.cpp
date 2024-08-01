/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A02 - Classes - Planes/Fleets
# Date:             Monday, July 15, 2024 (re-submission)
# Description:      This program uses nested classes, Airplane and Fleet, to 
#		    set private and public member functions and data. The 
#		    program is multi-file, and allows a user to add a plane, 
#                   remove a plane, view the planes, search planes, etc using 
#                   constructors, functions, etc.
#    
# Input:            This program uses an Airplane Class with public and private
#		    data. There are setters and getters uses to manipulate the
#                   data into an output file. The Airplane Class is nested 
# 		    within the Fleet Class. There are arrays used to verify,
#		    and change the data in the database into an output.txt file.
# Output:           New database of planes in the fleet database after each 
# 		    change made by the user.
# Sources:          Mr. Martin's notes/example code/email & Zybooks + notes
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// You don't need to include these three lines in your program!
#include "fleet.h"

using namespace std; 

/* To Run program: 

First compile (in terminal):
    g++ -Wall -g -o output.txt *.cpp
then run executable file:
    ./output.txt

 */

int main() {
    Fleet myFleet;
    bool success;
    int count = 0; // *NEW*

    welcome();
    
    // Initial loading of planes from file
    if(!myFleet.openTheFile()){
        cout << "\nQuitting the program since the file didn't open." << endl;
    }
    else {
    // Count works now!
    count = myFleet.loadPlanes();
    cout << endl << endl << count << " planes were loaded from the file.\n";
    myFleet.printPlanes();
    
    char option;
    do {
        cout << "\nChoose an option:\n";
        cout << "L: List All Planes\n";
        cout << "M: List Planes by Make\n";
        cout << "A: Add a New Plane\n";
        cout << "R: Remove a Plane\n";
        cout << "Q: Save and Quit\n\n";
        cin >> option;
        option = toupper(option);// ADDED
        cin.ignore(); // clear the newline character from the buffer

        switch(option) {
            case 'L':
                myFleet.printPlanes();
                break;
            case 'M':
                myFleet.listByMake();
                break;
            case 'A':
                // CHANGED
                success = myFleet.addAPlane();
                if(!success) {
                    cout << "\n\nThe new plane was not added. Out of room.\n\n";
                }
                break;
            case 'R':
                myFleet.removeAPlane();
                break;
            case 'Q':
                myFleet.writePlanes();
                cout << "\nDatabase file updated. Terminating program.\n\n";
                break;
            default:
                cout << "\nInvalid option. Please try again.\n";
        }
    } while (option != 'Q');

    return 0;
    }
}

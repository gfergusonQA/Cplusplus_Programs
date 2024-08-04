/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A03 - Dynamic Memory - Planes/Fleets
# Date:             Saturday, August 3, 2024
# Description: This airplane database represents a fleet. The user-
#              driven menu uses a do while loop. The user can view,
#              add, remove, search, and list by make the planes in the
#              file. Then the program writes to an output.txt file
#              with the updates.
#    
# Input:      The program takes multiple inputs, including file names,
#              airplane details (model, make, fuel capacity, empty
#              weight, engine horsepower, max range, and cruise speed),
#              and menu options to perform different operations on the
#              fleet.
# 
# Output:     The program outputs various information to the console,
#              including the list of airplanes, search results,
#              confirmation messages for adding and removing airplanes,
#              and error messages for invalid inputs. It also writes
#              the updated list of airplanes to an output.txt file.
# Sources:    Mr. Martin's notes/example code/email & Zybooks + notes
#******************************************************************************/
#include "fleet.h"

int main() {
    Fleet fleet;
    bool success = false;
    int count = 0;
    char option = ' ';

    welcome();

    if(!fleet.openTheFile()) {
        cout << "\nQuitting the program because the file didn't open.\n";
    } else {
        count = fleet.loadPlanes();
        cout << endl << count << " planes were loaded from the file.\n";
        fleet.printPlanes();
    }

    do {
        displayMenu();
        cin >> option;
        option = toupper(option);
        cin.ignore();

        switch (option) {
            case 'L':
                fleet.printPlanes();
                break;
            case 'M':
                fleet.listByMake();
                break;
            case 'A':
                success = fleet.addAPlane();
                if (!success) {
                    cout << "\n\nThe new plane was not added. "
                        "Out of room.\n\n";
                }
                break;
            case 'R':
                fleet.removeAPlane();
                break;
            case 'S': {
                fleet.search();
                break;
            }
            case 'Q':
                fleet.writePlanes();
                break;
            default:
                cout << "\n\nInvalid choice. Please try again.\n" << endl;
                break;
        }
    } while (option != 'Q');

    return 0;
}

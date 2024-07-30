#include "tools.h"
#include "Fleet.h"

using namespace std;

int main() {
    // Create variables / object
    bool success = false;
    bool result = false;
    int count = 0;
    char searchName[STR_SIZE];
    char choice = ' ';

    Fleet fleet; // construct 'fleet' from Fleet class

    result = fleet.openTheFile(); // 

    if(result) {
        count = Fleet::loadPlanes(planes, inFile);
        Fleet::inFile.close();
        cout << endl << count << " planes were loaded from the file.\n";
        Fleet::printPlanes();
    }

    int loadedCount = fleet.loadPlanes();
    cout << "\nSuccessfully loaded " << loadedCount << " airplanes." << endl;
    fleet.printPlanes();

    char option;
    do {
        displayMenu();
        cin >> option;
        option = toupper(option);

        switch (option) {
            case 'A':
                if (fleet.addAPlane()) {
                    cout << "\nSuccessfully added the airplane to the database." << endl;
                }
                break;
            case 'L':
                fleet.printPlanes();
                break;
            case 'R':
                if (fleet.removeAPlane()) {
                    cout << "\nSuccessfully removed the airplane from the database." << endl;
                }
                break;
            case 'S': {
                char model[STR_SIZE];
                cout << "\nFor what airplane would you like to search? ";
                cin.ignore();
                cin.getline(model, STR_SIZE);
                fleet.searchAirplaneByModel(model);
                break;
            }
            case 'M':
                fleet.listByMake();
                break;
            case 'Q':
                fleet.writePlanes();
                cout << "Database file updated. Terminating Program."
                    << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (option != 'Q');

    return 0;
}

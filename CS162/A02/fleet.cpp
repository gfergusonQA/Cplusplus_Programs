/*
#******************************************************************************
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference. */

#include "fleet.h"
#include "tools.h"

//Name: Fleet:Fleet() CONSTRUCTOR
//Desc: This is the constructor for Fleet, initialized with an empty string in
//      order to prevent garbage data for fileName, and make sure its clear.
//Input: 
//Output: 
//Return: 
Fleet::Fleet() {
    count = 0;
    strcpy(fileName, "");
}

//Name:   openTheFile()
//Desc:   Shows welcome message, opens the file, and checks for data validation
//input:  fileName (char array): file name being opened
//output: success (bool), output messages
//return: success (bool), starts as false, returns true if file opens
bool Fleet::openTheFile() {
    bool success = false;
    cin.getline(fileName, STR_SIZE);
    inFile.open(fileName);

    while(!inFile.is_open() && strcmp(fileName, "Q") != 0) {
        cout << "\n*** The file " << fileName << " was not found. "
            "Try again or type 'quit' to exit the program: ";
        cin.getline(fileName, STR_SIZE);
        inFile.open(fileName);
    }
        if (inFile.is_open()) {
            success = true;
        }
    return success;
}

//Name:   insert()
//Desc:   This function inserts the airplane using a for loop in an array
//input:  none
//output: tempPlane array data printed to console
//return: result (boolean): begins as false, returns true if there's a match
bool Fleet::insert() {
    bool result = false;
    int index = 0;
    
    // Limit is 20
    if (count < ARR_SIZE) {

    // Part 1: If the tempPlane model is greater than 0, 
    //         (tempPlane model is alphabetically after 
    //         fleetAirplanes), then we break out of the loop.
    for (index = 0; index < count; ++index) {
        if (strcmp(fleetAirplanes[index].getModel(), 
            tempPlane.getModel()) > 0) {
            break;
        }
    }
    // Part 2: Shift the array to the right
    for (int i = count; i > index; --i) {
        fleetAirplanes[i] = fleetAirplanes[i - 1];
    }
    // Part 3: Insert the tempPlane into the array
    fleetAirplanes[index] = tempPlane;
    ++count;
    result = true;
    cout << endl;
    cout << "--> " << tempPlane.getModel() << " plane data was "
        "successfully inserted.";
    }
    return result; // if true in loadPlanes() hops out of loop, closes file
}

//Name:   loadPlanes()
//Desc:   Loads planes using tempPlane array, and uses 
//        setter functions to insert each section
//input:  line (array), setters return make, model, etc
//output: none
//return: return count (in the Fleet class)
int Fleet::loadPlanes() {
    // File is already open
    double fuel = 0.0;
    int weight = 0;
    int hp = 0;
    int range = 0;
    int speed = 0;
    // Removed count *NOTE FOR LATER* local was breaking the function 
    bool result = false;
    char line[STR_SIZE];

    while (inFile.getline(line, STR_SIZE, ';')) {
        tempPlane.setModel(line);
        
        inFile.getline(line, STR_SIZE, ';');
        tempPlane.setMake(line);

        inFile >> fuel;
        inFile.ignore(1, ';');
        tempPlane.setMaxFuel(fuel);

        inFile >> weight;
        inFile.ignore(1, ';');
        tempPlane.setEmptyWeight(weight);

        inFile >> hp;
        inFile.ignore(1, ';');
        tempPlane.setEngineHP(hp);

        inFile >> range;
        inFile.ignore(1, ';');
        tempPlane.setMaxRange(range);

        inFile >> speed;
        inFile.ignore(1, '\n');
        tempPlane.setCruiseSpeed(speed);

        // Insert the plane into the array
        result = insert();
        // Check for room
        if(result == false) {
            cout << "\nNot all planes were loaded from the file, "
                    "out of room! " 
                    "The program is now ending, please try again.\n";
            break;
        }
    }
    inFile.close();
    return count; // This count is correct & private in Fleet class
}

//Name:   printPlanes()
//Desc:   This function
//input:  None
//output: prompt
//return: string name
void Fleet::printPlanes() {
    // Print the header
    cout << endl; // Need an extra line
    cout << endl;
    cout << right << setw(4) << "" // Empty space for the index column
         << left << setw(22) << "Model"
         << left << setw(15) << "Make"
         << right << setw(6) << "Fuel"
         << right << setw(9) << "Weight"
         << right << setw(5) << "HP"
         << right << setw(7) << "Range"
         << right << setw(9) << "Speed" << endl;

    // Print a separator line
    for (int i = 0; i < 76; ++i) {
        cout << '-';
    }
    cout << endl;

    // Print the planes
    for (int i = 0; i < count; ++i) {
        cout << right << setw(2) << i + 1 << ". "
             << left << setw(22) << fleetAirplanes[i].getModel()
             << left << setw(15) << fleetAirplanes[i].getMake()
             << right << setw(6) << fleetAirplanes[i].getMaxFuel()
             << right << setw(9) << fleetAirplanes[i].getEmptyWeight()
             << right << setw(5) << fleetAirplanes[i].getEngineHP()
             << right << setw(7) << fleetAirplanes[i].getMaxRange()
             << right << setw(9) << fleetAirplanes[i].getCruiseSpeed() << endl;
    }
}

//Name:   listByMake()
//Desc:   Printing out the fleetAirplanes array by all categories
//input:  make array: holds list to print
//output: display string messaging and class index + functions
//return: none
void Fleet::listByMake() {
    char make[STR_SIZE];
    cout << "\nPlease type the make of the airplanes you would "
            "like to list: ";
    cin.getline(make, STR_SIZE);

    // Print the header
    cout << endl; // Need an extra line for format
    cout << right << setw(4) << "" // Empty space for the index column
             << left << setw(22) << "Model"
             << left << setw(15) << "Make"
             << right << setw(6) << "Fuel"
             << right << setw(9) << "Weight"
             << right << setw(5) << "HP"
             << right << setw(7) << "Range"
             << right << setw(9) << "Speed" << endl;

        // Print a separator line
        for (int i = 0; i < 77; ++i) {
            cout << '-';
        }
        cout << endl;
        cout << "\n\n\nFIXME:  Add 'The airplanes in the list made by "
        "fleet.Airplanes[i].getMake() are: \n\n\n";

        // Print the planes that match the Make the user input
        for (int i = 0; i < count; ++i) {
            if (strcmp(fleetAirplanes[i].getMake(), make) == 0) {
                cout << right << setw(2) << i + 1 << ". "
                     << left << setw(22) << fleetAirplanes[i].getModel()
                     << left << setw(15) << fleetAirplanes[i].getMake()
                     << right << setw(6) << fleetAirplanes[i].getMaxFuel()
                     << right << setw(9) << fleetAirplanes[i].getEmptyWeight()
                     << right << setw(5) << fleetAirplanes[i].getEngineHP()
                     << right << setw(7) << fleetAirplanes[i].getMaxRange()
                     << right << setw(9) << fleetAirplanes[i].getCruiseSpeed() 
                     << endl;
            }
        }
        cout << "\n\n\nFIXME:  remove printed menu if 0 planes!\n\n\n";
    }

//Name:   addAPlane()
//Desc:   Fleet array constructor to add a plane to the database 
//input:  plane array in the Airplane class that is used to grab the user info
//	  for airplane mode, make, fuel, weight, range, and cruise speed
//output: Messaging to console for prompt or error
//return: insert (boolean function): return the results of insert()
bool Fleet::addAPlane() {
    Airplane plane;
    char input[STR_SIZE];
    double dVal = 0.0;
    int iVal = 0;

    cout << "\nWhat is the model (name) of the airplane? ";
    cin.getline(input, STR_SIZE);
    plane.setModel(input);

    cout << "What is the make (manufacturer) of the airplane? ";
    cin.getline(input, STR_SIZE);
    plane.setMake(input);

    cout << "What is the fuel capacity in gallons? ";
    cin >> dVal;
    while (cin.fail() || dVal <= 0.0 || dVal > 150.0) {
        cin.clear();

        cin.ignore(INT_MAX, '\n');
        cout << "Please enter a decimal number for fuel capacity between "
                "1.00 and 150.00: ";
        cin >> dVal;
    }
    plane.setMaxFuel(dVal);
    cin.ignore(INT_MAX, '\n');

    cout << "What is the empty weight? ";
    cin >> iVal;
    while (cin.fail() || iVal <= 0 || iVal > 3000) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The weight must be a whole number between 1 and 3000 pounds: ";
        cin >> iVal;
    }
    plane.setEmptyWeight(iVal);
    cin.ignore(INT_MAX, '\n');

    cout << "What is the horsepower of the engine? ";
    cin >> iVal;
    while (cin.fail() || iVal <= 0 || iVal > 400) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The horsepower must be a whole number between 1 and 400: ";
        cin >> iVal;
    }
    plane.setEngineHP(iVal);
    cin.ignore(INT_MAX, '\n');

    cout << "What is the range? ";
    cin >> iVal;
    while (cin.fail() || iVal <= 0 || iVal > 2000) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The range must be a whole number between 1 and 2000: ";
        cin >> iVal;
    }
    plane.setMaxRange(iVal);
    cin.ignore(INT_MAX, '\n');

    cout << "What is the cruise speed? ";
    cin >> iVal;
    while (cin.fail() || iVal <= 0) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The cruise speed must be a positive whole number: ";
        cin >> iVal;
    }
    plane.setCruiseSpeed(iVal);
    cin.ignore(INT_MAX, '\n');

    tempPlane = plane;
    return insert();
}

//Name:   removeAPlane()
//Desc:   This boolean function uses the index of Fleet class 
//input:  index(integer): uses user input 
//output: mostly user messaging + count
//return: true (this is a boolean constructor function)
bool Fleet::removeAPlane() {
    int index;
    cout << "\nWhich index would you like to remove (1 – " << count << ")? ";
    cin >> index;
    while (cin.fail() || index < 1 || index > count) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid Index. Please type an index between 1 and " << 
                count << ": ";
        cin >> index;
    }
    index--; // Convert to 0-based index

    cout << "\n\n\nFIXME: Need to tell user which index # was removed to "
            "confirm.\n\n\n";

    for (int i = index; i < count - 1; ++i) {
        fleetAirplanes[i] = fleetAirplanes[i + 1];
    }
    --count;
    return true;
}

//Name:   writePlanes()
//Desc:   This function sends the current plane database to an output .txt file
//input:  None
//output: the fleetAirplanes array, using getter functions
//return: none
void Fleet::writePlanes() {
    char outputFileName[STR_SIZE];
    cout << "\nEnter the name of the file to save airplane data: ";
    cin.getline(outputFileName, STR_SIZE);
    cin.ignore(100, '\n');

    ofstream outFile(outputFileName);
    for (int i = 0; i < count; ++i) {
        outFile << fleetAirplanes[i].getModel() << ";"
                << fleetAirplanes[i].getMake() << ";"
                << fleetAirplanes[i].getMaxFuel() << ";"
                << fleetAirplanes[i].getEmptyWeight() << ";"
                << fleetAirplanes[i].getEngineHP() << ";"
                << fleetAirplanes[i].getMaxRange() << ";"
                << fleetAirplanes[i].getCruiseSpeed() << endl;
    }
    cout << "\n\n\nFIXME: output file going incorrectly saving to "
            "airplanes.txt.\n\n\n";
    outFile.close();
}

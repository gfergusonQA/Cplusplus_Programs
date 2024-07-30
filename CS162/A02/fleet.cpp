#include "fleet.h"
#include "tools.h"

Fleet::Fleet() : count(0) {
    strcpy(fileName, "");
}

//Name:   openTheFile()
//Desc:   Shows welcome message, opens the file, and checks for data validation
//input:  fileName (char array): file name being opened
//output: success (bool), output messages
//return: success (bool), starts as false, returns true if file opens
bool Fleet::openTheFile() {
    bool success = false;
    char fileName[STR_SIZE];
    cout << "Welcome to the airplane collection program!\n"
        "\nWhat is the name of the airplane collection file? ";
    cin.getline(fileName, STR_SIZE);
    inFile.open(fileName);

    while(!inFile.is_open() && strcmp(fileName, "Q") != 0) {
        cout << "\n*** The file " << fileName << " did not open. Type 'Q' to"
            " quit, or try again now: ";
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
    if (count < ARR_SIZE) {
    int index;
    for (index = 0; index < count; ++index) {
        if (strcmp(fleetAirplanes[index].getModel(), tempPlane.getModel()) > 0) {
            break;
        }
    }
    for (int i = count; i > index; --i) {
        fleetAirplanes[i] = fleetAirplanes[i - 1];
    }
    fleetAirplanes[index] = tempPlane;
    ++count;
    result = true;
    cout << endl;
    cout << tempPlane.getModel() << " plane data was successfully inserted." << endl;
    }
    return result;
}

//Name:   loadPlanes()
//Desc:   Loads planes using tempPlane array, and uses setter functions to insert each section
//input:  line (array), setters return make, model, etc
//output: none
//return: return count (in the Fleet class)
int Fleet::loadPlanes() {
    // File is already open
    char line[STR_SIZE];
    double fuel = 0.0;
    int weight = 0;
    int hp = 0;
    int range = 0;
    int speed = 0;

    cout << endl;
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

        insert();
    }

    inFile.close();
    cout << endl;
    return count;
}

//Name:   printPlanes()
//Desc:   This function
//input:  None
//output: prompt
//return: string name
void Fleet::printPlanes() {
    cout << setw(20) << left << "\nModel"
         << setw(15) << left << "Make"
         << setw(15) << left << "Fuel Capacity"
         << setw(15) << left << "Empty Weight"
         << setw(15) << left << "Horsepower"
         << setw(15) << left << "Range"
         << setw(15) << left << "Cruise speed" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". "
             << setw(20) << left << fleetAirplanes[i].getModel()
             << setw(15) << left << fleetAirplanes[i].getMake()
             << setw(15) << left << fleetAirplanes[i].getMaxFuel()
             << setw(15) << left << fleetAirplanes[i].getEmptyWeight()
             << setw(15) << left << fleetAirplanes[i].getEngineHP()
             << setw(15) << left << fleetAirplanes[i].getMaxRange()
             << setw(15) << left << fleetAirplanes[i].getCruiseSpeed() << endl;
    }
}


//Name:   listByMake()
//Desc:   Printing out the fleetAirplanes array by all categories
//input:  make array: holds list to print
//output: display string messaging and class index + functions
//return: none
void Fleet::listByMake() {
    char make[STR_SIZE];
    cout << "\nPlease type the make of the airplanes you would like to list: ";
    cin.getline(make, STR_SIZE);

    cout << setw(20) << left << "\nModel"
         << setw(15) << left << "Make"
         << setw(15) << left << "Fuel Capacity"
         << setw(15) << left << "Empty Weight"
         << setw(15) << left << "Horsepower"
         << setw(15) << left << "Range"
         << setw(15) << left << "Cruise speed" << endl;
    cout << "-----------------------------------------------------------------"
	    "------------------------------------" << endl;

    for (int i = 0; i < count; ++i) {
        if (strcmp(fleetAirplanes[i].getMake(), make) == 0) {
            cout << i + 1 << ". "
                 << setw(20) << left << fleetAirplanes[i].getModel()
                 << setw(15) << left << fleetAirplanes[i].getMake()
                 << setw(15) << left << fleetAirplanes[i].getMaxFuel()
                 << setw(15) << left << fleetAirplanes[i].getEmptyWeight()
                 << setw(15) << left << fleetAirplanes[i].getEngineHP()
                 << setw(15) << left << fleetAirplanes[i].getMaxRange()
                 << setw(15) << left << fleetAirplanes[i].getCruiseSpeed() << endl;
        }
    }
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
        cout << "Please enter a decimal number for fuel capacity between 1.00 and 150.00: ";
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
        cout << "Invalid Index. Please type an index between 1 and " << count << ": ";
        cin >> index;
    }
    index--; // Convert to 0-based index

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
    ofstream outFile(fileName);
    for (int i = 0; i < count; ++i) {
        outFile << fleetAirplanes[i].getModel() << ";"
                << fleetAirplanes[i].getMake() << ";"
                << fleetAirplanes[i].getMaxFuel() << ";"
                << fleetAirplanes[i].getEmptyWeight() << ";"
                << fleetAirplanes[i].getEngineHP() << ";"
                << fleetAirplanes[i].getMaxRange() << ";"
                << fleetAirplanes[i].getCruiseSpeed() << endl;
    }
    outFile.close();
}

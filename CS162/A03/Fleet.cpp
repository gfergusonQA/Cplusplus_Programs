#include "fleet.h"

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

// Function: Fleet::Fleet()
// Description: Fleet constructor, initializes the Fleet object
// Inputs: none
// Outputs: none
// Return: none
Fleet::Fleet() {
    count = 0;
    capacity = 3;
    // allocate memory
    fleetAirplanes = new Airplane[capacity];
}

// Function: Fleet::~Fleet()
// Description: Fleet Destructor, releases dynamically allocated memory
// Inputs: none
// Outputs: none
// Return: none
Fleet::~Fleet() {
    delete[] fleetAirplanes;
}

// Function: Fleet::growArray()
// Description: Doubles the capacity of the fleetAirplanes array
//              and copies existing elements to the new array
// Inputs: none
// Outputs: none
// Return: none
void Fleet::growArray() {
    capacity *= 2;
    Airplane* newArray = new Airplane[capacity];
    for (int i = 0; i < count; ++i) {
        newArray[i] = fleetAirplanes[i];
    }
    delete[] fleetAirplanes;
    fleetAirplanes = newArray;
}

// Function: Fleet::insert()
// Description: Inserts an Airplane object into the fleetAirplanes array in lexicographical order by model
// Inputs: none
// Outputs: none
// Return: bool - true if insertion is successful, false otherwise
bool Fleet::insert() {
Airplane tempPlane = fleetAirplanes[count]; // use the last added plane
bool result = false;
int index = 0;
    
// If # of planes (count) is >= capacity, grow array!
if (count >= capacity) {
    growArray();
}

for (index = 0; index < count; index++) {
    if (strcmp(fleetAirplanes[index].getModel(), tempPlane.getModel()) > 0) {
        break;
    }
}

// Part 2 shift the array to the right
for (int i = count; i > index; i--) {
    fleetAirplanes[i] = fleetAirplanes[i - 1]; // copy indices -1 to itself
}

// Part 3: Insert the tempPlane into the array
fleetAirplanes[index] = tempPlane;
count++;
result = true;
cout << endl;
return result;
}

// Function: Fleet::loadPlanes()
// Description: Loads airplane data from the file into the 
//              fleetAirplanes array, sorted by model
// Inputs: none
// Outputs: none
// Return: int - the number of planes loaded
int Fleet::loadPlanes() {
    char model[STR_SIZE];
    char make[STR_SIZE];
    double maxFuel = 0.0;
    int emptyWeight = 0;
    int engineHP = 0;
    int maxRange = 0;
    int cruiseSpeed = 0;

    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cout << "Failed to open file." << endl;
        return -1;
    }
    
    // Needs to be sorted by model
    while (inFile.getline(model, STR_SIZE, ';')) {
        inFile.getline(make, STR_SIZE, ';');
        inFile >> maxFuel;
        inFile.ignore();
        inFile >> emptyWeight;
        inFile.ignore();
        inFile >> engineHP;
        inFile.ignore();
        inFile >> maxRange;
        inFile.ignore();
        inFile >> cruiseSpeed;
        inFile.ignore();

        Airplane plane;
        plane.setModel(model);
        plane.setMake(make);
        plane.setMaxFuel(maxFuel);
        plane.setEmptyWeight(emptyWeight);
        plane.setEngineHP(engineHP);
        plane.setMaxRange(maxRange);
        plane.setCruiseSpeed(cruiseSpeed);

        if (count >= capacity) {
            growArray();
        }
        fleetAirplanes[count] = plane;
        insert(); // use the insert function to maintain order
    }
    inFile.close();
    return count;
}

// Function: Fleet::printPlanes()
// Description: Prints the list of airplanes in the fleet
// Inputs: none
// Outputs: none
// Return: none
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

      // Print each plane's details
    for (int i = 0; i < count; ++i) {
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

// Function: Fleet::listByMake()
// Description: Lists airplanes by a specified make
// Inputs: none
// Outputs: none
// Return: none
void Fleet::listByMake() {
    char make[STR_SIZE];
    bool found = false;
    cout << "\nPlease type the make of the airplanes you would like "      
        "to list: ";
    cin.getline(make, STR_SIZE);
    cout << "\nThe airplanes in the list made by " << make <<
        " are:\n";
    
    // Header:
    cout << endl;
    cout << right << setw(4) << ""
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
                found = true;
        }
    }
    if (!found) {
        cout << "\nThere are no airplanes made by " << make << " in the database.\n";
    }
}

// Function: Fleet::addAPlane()
// Description: Adds a new airplane to the fleet with user input and inserts it in lexicographical order
// Inputs: none
// Outputs: none
// Return: bool - true if the plane is added successfully, false otherwise
bool Fleet::addAPlane() {
    char model[STR_SIZE];
    char make[STR_SIZE];
    double maxFuel = 0.0;
    int emptyWeight = 0;
    int engineHP = 0;
    int maxRange = 0;
    int cruiseSpeed = 0;

    cout << "\nWhat is the model (name) of the airplane? ";
    cin.getline(model, STR_SIZE);
    cout << "What is the make (manufacturer) of the airplane? ";
    cin.getline(make, STR_SIZE);

    cout << "What is the fuel capacity in gallons? ";
    while (!validateInput(maxFuel, 1.0, 150.0)) {
        cin.clear();
        // cin.ignore(100, '\n');
        cout << "OOPS! You must enter a decimal number for fuel capacity "
                "between 1.00 and 150.00. Please try again: ";
    }

    cout << "What is the empty weight? ";
    while (!validateInput(emptyWeight, 1, 3000)) {
        cin.clear();
        // cin.ignore(100, '\n');
        cout << "OOPS! The weight must be a whole number between 1 "
                "and 3000 pounds. Please try again: ";
    }

    cout << "What is the horsepower of the engine? ";
    while (!validateInput(engineHP, 1, 400)) {
        cin.clear();
        // cin.ignore(100, '\n');
        cout << "OOPS! The horsepower must be a whole number between 1"
                " and 400. Please try again: ";
    }

    cout << "What is the max range? ";
    while (!validateInput(maxRange, 1, 2000)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "OOPS! The range must be a whole number between 1 "
            "and 2000 nautical miles. Please try again: ";
    }

    cout << "What is the cruise speed? ";
    while (!validateInput(cruiseSpeed, 1, 250)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "OOPS! The cruise speed must be a whole number between 1 "
                "and 250 knots. Please try again: ";
    }

    Airplane airplane;
    airplane.setModel(model);
    airplane.setMake(make);
    airplane.setMaxFuel(maxFuel);
    airplane.setEmptyWeight(emptyWeight);
    airplane.setEngineHP(engineHP);
    airplane.setMaxRange(maxRange);
    airplane.setCruiseSpeed(cruiseSpeed);

    if (count >= capacity) {
        growArray();
    }
    fleetAirplanes[count] = airplane;
    insert();
    cout << "\n\n--> " << airplane.getModel() << " plane data was "
        "successfully inserted.\n";
    
    return true;
}

// Function: Fleet::removeAPlane()
// Description: Removes an airplane from the fleet at a specified index
// Inputs: none
// Outputs: none
// Return: bool - true if the plane is removed successfully, false otherwise
bool Fleet::removeAPlane() {
    int index = 0;
    cout << "\nWhich index would you like to remove (1 – " << count << ")? ";
    while (!validateInput(index, 1, count)) {
        cout << "Invalid Index. Please type an index between 1 and "
            << count << ": ";
    }
    cout << "\n--> " << fleetAirplanes[index - 1].getModel() << " at index " 
        << index << " has been removed.\n\n"; 

    // Shift elements to the left, starting from the index of the plane
    // that was removed
    for (int i = index - 1; i < count - 1; ++i) {
        fleetAirplanes[i] = fleetAirplanes[i + 1];
    }
    count--;
    return true;
}

// Function: Fleet::writePlanes()
// Description: Writes the list of airplanes to a file
// Inputs: none
// Outputs: none
// Return: none
void Fleet::writePlanes() {
    cout << "\n\n... file is writing to file output.txt...\n\n";
    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cout << "Failed to open file for writing." << endl;
        return;
    }
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
    cout << "\n\nDatabase file updated. Terminating Program.\n"
        << endl;
}

// Function: Fleet::search()
// Description: Searches for an airplane by model and displays its details if found
// Inputs: none
// Outputs: none
// Return: none
void Fleet::search() {
    char model[STR_SIZE];

    cout << "\nFor what airplane would you like to search? ";
    cin.getline(model, STR_SIZE);
    
    for (int i = 0; i < count; ++i) {
        if (strcmp(fleetAirplanes[i].getModel(), model) == 0) {
            cout << "\nInformation on the " << model << " is as follows:\n";
            cout << "Make: " << fleetAirplanes[i].getMake() << ", Fuel Capacity: " << 
                    fleetAirplanes[i].getMaxFuel() << ", Empty weight: " << 
                    fleetAirplanes[i].getEmptyWeight() << ", Horsepower: " << 
                    fleetAirplanes[i].getEngineHP() << ", Range: " << 
                    fleetAirplanes[i].getMaxRange() << ", Cruise speed: " << 
                    fleetAirplanes[i].getCruiseSpeed() << endl;
            return;
        }
    }
    cout << "\nThe " << model << " was not found in the database.\n";
}


// Function: openTheFile()
// Description: This function opens the file and loads fileName into an 
//              array in order to check if file opened or not. 
// Inputs:     fileName (char array): file name being opened
// Outputs:     success (boolean), true if file opens
// Return:     success (boolean), true if file opens
bool Fleet::openTheFile() {
    bool success = false;
    cin.getline(fileName, STR_SIZE);
    inFile.open(fileName);

    while(!inFile.is_open() && strcmp(fileName, "Q") != 0) {
        cout << "\n*** The file " << fileName << " was not found. Type 'Q' "
            "to quit, or try again now: ";
        cin.getline(fileName, STR_SIZE);
        inFile.open(fileName);
    }
    if(inFile.is_open()) {
        success = true;
    }
    return success;
}

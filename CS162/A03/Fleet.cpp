#include "Fleet.h"
#include <cstring>

// Function: Fleet::Fleet()
// Description: Fleet constructor
// Inputs: 
// Outputs: 
// Return: 
Fleet::Fleet() {
    count = 0;
    capacity = 3;
    fleetAirplanes = new Airplane[capacity];
    ready = openTheFile();
    if(ready)
        loadPlanes();
}

// Function: Fleet::Fleet()
// Description: Fleet Destructor
// Inputs: 
// Outputs: 
// Return: 
~Fleet::Fleet() {
    delete[] fleetAirplanes;
}

// Function: Fleet::growArray()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Fleet::growArray() {
    capacity *= 2;
    Airplane* newArray = new Airplane[capacity];
    for (int i = 0; i < count; ++i) {
        newArray[i] = fleetAirplanes[i];
    }
    delete[] fleetAirplanes;
    fleetAirplanes = newArray;
}

// Function: Fleet::loadPlanes()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
int Fleet::loadPlanes() {
    char model[STR_SIZE];
    char make[STR_SIZE];
    double maxFuel;
    int emptyWeight;
    int engineHP;
    int maxRange;
    int cruiseSpeed;

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
        fleetAirplanes[count++] = airplane;
    }

    inFile.close();
    return count;
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Fleet::printPlanes() {
    char separator[114];
    cout << endl 
        << left << setw(25) << "     Model" 
        << left << setw(15) << "Make" 
        << right << setw(13) << "Fuel Capacity" 
        << right << setw(15) << "Empty Weight" 
        << right << setw(15) << "Horsepower" 
        << right << setw(15) << "Range" 
        << right << setw(16) << "Cruise Speed\n" 
        << endl;

      // Print a seperator line
      for (int i = 0; i < 115; i++) {
        separator[i] = '-';
      }
      separator[113] = '\0'; // null-terminate the char array
      cout << separator << endl;

      // Print each plane's details
      for (int i = 0; i < count; i++) {
        cout << right << setw(2) << i + 1 << left << setw(3) << ". " 
          << left << setw(20) << fleetAirplanes[i].getModel() 
          << left << setw(18) << fleetAirplanes[i].getMake() 
          << right << setw(10) << fixed << setprecision(2) 
                               << fleetAirplanes[i].getMaxFuel() 
          << right << setw(15) << fleetAirplanes[i].getEmptyWeight() 
          << right << setw(15) << fleetAirplanes[i].getEngineHP() 
          << right << setw(15) << fleetAirplanes[i].getMaxFuel() 
          << right << setw(15) << fleetAirplanes[i].getCruiseSpeed() 
          << endl;
      }
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Fleet::listByMake() {
    char make[STR_SIZE];
    cout << "\nPlease type the make of the airplanes you would like to list: ";
    cin.ignore();
    cin.getline(make, STR_SIZE);
    bool found = false;
    cout << "\nThe airplanes in the list made by " << make << " are:\n";
    cout << "\n\n     Model              Make      Fuel Capacity   Empty Weight   Horsepower   Range     Cruise speed\n";
    cout << "-----------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; ++i) {
        if (strcmp(fleetAirplanes[i].getMake(), make) == 0) {
            cout << i + 1 << ".  " << fleetAirplanes[i].getModel() << "  "
                 << fleetAirplanes[i].getMake() << "  " << fleetAirplanes[i].getMaxFuel() << "  "
                 << fleetAirplanes[i].getEmptyWeight() << "  " << fleetAirplanes[i].getEngineHP() << "  "
                 << fleetAirplanes[i].getMaxRange() << "  " << fleetAirplanes[i].getCruiseSpeed() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\nThere are no airplanes made by " << make << " in the database.\n";
    }
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
bool Fleet::addAPlane() {
    char model[STR_SIZE];
    char make[STR_SIZE];
    double maxFuel;
    int emptyWeight;
    int engineHP;
    int maxRange;
    int cruiseSpeed;

    cout << "\nWhat is the model (name) of the airplane? ";
    cin.ignore();
    cin.getline(model, STR_SIZE);
    cout << "What is the make (manufacturer) of the airplane? ";
    cin.getline(make, STR_SIZE);

    cout << "What is the fuel capacity in gallons? ";
    while (!(cin >> maxFuel) || maxFuel < 1.0 || maxFuel > 150.0) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a decimal number for fuel capacity between 1.00 and 150.00.\n";
    }

    cout << "What is the empty weight? ";
    while (!(cin >> emptyWeight) || emptyWeight < 1 || emptyWeight > 3000) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "The weight must be a whole number between 1 and 3000 pounds.\n";
    }

    cout << "What is the horsepower of the engine? ";
    while (!(cin >> engineHP) || engineHP < 1 || engineHP > 400) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "The horsepower must be a whole number between 1 and 400.\n";
    }

    cout << "What is the range? ";
    while (!(cin >> maxRange) || maxRange < 1 || maxRange > 2000) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "The range must be a whole number between 1 and 2000 nautical miles.\n";
    }

    cout << "What is the cruise speed? ";
    while (!(cin >> cruiseSpeed) || cruiseSpeed < 1 || cruiseSpeed > 250) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "The cruise speed must be a whole number between 1 and 250 knots.\n";
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
    fleetAirplanes[count++] = airplane;
    return true;
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
bool Fleet::removeAPlane() {
    int index;
    cout << "\nWhich index would you like to remove (1 – " << count << ")? ";
    while (!(cin >> index) || index < 1 || index > count) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid Index. Please type an index between 1 and " << count << ": ";
    }

    for (int i = index - 1; i < count - 1; ++i) {
        fleetAirplanes[i] = fleetAirplanes[i + 1];
    }
    count--;
    return true;
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Fleet::writePlanes() {
    ofstream outFile(fileName);
    for (int i = 0; i < count; ++i) {
        outFile << fleetAirplanes[i].getModel() << ";" << fleetAirplanes[i].getMake() << ";"
                << fleetAirplanes[i].getMaxFuel() << ";" << fleetAirplanes[i].getEmptyWeight() << ";"
                << fleetAirplanes[i].getEngineHP() << ";" << fleetAirplanes[i].getMaxRange() << ";"
                << fleetAirplanes[i].getCruiseSpeed() << endl;
    }
    outFile.close();
}

// Function: openTheFile()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Fleet::searchAirplaneByModel(const char* model) const {
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
// Description: 
// Inputs: 
// Outputs: 
// Return: 
const char* Fleet::getFileName() const {
    return fileName;
}

// Function: openTheFile()
// Description: This function opens the file and loads fileName into an 
//              array in order to check if file opened or not. 
// Inputs: 
// Outputs: 
// Return: 
bool Fleet::openTheFile() {
    bool success = false;
    char fileName[STR_SIZE];
    cout << "Welcome to the airplane collection program!\n"
            "\nWhat is the name of the airplane collection file? ";
    cin.getline(fileName, STR_SIZE);
    inFile.open(fileName);

    while(!inFile.is_open() && strcmp(fileName, "Q") != 0) {
        cout << "\n*** The file " << fileName << " did not"
            " open. Type 'Q' to quit, or try again now: ";
        cin.getline(fileName, STR_SIZE);
        inFile.open(fileName);
    }
    if(inFile.is_open()) {
        success = true;
    }
    return success;
}

#include "airplane.h" 


// ------------------------- Function Definitions -------------------------- //
//Name:   openTheFile(ifstream & inFile)
//Desc:   This function
//input:  None
//output: prompt
//return: string name
bool openTheFile(ifstream & inFile) {
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

//Name:   loadPlanes()
//Desc:   This function loads planes into the array of structs.
//input:  Airplane planes[]: array of structs to load data into
//        ifstream &inFile: reads the plane data from an input file
//output: cout <message> to console for error (out of space)
//return: count (integer): adds the count of planes in the list
//        to the other count variable in main.cpp
int loadPlanes(Airplane planes[], ifstream & inFile) {
  Airplane newPlane; // local variable
  int count = 0;
  bool success = true;

  // getting user input model of plane "name"
  inFile.getline(newPlane.model, STR_SIZE, ';'); 
  
  while(!inFile.eof() && success) {
    inFile.getline(newPlane.make, STR_SIZE, ';'); // read the make of the plane
    inFile >> newPlane.maxFuel;
    inFile.ignore(); // ignore the semicolon
    inFile >> newPlane.emptyWeight;
    inFile.ignore();
    inFile >> newPlane.engineHP;
    inFile.ignore();
    inFile >> newPlane.maxRange;
    inFile.ignore();
    inFile >> newPlane.cruiseSpeed; 
    inFile.ignore();

    // insert the plane into the array
    success = insertPlane(planes, newPlane, count);

    // Check for room
    if(!inFile.eof() && !success) {
      cout << "Not all planes were loaded from the file, out of room! Please"
        " quit the program, and try again." << endl;
    }

    // Read the next plane's model
    inFile.getline(newPlane.model, STR_SIZE, ';');
  }
  
  return count;  
}

//Name:   addPlane(Airplane planes[], int & count)
//Desc:   This function adds an airplane by asking the user
//        in the console, and intaking model name, etc.
//input:  newPlane.model,.make, etc from the Struct
//output: Messages to console asking for each data type
//return: result (true or false)
bool addPlane(Airplane planes[], int &count, int &newIndex) {
  bool result = false;
  if (count < ARR_SIZE) {
    Airplane newPlane;
    
    // Get model name
    cout << "\nWhat is the model (name) of the airplane? ";
    cin.getline(newPlane.model, STR_SIZE);

    // Get make
    cout << "What is the make (manufacturer) of the airplane? ";
    cin.getline(newPlane.make, STR_SIZE);

    // Get fuel capacity with data validation
    cout << "What is the fuel capacity in gallons? ";
    while(!(cin >> newPlane.maxFuel) || 
      newPlane.maxFuel < 0 || 
      newPlane.maxFuel > 149) {
      cout << "Invalid input. Please enter a valid fuel capacity between "
        " 1.00 and 150.00: ";
      cin.clear();
      cin.ignore(LARGE_NUMBER, '\n');
    }
    cin.ignore(LARGE_NUMBER, '\n'); // Clear the newline char left

    // Get empty weight with validation using readInt
    readInt("What is the empty weight (in pounds)? ", newPlane.emptyWeight);
    while (newPlane.emptyWeight < 1 || newPlane.emptyWeight > 2999) {
        cout << "Invalid input. Please enter a valid weight between 1 and "
          "3000 pounds: ";
        readInt("", newPlane.emptyWeight);
    }

    // Get engine horsepower with validation using readInt
    readInt("What is the horsepower of the engine? ", newPlane.engineHP);
    while (newPlane.engineHP < 1 || newPlane.engineHP > 399) {
        cout << "Invalid input. Please enter a valid horsepower between 1 and "
          "400: ";
        readInt("", newPlane.engineHP);
    }

    // Get range with validation using readInt
    readInt("What is the range? ", newPlane.maxRange);
    while (newPlane.maxRange < 0 || newPlane.maxRange > 1999) {
        cout << "Invalid input. Please enter a valid range: ";
        readInt("", newPlane.maxRange);
    }

    // Get cruise speed with validation using readInt
    readInt("What is the cruise speed? ", newPlane.cruiseSpeed);
    while (newPlane.cruiseSpeed < 0) {
        cout << "Invalid input. Please enter a valid cruise speed: ";
        readInt("", newPlane.cruiseSpeed);
    }

    // Insert the new plane into the array
    result = insertPlane(planes, newPlane, count);

    // Identify the new index (For main.cpp switch case)
    if (result) {
      for (int i = 0; i < count; i++) {
        if(strcmp(planes[i].model, newPlane.model) == 0 &&
          strcmp(planes[i].make, newPlane.make) == 0) {
          newIndex = i;
          break;
        }
      }
    }
  }
  return result;
}

//Name:   insertPlane(Airplane planes[], Airplane newPlane, int & count)
//Desc:   
//input:  
//output: 
//return: 
bool insertPlane(Airplane planes[], Airplane newPlane, int & count) {
  bool result = false;
  int index = 0;

  if(count < ARR_SIZE) { // limit it 20
    // Part 1: empty array
    if(count == 0) {
      planes[0] = newPlane; // aggregate copy
    }
    // Part 2: maybe newPlane goes to the end, alphabetically
    else if(strcmp(planes[count - 1].model, newPlane.model) <= 0) {
      planes[count] = newPlane;
    }
    // Part 3: newPlane based on the model goes in the list. 
    //          - Shift the planes already in the array.
    else {
      while(index < count && strcmp(planes[index].model, newPlane.model) <= 0) {
        index++;
      }
      // Move the planes up to the next indices
      for(int i = count; i > index; i--) {
        planes[i] = planes[i - 1]; // moved one plane up by one index
      }
      // Now there is room for the newPlane to be placed at index
      planes[index] = newPlane;
    }
    count++;
    result = true;
  }
  return result;
}

//Name:   printPlanes()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
void printPlanes(Airplane planes[], int count) {
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
      << left << setw(20) << planes[i].model 
      << left << setw(18) << planes[i].make 
      << right << setw(10) << fixed << setprecision(2) << planes[i].maxFuel 
      << right << setw(15) << planes[i].emptyWeight 
      << right << setw(15) << planes[i].engineHP 
      << right << setw(15) << planes[i].maxRange 
      << right << setw(15) << planes[i].cruiseSpeed 
      << endl;
  }
}

//Name:   promptName()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
void writePlane(Airplane planes[], int count) {
  char fileName[STR_SIZE];
  ofstream outFile;
  cout << "\nWhat is the name of the file to write to? " << endl;
  cin.getline(fileName, STR_SIZE);
  outFile.open(fileName);

  for(int i = 0; i < count; i++) {
    outFile << planes[i].model << ';' << planes[i].make << ';' <<
      planes[i].maxFuel << ';' << planes[i].emptyWeight << ';' <<
      planes[i].emptyWeight << ';' << planes[i].engineHP << ';' <<
      planes[i].maxRange << ';' << planes[i].cruiseSpeed << endl;
  }
  outFile.close();
}

//Name:   promptName()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
void readInt(const char prompt[], int &result) {
  cout << prompt;
  while (!(cin >> result)) {
    cout << "Invalid input. Please enter an interger: ";
    cin.clear();
    cin.ignore(100, '\n');
  }
cin.ignore(100, '\n');
}

//Name:   promptName()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
void searchByModel(Airplane planes[], int count) {
  char searchModel[MAX_CHAR];
  cout << "\nFor what airplane would you like to search (by model name)? ";
  cin.get(searchModel, MAX_CHAR, '\n');

  // Convert searchModel to uppercase for comparison
  convertCase(searchModel);

  bool found = false;

  for (int i = 0; i < count; i++) {
    char planeModelUpper[MAX_CHAR];
    strcpy(planeModelUpper, planes[i].model);
  
    // Convert plane model to uppercase for comparison
    convertCase(planeModelUpper);
    
    // Check if searchModel is in planeModelUpper
    if (strstr(planeModelUpper, searchModel) != NULL) {
      found = true;
      cout << "\nInformation on the " << planes[i].model << " is as follows\n";
      cout << "\nModel: " << planes[i].model << ", "
        << "Make: " << planes[i].make << ", "
        << "Fuel Capacity: " << fixed << setprecision(2) << planes[i].maxFuel 
        << ", "
        << "Empty Weight: " << planes[i].emptyWeight << ", "
        << "Horsepower: " << planes[i].engineHP << ", "
        << "Range: " << planes[i].maxRange << ", "
        << "Cruise speed: " << planes[i].cruiseSpeed
        << endl;
      break;
        }
      }
    if (!found) {
      cout << "\nThe airplane with model name " << searchModel << " was not "
        "found in the database." << endl;
    }
  }

//Name:   listByMake()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
void listByMake(Airplane planes[], int count) {
  char make[MAX_CHAR];

  cout << "\nPlease type the make of the airplanes you would like to list: ";
  cin.getline(make, MAX_CHAR);

  // Convert make to uppercase for comparison
  convertCase(make);

  bool found = false;
  cout << "\nThe airplanes in the list made by " << make << " are:\n"
       << left << setw(20) << "\n\n     Model" 
       << left << setw(15) << "Make" 
       << right << setw(15) << "Fuel Capacity" 
       << right << setw(15) << "Empty Weight" 
       << right << setw(15) << "Horsepower" 
       << right << setw(15) << "Range" 
       << right << setw(19) << "Cruise speed\n" 
       << endl;

  // Print a separator line
  for (int i = 0; i < 113; i++) cout << '-';
  cout << endl;

  int listCount = 0;
  for (int i = 0; i < count; i++) {
    char planeMakeUpper[MAX_CHAR];
    strcpy(planeMakeUpper, planes[i].make);
    // Convert plane make to uppercase for comparison
    convertCase(planeMakeUpper);

    if (strcmp(planeMakeUpper, make) == 0) {
      found = true;
      listCount++;
      cout << right << setw(2) << listCount << " . " 
           << left << setw(20) << planes[i].model 
           << left << setw(18) << planes[i].make 
           << right << setw(10) << fixed << setprecision(2) << planes[i].maxFuel 
           << right << setw(15) << planes[i].emptyWeight 
           << right << setw(15) << planes[i].engineHP 
           << right << setw(15) << planes[i].maxRange 
           << right << setw(15) << planes[i].cruiseSpeed 
           << endl;
    }
  }

  if (!found) {
    cout << "\nThere are no airplanes made by " << make << " in the database.\n";
  }
}

//Name:   convertCase(char tempStr[]
//Desc:   updates letter to uppercase via array
//input:  char for making into uppercase letter
//output: tempStr[i]
//return: string name
void convertCase(char tempStr[]) {
  for (size_t i = 0; i < strlen(tempStr); i++) {
    tempStr[i] = toupper(tempStr[i]);
  }
}
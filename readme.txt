// INSTRUCTIONS: //

After completing this code, you will be able to: 
Write code using classes and objects that use dynamic memory.
Create and use dynamic c-strings and dynamic arrays.
Implement the default constructor, copy constructor, destructor, and overloaded assignment operator for a user-defined class.
Avoid memory errors such as segmentation faults, memory leaks and dangling pointers.
Implement and use accessors and mutators for a class.
Organize source code in multiple header and implementation files.
Read from input data files.


CS162 Assignment 3: Dynamic Memory	Airplane Information Database

For our airplane database program, we are going to take steps to make it more memory efficient. Consider the Airplane class from assignment 2 and the make and model c-string members. The constant STR_SIZE is at least 100, so that make and model can contain a relatively large amount of characters, just in case. However, one of the model names is 152, which is only 4 characters (3 characters and 1 null terminator). So, allocating 100 characters for such a small name is wasting 96 bytes. There is also a potential waste of memory – and a limitation - when creating an array of Airplanes in the Fleet class. The constant I chose for the size of the array is 30. If we have a list of only 10 airplanes, then we will have created memory for an extra 20 airplanes that won’t be used. Conversely if we have a list of 40 airplanes, then we won’t have enough room to load the last 10 from the file into memory.
To remedy this situation, we will be allocating memory for c-strings and the array of Airplanes dynamically. That means that we need char pointers for the c-strings and an Airplane pointer for the Airplane array. For the c-strings, the code will count the number of characters necessary for the make and model and then only allocate that many characters, plus one for the null-terminator. To store the Airplanes, the code will allocate a small Airplane array and then “grow” if more room is needed. See below for changes to the classes. The Airplane class now has char pointers for make and model, and the Fleet class has an Airplane pointer for a dynamic array.
Because the two classes (Airplane and Fleet) will have dynamic members, this assignment requires the “rule of 3” functions: the destructor (so there won’t be memory leaks), the copy constructor, and the overloaded assignment operator (so there won’t be shallow copies). There is also a new function called growArray() in the Fleet class, so that new memory can be allocated if the array of Airplanes becomes full.
Continue to use the same format from assignment 1 for loading from a file, presenting a menu driven loop, error checking etc. Load the input file at the start of the program, insert the airplanes in sorted order by model name, close the input file and only deal with data in memory, and then write the data back to the output file at program termination.
Requirements:
Continue to implement the encapsulation and data hiding requirements from assignment 2. The Fleet class must encapsulate the array of Airplane class objects, and the array must be private. All member variables (properties) of the Airplane class must be encapsulated and private inside of the Airplane class. These include make, model, maximum fuel, empty weight, engine horsepower, and cruise speed. All functions that manipulate data for the Airplane class must be encapsulated inside of the Airplane class, commonly referred to as getters and setters.
You must implement dynamic memory for make and model using a char pointer, and the array of Airplanes in the Fleet class must be dynamic. For the Airplane class, you must implement the destructor, copy constructor, and overloaded assignment operator. You must implement the destructor and the growArray() function for the Fleet class. You may implement the copy constructor and the assignment operator for Fleet or set them to delete. See below in the Strategies section for more details.
You must not use <string> or any container classes such as <vector>. Do not use the <sstream> class, as that class uses string objects.
You must use functions and have multiple code files and header files.
You must follow the coding style listed in the C++ style guidelines.
Use valgrind or some other memory leak checker to make sure that your program does not have any memory leaks. See the strategies section below for details.
Tasks (Same as Assignment 2): 
• Complete the zylabs from chapters 19 and 20. 19.16, Car value (Pointer Objects) , 20.10, List of Integers and 20.11, Video Class. For chapters 19 and 20, please complete the zylabs with a score of 100%, 70% of the challenge activities, and 80% of the participation activities.
• Open the Algorithm Design Document or the UML based Algorithm Design Document, make a copy, and follow the steps to create your algorithm. Complete the algorithm design document to receive a grade.
• If you are tired of creating pseudocode and would like a graphical option, you can use this alternative UML based Algorithm Design Document. It has an example of a UML graph instead of pseudocode.
• Load the data from the database file in sorted order by model. You may not use a user-defined sorting function or sort function from a library - this means that each airplane must be inserted into the array in sorted order.
• Load the data when the program is started and write the data back to the file at program termination. Only load from the file at the start of the program. Only write to the file at program termination.
• After the file is loaded, the program will enter a user-controlled loop. Inside of the loop, the program will ask the user what they want to do.
• The rest of the tasks are split into 3 different versions based on the type of grade you want, just like assignment 1. There are 3 versions for this assignment, and each version has the minimum requirements for a particular grade – A, B or C. The B version builds on the requirements of the C version, and the A version builds on the requirements of the A version. Here are the requirements for each version:
Version C:
List all the airplanes, one per line, using line numbers.
Add a new airplane to the database in sorted order.
Quit.

Version B:
List all the airplanes, one per line, using line numbers.
Add a new airplane to the database in sorted order.
Remove an airplane by index (new for B version). 
Quit.

Version A:
List all the airplanes, one per line, using line numbers.
Add a new airplane to the database in sorted order.
Remove an airplane by index.
Search for an airplane by model (new for A version).
List all airplanes by make (new for A version).
Quit.

NOTE: There are different error checking requirements when adding a new airplane or removing an airplane for each one of the grade versions above:
C version – check to make sure all number values are positive.
B version – check to make sure all number values are positive and check for proper index to remove (not out of bounds). Also:
Make sure the maximum fuel is less than 150 gallons.
Make sure the empty weight is less than 3000 pounds.
Make sure the engine horsepower is less than 400.
Make sure the range is less than 2000.
Make sure the maximum cruise is less than 250 knots.
A version – All the error checks for version B and check for input failure (don’t allow the program to crash or go into an infinite loop when letters are typed for input to numbers).

The file format lists all the information for one airplane on one line, and includes:
model (name)
make (manufacturer)
fuel capacity
empty weight
engine horsepower
range (nautical miles)
cruise speed (knots)



Make sure that there is a newline (return) at the end of every line, including the last line. See the assignment 1 document for handling the newline at the end of the file.
Along with this document there will be an example text file that contains the following airplanes in this format:
360;Lancair;43.00;1090;180;990;208
Skyhawk 172;Cessna;53.00;1663;180;515;123
K35 Bonanza;Beechcraft;70.00;1832;250;534;168
RangeMaster H;Navion;40.00;1945;330;1381;160 
Tomahawk;Piper;30.00;1128;112;383;107
M20R Ovation;Mooney;89.00;2205;280;969;189
C23 Sundowner;Beechcraft;57.00;1494;180;564;115
RV-12;Vans Aircraft;20.00;750;100;451;119
TB-21 GT Trinidad;Socata;88.00;1911;250;1025;168
RV-9;Vans Aircraft;36.00;1057;160;616;163
152;Cessna;26.00;1081;110;414;106
Tiger;Grumman;51.00;1360;180;529;139
Super Cub;Piper;36.00;845;125;449;96

The sample run / sample output is the same as the first assignment, so it has been removed from this version. Open the first assignment document to see the sample output.
Programming Requirements
Just like assignment 2, you must have a main.cpp file, a plane.h and plane.cpp file, and a fleet.h and fleet.cpp file. All member function definitions must be part of the class implementation file for both classes. You may also have tools.h and tools.cpp or functions.h and functions.cpp, but these files should only contain code for stand-alone functions (such as welcome()) which are not part of a class. You can also add a main.h file if you want.
Just like assignment 1 and 2, Don’t use the string library or any of the STL containers such as vectors.
Encapsulate your array of Airplane objects in the Fleet class. Do not use any global variables.
Unlike assignment 2, you won’t be checking the size of the Airplane array against a constant. This time you will be checking against a member variable, perhaps called capacity, that will be set in the constructor. If the size of the array is greater than or equal to capacity, then grow the array by calling the growArray() function.
All of the remaining requirements from assignment 2 are also required for this assignment. Namely:
make sure the file is open, ifstream.is_open()
Check for negative values and bad data, depending on the grade version (C, B, or A).
Use the file guards  in your header files - #ifndef, #define and #endif
Use #include to include the fleet.h and plane.h header files where they are needed.
Use the Airplane class to represent airplane data and the Fleet class to represent a collection.
Programming Strategies
Now that we have dynamic c-strings and a dynamic array, the constructor for Airplane will be responsible for allocating dynamic memory, or for setting the char pointers to nullptr. You can either allocate memory for something like “none,” or you can just set the pointers equal to nullptr.
The constructor for Fleet will need to allocate an array for fleetAirplanes. Set the array capacity small, such as 3, so that it will be easy to test your growArray() function:
count = 0;
capacity = 3;
fleetAirplanes = new Airplane[capacity];
We will need the “rule of 3” as described in the Zybook for the Airplane class. The rule of 3 refers to the 3 member functions (at a minimum) that we must implement. The 3 functions are: the assignment operator (also called the copy assignment operator), the copy constructor, and the destructor. Those 3 functions are provided by the compiler automatically if we don’t provide code for them. However, we can’t rely on the versions of the copy constructor and assignment operator that are provided automatically anymore, because our classes have dynamically allocated properties. If we don’t provide the overloaded code for them, then we will have a serious problem called “shallow copy.” This is because our objects contain dynamic variables, which are simply pointers. Let’s look at examples of how these functions are invoked:
Airplane a1, a2;
a1 = a2;         // invoke the assignment operator.
Airplane a3(a2); // invoke the copy constructor. a3 will be a copy of a2.
Suppose the model of a2 is set to the string “Skyhawk 172”. The auto-generated copy constructor and assignment operator will make a copy of the pointer for model. Therefore a1.model and a2.model will be pointing at the same memory location. In effect, they will be sharing the memory for model, and so if the model for a1 is modified, it will modify the model for a2, or more likely, create errors for a2. To fix this problem, we need a deep copy. So, in the code for the overloaded copy constructor and assignment operator, we will first find out how many characters are in a2.model, allocate just the right amount of characters for a1.model, and then use: strcpy(a1.model, a2.model);
We will need a similar strategy for the setters for the c-strings. Suppose the user changes the model to “TB-21 GT Trinidad.” This is longer than the string “Skyhawk 172,” so we can’t just overwrite the memory that contains “Skyhawk 172,” because we haven’t allocated enough memory and will have buffer overflow. So instead, we will have to delete the currently assigned memory and then allocate new memory for the new model name.
We need this same strategy for the growArray() function. Once we run out of room in the fleetAirplanes array, we will need to allocate a larger array. Once we create the new array, we will copy each Airplane from the old array to the new array, delete the old array, and then set fleetAirplanes to the new array.
The destructor is invoked when an object is no longer accessible, which is when an automatic object (on the stack) goes out of scope or when a dynamically allocated object (on the heap) is deleted. The only thing the destructors will need to do is call delete or delete[] for all of the dynamically allocated properties.
If all dynamic memory is deleted before program termination, then there can’t be any memory leaks, but we need to make sure. Memory leaks are notoriously hard to find. So, we can use a tool called valgrind. Valgrind is a program on the Linux server that checks your program for memory leaks and other memory errors. Here is a sample run: valgrind --leak-check=full ./programName
The textbox on the left shows that valgrind found some memory leaks, and the textbox on the right shows no memory leaks:
You may notice that there are prototypes for the copy constructor and overloaded assignment operator in the Fleet class, but both are set to delete. If you wish to implement them, then remove the equal sign and delete keyword from the prototype. We will only need one Fleet object, so we won’t need a copy, so we won’t write the code for those two functions. Remember though that if we don’t provide these two functions, then the compiler will, so if the client tries to make a copy of a Fleet object, it will produce a shallow copy. To stop the client from making a copy, we can set those two functions to delete, and they will get a compilation error.

CODE THAT MUST BE USED AND MUST STAY UNEDITED IN THIS PROGRAM:
class Fleet {
  private:
    char fileName[STR_SIZE];
    ifstream inFile;
    int count;
    int capacity;
    Airplane * fleetAirplanes;
    bool insert(); // private method.

  public:
    Fleet(); // Default constructor.
    Fleet(const Fleet &) = delete;
    Fleet & operator=(const Fleet &) = delete;
    int loadPlanes();
    void printPlanes();
    void listByMake();
    bool addAPlane();
    bool removeAPlane();
    void writePlanes();
    void growArray();
};

class Airplane {
private:  // Properties are private.
    char * make;
    char * model;
    double maxFuel;   // in gallons
    int emptyWeight;  // in pounds
    int engineHP;     // horse power
    int maxRange;  // nautical miles
    int cruiseSpeed; // knots
public:
    Airplane(); // default constructor.
    Airplane(const Airplane &);
    ~Airplane();
    Airplane & operator=(const Airplane &);
    // Getters
    const char * getMake();
    const char * getModel();
    double getMaxFuel();
    int getEmptyWeight();
    int getMaxRange();
    int getCruiseSpeed();
    // Setters
    void setMake(const char *);
    void setModel(const char *);
    void setMaxFuel(double);
    void setEmptyWeight(int);
    void setMaxRange(int);
    void setCruiseSpeed(int);
};




// --------- END INSTRUCTIONS ----- //


// --------- planes.txt ----------- //
360;Lancair;43.00;1090;180;990;208
Skyhawk 172;Cessna;53.00;1663;180;515;123
K35 Bonanza;Beechcraft;70.00;1832;250;534;168
RangeMaster H;Navion;40.00;1945;330;1381;160
Tomahawk;Piper;30.00;1128;112;383;107
M20R Ovation;Mooney;89.00;2205;280;969;189
C23 Sundowner;Beechcraft;57.00;1494;180;564;115
RV-12;Vans Aircraft;20.00;750;100;451;119
TB-21 GT Trinidad;Socata;88.00;1911;250;1025;168
RV-9;Vans Aircraft;36.00;1057;160;616;163
152;Cessna;26.00;1081;110;414;106
Tiger;Grumman;51.00;1360;180;529;139
Super Cub;Piper;36.00;845;125;449;96

// ---------- tools.h ------------- //
#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <climits>

#include "Fleet.h"

using namespace std;

const int STR_SIZE = 100;
const int ARR_SIZE = 100;

void loadFleet(Fleet& fleet, const char* filename);
void saveFleet(const Fleet& fleet, const char* filename);
void displayMenu();
bool validateInput(const string& input, float& value);
bool validateInput(const string& input, int& value);

#endif // TOOLS_H


// ---------- tools.cpp ----------- //
#include "tools.h" 

using namespace std;

//Name:   displayMenu
//Desc:   This function displays the main menu for the program
//input:  None
//output: prompt
//return: None
void displayMenu() {
    cout << "What would you like to do? (A)dd a plane, (L)ist all planes, "
         << "(R)emove a plane by index, (S)earch for a plane, List all planes by "
         << "(M)ake, or (Q)uit? ";
}

//Name:   validateInput
//Desc:   This function validates if a string input can be converted to a float
//input:  const string& input, float& value
//output: None
//return: bool
bool validateInput(const string& input, float& value) {
    try {
        size_t pos;
        value = stof(input, &pos);
        return pos == input.length();
    } catch (...) {
        return false;
    }
}

//Name:   validateInput
//Desc:   This function validates if a string input can be converted to an int
//input:  const string& input, int& value
//output: None
//return: bool
bool validateInput(const string& input, int& value) {
    try {
        size_t pos;
        value = stoi(input, &pos);
        return pos == input.length();
    } catch (...) {
        return false;
    }
}

// --------- Airplane.h ----------- //
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "tools.h"

#include <iostream>
#include <cstring>

using namespace std;

class Airplane {
private:
    char *model;
    char *make;
    int fuelCapacity;
    float emptyWeight;
    int horsepower;
    int range;
    int cruiseSpeed;

    void setString(char*& dest, const char* src);

public:
    Airplane();
    Airplane(const char* model, const char* make, int fuelCapacity, 
        float emptyWeight, int horsepower, int range, int cruiseSpeed);
    Airplane(const Airplane& other); // Copy constructor
    Airplane& operator=(const Airplane& other); // Copy assignment operator
    ~Airplane(); // Destructor

    void setModel(const char* model);
    void setMake(const char* make);
    void setFuelCapacity(int fuelCapacity);
    void setEmptyWeight(float emptyWeight);
    void setHorsepower(int horsepower);
    void setRange(int range);
    void setCruiseSpeed(int cruiseSpeed);

    const char* getModel() const;
    const char* getMake() const;
    int getFuelCapacity() const;
    float getEmptyWeight() const;
    int getHorsepower() const;
    int getRange() const;
    int getCruiseSpeed() const;

    friend ostream& operator<<(ostream& os, const Airplane& airplane);
};

#endif // AIRPLANE_H


// --------- Airplane.cpp --------- //
#include "Airplane.h"

//Name:   setString
//Desc:   This helper function sets a char pointer to a new string value
//input:  char*& dest, const char* src
//output: None
//return: None
void Airplane::setString(char*& dest, const char* src) {
    if (dest) {
        delete[] dest;
    }
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

// Default constructor
//Name:   Airplane
//Desc:   Default constructor initializing members to default values
//input:  None
//output: None
//return: None
Airplane::Airplane() : model(nullptr), make(nullptr), fuelCapacity(0), emptyWeight(0), horsepower(0), range(0), cruiseSpeed(0) {}

// Parameterized constructor
//Name:   Airplane
//Desc:   Constructor initializing members to specified values
//input:  const char* model, const char* make, int fuelCapacity, float emptyWeight, int horsepower, int range, int cruiseSpeed
//output: None
//return: None
Airplane::Airplane(const char* model, const char* make, int fuelCapacity, float emptyWeight, int horsepower, int range, int cruiseSpeed) {
    setString(this->model, model);
    setString(this->make, make);
    this->fuelCapacity = fuelCapacity;
    this->emptyWeight = emptyWeight;
    this->horsepower = horsepower;
    this->range = range;
    this->cruiseSpeed = cruiseSpeed;
}

// Copy constructor
//Name:   Airplane
//Desc:   Copy constructor initializing members to values from another Airplane object
//input:  const Airplane& other
//output: None
//return: None
Airplane::Airplane(const Airplane& other) {
    setString(model, other.model);
    setString(make, other.make);
    fuelCapacity = other.fuelCapacity;
    emptyWeight = other.emptyWeight;
    horsepower = other.horsepower;
    range = other.range;
    cruiseSpeed = other.cruiseSpeed;
}

// Copy assignment operator
//Name:   operator=
//Desc:   Copy assignment operator assigning values from another Airplane object
//input:  const Airplane& other
//output: None
//return: Airplane&
Airplane& Airplane::operator=(const Airplane& other) {
    if (this == &other) return *this;
    setString(model, other.model);
    setString(make, other.make);
    fuelCapacity = other.fuelCapacity;
    emptyWeight = other.emptyWeight;
    horsepower = other.horsepower;
    range = other.range;
    cruiseSpeed = other.cruiseSpeed;
    return *this;
}

// Destructor
//Name:   ~Airplane
//Desc:   Destructor freeing allocated memory
//input:  None
//output: None
//return: None
Airplane::~Airplane() {
    delete[] model;
    delete[] make;
}

// Setter methods
//Name:   setModel
//Desc:   Sets the model of the airplane
//input:  const char* model
//output: None
//return: None
void Airplane::setModel(const char* model) { setString(this->model, model); }

//Name:   setMake
//Desc:   Sets the make of the airplane
//input:  const char* make
//output: None
//return: None
void Airplane::setMake(const char* make) { setString(this->make, make); }

//Name:   setFuelCapacity
//Desc:   Sets the fuel capacity of the airplane
//input:  int fuelCapacity
//output: None
//return: None
void Airplane::setFuelCapacity(int fuelCapacity) { this->fuelCapacity = fuelCapacity; }

//Name:   setEmptyWeight
//Desc:   Sets the empty weight of the airplane
//input:  float emptyWeight
//output: None
//return: None
void Airplane::setEmptyWeight(float emptyWeight) { this->emptyWeight = emptyWeight; }

//Name:   setHorsepower
//Desc:   Sets the horsepower of the airplane
//input:  int horsepower
//output: None
//return: None
void Airplane::setHorsepower(int horsepower) { this->horsepower = horsepower; }

//Name:   setRange
//Desc:   Sets the range of the airplane
//input:  int range
//output: None
//return: None
void Airplane::setRange(int range) { this->range = range; }

//Name:   setCruiseSpeed
//Desc:   Sets the cruise speed of the airplane
//input:  int cruiseSpeed
//output: None
//return: None
void Airplane::setCruiseSpeed(int cruiseSpeed) { this->cruiseSpeed = cruiseSpeed; }

// Getter methods
//Name:   getModel
//Desc:   Gets the model of the airplane
//input:  None
//output: None
//return: const char*
const char* Airplane::getModel() const { return model; }

//Name:   getMake
//Desc:   Gets the make of the airplane
//input:  None
//output: None
//return: const char*
const char* Airplane::getMake() const { return make; }

//Name:   getFuelCapacity
//Desc:   Gets the fuel capacity of the airplane
//input:  None
//output: None
//return: int
int Airplane::getFuelCapacity() const { return fuelCapacity; }

//Name:   getEmptyWeight
//Desc:   Gets the empty weight of the airplane
//input:  None
//output: None
//return: float
float Airplane::getEmptyWeight() const { return emptyWeight; }

//Name:   getHorsepower
//Desc:   Gets the horsepower of the airplane
//input:  None
//output: None
//return: int
int Airplane::getHorsepower() const { return horsepower; }

//Name:   getRange
//Desc:   Gets the range of the airplane
//input:  None
//output: None
//return: int
int Airplane::getRange() const { return range; }

//Name:   getCruiseSpeed
//Desc:   Gets the cruise speed of the airplane
//input:  None
//output: None
//return: int
int Airplane::getCruiseSpeed() const { return cruiseSpeed; }

// Output operator
//Name:   operator<<
//Desc:   Outputs the details of the airplane
//input:  ostream& os, const Airplane& airplane
//output: None
//return: ostream&
ostream& operator<<(ostream& os, const Airplane& airplane) {
    os << airplane.model << "\t\t" << airplane.make << "\t" << airplane.fuelCapacity << "\t"
       << airplane.emptyWeight << "\t" << airplane.horsepower << "\t" << airplane.range << "\t"
       << airplane.cruiseSpeed;
    return os;
}


// --------- Fleet.h -------------- //
#ifndef FLEET_H
#define FLEET_H

#include "tools.h"
#include "Airplane.h"

#include <fstream>

using namespace std;

class Fleet {
private:
    int count;
    char fileName[STR_SIZE];
    ifstream inFile;
    Airplane* airplanes;
    int size;
    int capacity;

    void growArray();

public:
    Fleet();
    ~Fleet();
    void addAirplane(const Airplane& airplane);
    void removeAirplane(int index);
    Airplane getAirplane(int index) const;
    int getSize() const;
    void listAirplanes() const;
    void searchAirplaneByModel(const char* model) const;
    void listAirplanesByMake(const char* make) const;
    void loadFleet(Fleet& fleet, const char* filename);
    void saveFleet(const Fleet& fleet, const char* filename);
    bool openTheFile();
};

#endif // FLEET_H


// --------- Fleet.cpp ------------ //
#include "tools.h"
#include "Fleet.h"

#include <iostream>

using namespace std;


// Default constructor
//Name:   Fleet
//Desc:   Default constructor initializing size and capacity
//input:  None
//output: None
//return: None
Fleet::Fleet() : size(0), capacity(3) {
    airplanes = new Airplane[capacity];
}

// Destructor
//Name:   ~Fleet
//Desc:   Destructor freeing allocated memory
//input:  None
//output: None
//return: None
Fleet::~Fleet() {
    delete[] airplanes;
}

//Name:   growArray
//Desc:   Grows the internal array to accommodate more airplanes
//input:  None
//output: None
//return: None
void Fleet::growArray() {
    capacity *= 2;
    Airplane* newArray = new Airplane[capacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = airplanes[i];
    }
    delete[] airplanes;
    airplanes = newArray;
}

//Name:   addAirplane
//Desc:   Adds a new airplane to the fleet
//input:  const Airplane& airplane
//output: None
//return: None
void Fleet::addAirplane(const Airplane& airplane) {
    if (size >= capacity) {
        growArray();
    }
    airplanes[size++] = airplane;
}

//Name:   removeAirplane
//Desc:   Removes an airplane from the fleet by index
//input:  int index
//output: None
//return: None
void Fleet::removeAirplane(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        airplanes[i] = airplanes[i + 1];
    }
    --size;
}

//Name:   getAirplane
//Desc:   Gets an airplane by index
//input:  int index
//output: None
//return: Airplane
Airplane Fleet::getAirplane(int index) const {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        exit(1);
    }
    return airplanes[index];
}

//Name:   getSize
//Desc:   Gets the size of the fleet
//input:  None
//output: None
//return: int
int Fleet::getSize() const {
    return size;
}

//Name:   listAirplanes
//Desc:   Lists all airplanes in the fleet
//input:  None
//output: None
//return: None
void Fleet::listAirplanes() const {
    cout << "\n     Model              Make      Fuel Capacity   Empty Weight   Horsepower   Range     Cruise speed\n";
    cout << "-----------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ".  " << airplanes[i] << "\n";
    }
}

//Name:   searchAirplaneByModel
//Desc:   Searches for an airplane by model
//input:  const char* model
//output: None
//return: None
void Fleet::searchAirplaneByModel(const char* model) const {
    for (int i = 0; i < size; ++i) {
        if (strcmp(airplanes[i].getModel(), model) == 0) {
            cout << "Information on the " << model << " is as follows:\n";
            cout << "Make: " << airplanes[i].getMake() << ", Fuel Capacity: " << airplanes[i].getFuelCapacity()
                 << ", Empty weight: " << airplanes[i].getEmptyWeight() << ", Horsepower: " << airplanes[i].getHorsepower()
                 << ", Range: " << airplanes[i].getRange() << ", Cruise speed: " << airplanes[i].getCruiseSpeed() << "\n";
            return;
        }
    }
    cout << "The " << model << " was not found in the database.\n";
}

//Name:   listAirplanesByMake
//Desc:   Lists all airplanes by make
//input:  const char* make
//output: None
//return: None
void Fleet::listAirplanesByMake(const char* make) const {
    bool found = false;
    cout << "The airplanes in the list made by " << make << " are:\n";
    cout << "\n     Model              Make      Fuel Capacity   Empty Weight   Horsepower   Range     Cruise speed\n";
    cout << "-----------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        if (strcmp(airplanes[i].getMake(), make) == 0) {
            cout << i + 1 << ".  " << airplanes[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "There are no airplanes made by " << make << " in the database.\n";
    }
}

//Name:   saveFleet
//Desc:   This function saves the current fleet of airplanes to a file
//input:  const Fleet& fleet, const char* filename
//output: None
//return: None
void saveFleet(const Fleet& fleet, const char* filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Could not open file " << filename << endl;
        return;
    }

    for (int i = 0; i < fleet.getSize(); ++i) {
        Airplane ap = fleet.getAirplane(i);
        file << ap.getModel() << ";" << ap.getMake() << ";" << ap.getFuelCapacity() << ";" << ap.getEmptyWeight() << ";"
             << ap.getHorsepower() << ";" << ap.getRange() << ";" << ap.getCruiseSpeed() << "\n";
    }

    file.close();
}

//Name:   loadFleet
//Desc:   This function reads airplane data from a file and loads it into 
//        the fleet
//input:  Fleet& fleet, const char* filename
//output: None
//return: None
void loadFleet(Fleet& fleet, const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Could not open file " << filename << endl;
        return;
    }

    char model[100], make[100];
    float fuelCapacity, emptyWeight;
    int horsepower, range, cruiseSpeed;

    while (file.getline(model, 100, ';')) {
        file.getline(make, 100, ';');
        file >> fuelCapacity;
        file.ignore();
        file >> emptyWeight;
        file.ignore();
        file >> horsepower;
        file.ignore();
        file >> range;
        file.ignore();
        file >> cruiseSpeed;
        file.ignore();
        fleet.addAirplane(Airplane(model, make, fuelCapacity, emptyWeight, horsepower, range, cruiseSpeed));
    }

    file.close();
}

//Name:   openTheFile()
//Desc:   This function
//input:  None
//output: prompt
//return: string name
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

// --------- main.cpp ------------- //
/******************************************************************************
# Author:           Gina Frguson
# Assignment:       CS162 Assignment 3
# Date:             (fill in)
# Description:      This program manages an airplane collection, allowing users
#                   to add, list, search, and remove airplanes from the collection.
# Input:            String inputs for filenames, model names, and makes; numeric
#                   inputs for fuel capacity, empty weight, horsepower, range,
#                   and cruise speed.
# Output:           Displays the list of airplanes, prompts for input, shows
#                   search results, and confirms additions/removals.
# Sources:          Assignment 3 specifications, Lab 1 specifications.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// You don't need to include these three lines in your program!

#include "tools.h"
#include "Airplane.h"
#include "Fleet.h"

using namespace std;

int main() {
    Fleet fleet;
    string filename;

    cout << "Welcome to the airplane collection program."
            "What is the name of the airplane collection file? ";
    if(!myFleet.openTheFile()) {
        cout << "Quitting program since the file didn't open." << endl;
    }
    else { 
        myFleet.loadPlanes();

        char option;
        do }

    char choice;
    do {
        displayMenu();
        cin >> choice;
        choice = toupper(choice);

        switch (choice) {
            case 'L':
                fleet.listAirplanes();
                break;
            case 'A': {
                char model[100], make[100];
                float fuelCapacity, emptyWeight;
                int horsepower, range, cruiseSpeed;

                cout << "What is the model (name) of the airplane? ";
                cin.ignore();
                cin.getline(model, 100);
                cout << "What is the make (manufacturer) of the airplane? ";
                cin.getline(make, 100);

                string input;
                cout << "What is the fuel capacity in gallons? ";
                while (true) {
                    cin >> input;
                    if (validateInput(input, fuelCapacity) && fuelCapacity >= 
                        1.00 && fuelCapacity <= 150.00) {
                        break;
                    } else {
                        cout << "Please enter a decimal number for fuel "
                                "capacity between 1.00 and 150.00.\n";
                    }
                }

                cout << "What is the empty weight? ";
                while (true) {
                    cin >> input;
                    if (validateInput(input, emptyWeight) && emptyWeight >= 1 && 
                        emptyWeight <= 3000) {
                        break;
                    } else {
                        cout << "The weight must be a whole number between "
                                "1 and 3000 pounds.\n";
                    }
                }

                cout << "What is the horsepower of the engine? ";
                while (true) {
                    cin >> input;
                    if (validateInput(input, horsepower) && horsepower >= 1 && 
                        horsepower <= 400) {
                        break;
                    } else {
                        cout << "The horsepower must be a whole number between 1 and 400.\n";
                    }
                }

                cout << "What is the range? ";
                cin >> range;

                cout << "What is the cruise speed? ";
                cin >> cruiseSpeed;

                fleet.addAirplane(Airplane(model, make, fuelCapacity, emptyWeight, 
                    horsepower, range, cruiseSpeed));
                cout << "Successfully added " << model << " to the database.\n";
                break;
            }
            case 'R': {
                int index;
                cout << "Which index would you like to remove (1 – " << fleet.getSize() 
                     << ")? ";
                while (true) {
                    cin >> index;
                    if (index >= 1 && index <= fleet.getSize()) {
                        fleet.removeAirplane(index - 1);
                        cout << "Index " << index << " has been removed.\n";
                        break;
                    } else {
                        cout << "Invalid Index. Please type an index between 1 and " << 
                                fleet.getSize() << ": ";
                    }
                }
                break;
            }
            case 'S': {
                char model[100];
                cout << "For what airplane would you like to search? ";
                cin.ignore();
                cin.getline(model, 100);
                fleet.searchAirplaneByModel(model);
                break;
            }
            case 'M': {
                char make[100];
                cout << "Please type the make of the airplanes you would like to list: ";
                cin.ignore();
                cin.getline(make, 100);
                fleet.listAirplanesByMake(make);
                break;
            }
            case 'Q':
                saveFleet(fleet, filename.c_str());
                cout << "Database file updated. Terminating Program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 'Q');

    return 0;
}


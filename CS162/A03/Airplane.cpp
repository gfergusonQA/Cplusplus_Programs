#include "airplane.h"

// Function: Airplane::Airplane()
// Description: DEFAULT CONSTRUCTOR, this builds the object
// Inputs: none
// Outputs: none
// Return: none
Airplane::Airplane() {
    make = new char[20];
    strcpy(make, "None");
    model = new char[20];
    strcpy(model, "None");
    maxFuel = 0.0;
    emptyWeight = 0;
    engineHP = 0;
    maxRange = 0;
    cruiseSpeed = 0;
}

// Function: Airplane::Airplane(const Airplane &)
// Description: COPY CONSTRUCTOR, creates a new Airplane
//              object as a copy of an existing one
// Inputs: other - the Airplane object to copy
// Outputs: none
// Return: none
Airplane::Airplane(const Airplane &other) {
    make = new char[strlen(other.make) + 1];
    strcpy(make, other.make);
    model = new char[strlen(other.model) +1];
    strcpy(model, other.model);
    maxFuel = other.maxFuel;
    emptyWeight = other.emptyWeight;
    engineHP = other.engineHP;
    maxRange = other.maxRange;
    cruiseSpeed = other.cruiseSpeed;
}

// Function: Airplane::operator=
// Description: COPY ASSIGNMENT OPERATOR, assigns values 
//              from one Airplane object to another
// Inputs: other - the Airplane object to copy
// Outputs: none
// Return: Airplane& - reference to the assigned Airplane object
Airplane& Airplane::operator=(const Airplane &other) {
    if (this == &other) return *this;
    delete[] make;
    delete[] model;
    make = new char[strlen(other.make) + 1];
    strcpy(make, other.make);
    model = new char[strlen(other.model) + 1];
    strcpy(model, other.model);
    maxFuel = other.maxFuel;
    emptyWeight = other.emptyWeight;
    engineHP = other.engineHP;
    maxRange = other.maxRange;
    cruiseSpeed = other.cruiseSpeed;
    return *this;
}

// Function: Airplane::~Airplane()
// Description: DESTRUCTOR, releases dynamically allocated memory
// Inputs: none
// Outputs: none
// Return: none
Airplane::~Airplane() {
    delete[] make;
    delete[] model;
}

// Function: Airplane::getMake()
// Description: Returns the make of the airplane
// Inputs: none
// Outputs: none
// Return: const char* - make of the airplane
const char* Airplane::getMake() {
    return make; 
}

// Function: Airplane::getModel()
// Description: Returns the model of the airplane
// Inputs: none
// Outputs: none
// Return: const char* - model of the airplane
const char* Airplane::getModel() { 
    return model; 
}

// Function: Airplane::getMaxFuel()
// Description: Returns the maximum fuel capacity of the airplane
// Inputs: none
// Outputs: none
// Return: double - maximum fuel capacity in gallons
double Airplane::getMaxFuel() { 
    return maxFuel; 
}

// Function: Airplane::getEmptyWeight()
// Description: Returns the empty weight of the airplane
// Inputs: none
// Outputs: none
// Return: int - empty weight in pounds
int Airplane::getEmptyWeight() { 
    return emptyWeight; 
}

 // Function: Airplane::getEngineHP()
 // Description: Returns the engine horsepower of the airplane
 // Inputs: none
 // Outputs: none
 // Return: int - engine horsepower
int Airplane::getEngineHP() { 
    return engineHP; 
}

// Function: Airplane::getMaxRange()
// Description: Returns the maximum range of the airplane
// Inputs: none
// Outputs: none
// Return: int - maximum range in nautical miles
int Airplane::getMaxRange() { 
    return maxRange; 
}

// Function: Airplane::getCruiseSpeed()
// Description: Returns the cruise speed of the airplane
// Inputs: none
// Outputs: none
// Return: int - cruise speed in knots
int Airplane::getCruiseSpeed() { 
    return cruiseSpeed; 
}

// Function: Airplane::setMake()
// Description: Sets the make of the airplane
// Inputs: make - the make to set
// Outputs: none
// Return: none
void Airplane::setMake(const char * make) {
    delete[] this->make;
    this->make = new char[strlen(make) + 1];
    strcpy(this->make, make);
}

// Function: Airplane::setModel()
// Description: Sets the model of the airplane
// Inputs: model - the model to set
// Outputs: none
// Return: none
void Airplane::setModel(const char * model) {
    delete[] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

// Function: Airplane::setMaxFuel()
// Description: Sets the maximum fuel capacity of the airplane
// Inputs: maxFuel - the maximum fuel capacity to set
// Outputs: none
// Return: none
void Airplane::setMaxFuel(double maxFuel) { 
    this->maxFuel = maxFuel; 
}

// Function: Airplane::setEmptyWeight()
// Description: Sets the empty weight of the airplane
// Inputs: emptyWeight - the empty weight to set
// Outputs: none
// Return: none
void Airplane::setEmptyWeight(int emptyWeight) { 
    this->emptyWeight = emptyWeight; 
}

// Function: Airplane::setEngineHP()
// Description: Sets the engine horsepower of the airplane
// Inputs: engineHP - the engine horsepower to set
// Outputs: none
// Return: none
void Airplane::setEngineHP(int engineHP) { 
    this->engineHP = engineHP; 
}

// Function: Airplane::setMaxRange()
// Description: Sets the maximum range of the airplane
// Inputs: maxRange - the maximum range to set
// Outputs: none
// Return: none
void Airplane::setMaxRange(int maxRange) { 
    this->maxRange = maxRange; 
}

// Function: Airplane::setCruiseSpeed()
// Description: Sets the cruise speed of the airplane
// Inputs: cruiseSpeed - the cruise speed to set
// Outputs: none
// Return: none
void Airplane::setCruiseSpeed(int cruiseSpeed) { 
    this->cruiseSpeed = cruiseSpeed; 
}

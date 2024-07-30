#include "Airplane.h"

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
Airplane::Airplane() {
    strcpy(make, "");
    strcpy(model, "");
    maxFuel = 0.0;
    emptyWeight = 0;
    engineHP = 0;
    maxRange = 0;
    cruiseSpeed = 0;
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
Airplane::Airplane(const Airplane &) {
    
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
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

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
Airplane::~Airplane() {
    delete[] make;
    delete[] model;
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
const char* Airplane::getMake() {
    return make; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
const char* Airplane::getModel() { 
    return model; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
double Airplane::getMaxFuel() { 
    return maxFuel; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
int Airplane::getEmptyWeight() { 
    return emptyWeight; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
int Airplane::getEngineHP() { 
    return engineHP; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
int Airplane::getMaxRange() { 
    return maxRange; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
int Airplane::getCruiseSpeed() { 
    return cruiseSpeed; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setMake(const char * make) {
    delete[] this->make;
    this->make = new char[strlen(make) + 1];
    strcpy(this->make, make);
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setModel(const char * model) {
    delete[] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setMaxFuel(double maxFuel) { 
    this->maxFuel = maxFuel; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setEmptyWeight(int emptyWeight) { 
    this->emptyWeight = emptyWeight; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setEngineHP(int engineHP) { 
    this->engineHP = engineHP; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setMaxRange(int maxRange) { 
    this->maxRange = maxRange; 
}

// Function: Airplane::Airplane()
// Description: 
// Inputs: 
// Outputs: 
// Return: 
void Airplane::setCruiseSpeed(int cruiseSpeed) { 
    this->cruiseSpeed = cruiseSpeed; 
}

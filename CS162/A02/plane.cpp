#include "plane.h"

Airplane::Airplane() {
    strcpy(make, "");
    strcpy(model, "");
    maxFuel = 0.0;
    emptyWeight = 0;
    engineHP = 0;
    maxRange = 0;
    cruiseSpeed = 0;
}

// Name:   getMake()
// Desc:   This function returns the make of the airplane.
// input:  None
// output: None
// return: const char* (make of the airplane)
const char * Airplane::getMake() {
    return make;
}

// Name:   getModel()
// Desc:   This function returns the model of the airplane.
// input:  None
// output: None
// return: const char* (model of the airplane)
const char * Airplane::getModel() {
    return model;
}

// Name:   getMaxFuel()
// Desc:   This function returns the maximum fuel capacity of the airplane.
// input:  None
// output: None
// return: double (maximum fuel capacity)
double Airplane::getMaxFuel() {
    return maxFuel;
}

// Name:   getEmptyWeight()
// Desc:   This function returns the empty weight of the airplane.
// input:  None
// output: None
// return: int (empty weight)
int Airplane::getEmptyWeight() {
    return emptyWeight;
}

// Name:   getEngineHP()
// Desc:   This function returns the engine horsepower of the airplane.
// input:  None
// output: None
// return: int (engine horsepower)
int Airplane::getEngineHP() {
    return engineHP;
}

// Name:   getMaxRange()
// Desc:   This function returns the maximum range of the airplane.
// input:  None
// output: None
// return: int (maximum range)
int Airplane::getMaxRange() {
    return maxRange;
}


// Name:   getCruiseSpeed()
// Desc:   This function returns the cruise speed of the airplane.
// input:  None
// output: None
// return: int (cruise speed)
int Airplane::getCruiseSpeed() {
    return cruiseSpeed;
}

// Name:   setMake()
// Desc:   This function sets the make of the airplane.
// input:  const char* (new make of the airplane)
// output: None
// return: None
void Airplane::setMake(const char * newMake) {
    strncpy(make, newMake, STR_SIZE - 1);
    make[STR_SIZE - 1] = '\0';
}

// Name:   setModel()
// Desc:   This function sets the model of the airplane.
// input:  const char* (new model of the airplane)
// output: None
// return: None
void Airplane::setModel(const char * newModel) {
    strncpy(model, newModel, STR_SIZE - 1);
    model[STR_SIZE - 1] = '\0';
}

// Name:   setMaxFuel()
// Desc:   This function sets the maximum fuel capacity of the airplane.
// input:  double (new maximum fuel capacity)
// output: None
// return: None
void Airplane::setMaxFuel(double newMaxFuel) {
    maxFuel = newMaxFuel;
}

// Name:   setEmptyWeight()
// Desc:   This function sets the empty weight of the airplane.
// input:  int (new empty weight)
// output: None
// return: None
void Airplane::setEmptyWeight(int newEmptyWeight) {
    emptyWeight = newEmptyWeight;
}

// Name:   setEngineHP()
// Desc:   This function sets the engine horsepower of the airplane.
// input:  int (new engine horsepower)
// output: None
// return: None
void Airplane::setEngineHP(int newEngineHP) {
    engineHP = newEngineHP;
}

// Name:   setMaxRange()
// Desc:   This function sets the maximum range of the airplane.
// input:  int (new maximum range)
// output: None
// return: None
void Airplane::setMaxRange(int newMaxRange) {
    maxRange = newMaxRange;
}

// Name:   setCruiseSpeed()
// Desc:   This function sets the cruise speed of the airplane.
// input:  int (new cruise speed)
// output: None
// return: None
void Airplane::setCruiseSpeed(int newCruiseSpeed) {
    cruiseSpeed = newCruiseSpeed;
}

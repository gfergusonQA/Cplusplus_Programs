#ifndef FLEET_H
#define FLEET_H

#include "plane.h"

class Fleet {
private:
    int count;
    char fileName[STR_SIZE];
    ifstream inFile;
    Airplane fleetAirplanes[ARR_SIZE];
    Airplane tempPlane; // Temporary storage for inserting a plane
    bool insert();      // private method without arguments
public:
    Fleet();            // Default Constructor
    int loadPlanes();
    void printPlanes();
    void listByMake();
    bool addAPlane();
    bool removeAPlane();
    void writePlanes();
    bool openTheFile();
};

#endif // FLEET_H

#ifndef FLEET_H
#define FLEET_H

#include "tools.h"
#include "airplane.h"

using namespace std;

class Fleet {
private:
    char fileName[STR_SIZE];
    ifstream inFile;
    int count;
    int capacity;
    Airplane * fleetAirplanes;
    bool insert();
public:
    Fleet();                       // Default constructor.
    ~Fleet();                      // Destructor.
    Fleet(const Fleet &) = delete; // Deletes the Copy constructor (prevents copying)
    Fleet &operator=(const Fleet &) = delete; // Deletes Copy assignment operator 
                                   // (also prevents compiler from generating a copy 
                                   // assign. op.) also prevents copying
    int loadPlanes();
    void printPlanes();
    void listByMake();
    void search();
    bool addAPlane();
    bool removeAPlane();
    void writePlanes();
    void growArray();
    bool openTheFile();
};

#endif // FLEET_H

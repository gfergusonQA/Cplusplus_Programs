#ifndef FLEET_H
#define FLEET_H

#include "Airplane.h"

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
    ~Fleet(); // Destructor
    Fleet(const Fleet &) = delete;
    // below is overloaded operator 
    Fleet & operator=(const Fleet &) = delete;
    int loadPlanes();
    void printPlanes();
    void listByMake();
    bool addAPlane();
    bool removeAPlane();
    void writePlanes();
    void growArray();
    void searchAirplaneByModel(); // confirmed by teacher

    // New public member functions ( I couldn't get it to work otherwise)
    const char* getFileName() const;
    bool openTheFile();
};

#endif // FLEET_H

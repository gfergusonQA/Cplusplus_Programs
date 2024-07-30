#ifndef PLANE_H
#define PLANE_H

#include "tools.h"

using namespace std;

class Airplane {
private:
    char make[STR_SIZE];
    char model[STR_SIZE];
    double maxFuel;   // in gallons
    int emptyWeight;  // in pounds
    int engineHP;     // horse power
    int maxRange;     // nautical miles
    int cruiseSpeed;  // knots

public:
    Airplane(); // default constructor.

    // Getters
    const char * getMake();
    const char * getModel();
    double getMaxFuel();
    int getEmptyWeight();
    int getEngineHP();
    int getMaxRange();
    int getCruiseSpeed();

    // Setters
    void setMake(const char *);
    void setModel(const char *);
    void setMaxFuel(double);
    void setEmptyWeight(int);
    void setEngineHP(int);
    void setMaxRange(int);
    void setCruiseSpeed(int);
};

#endif // PLANE_H

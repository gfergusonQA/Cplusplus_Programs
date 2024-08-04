#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "tools.h"

using namespace std;

class Airplane {
private:
    char * make;
    char * model;
    double maxFuel;   // in gallons
    int emptyWeight;  // in pounds
    int engineHP;     // horsepower
    int maxRange;     // nautical miles
    int cruiseSpeed;  // knots

public:
    Airplane();                             // Default constructor.
    Airplane(const Airplane &);             // Copy constructor.
    ~Airplane();                            // Destructor.
    Airplane & operator=(const Airplane &); // Copy assignment operator.

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

#endif // AIRPLANE_H

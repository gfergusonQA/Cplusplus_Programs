#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "tools.h"

using namespace std;

class Airplane {
private:
    char * make;
    char * model;
    double maxFuel;
    int emptyWeight;
    int engineHP;
    int maxRange;
    int cruiseSpeed;

public:
    Airplane();
    Airplane(const Airplane &);
    ~Airplane();
    Airplane & operator=(const Airplane &);

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

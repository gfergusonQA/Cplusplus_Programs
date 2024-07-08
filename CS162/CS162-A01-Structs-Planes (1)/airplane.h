/* A01 Planes - Structs - Arrays
 * airplane.h, header file for the Airplane struct,
 * prototypes, and constants. */

#pragma once
#ifndef airplane_h
#define airplane_h

// Constants
const int STR_SIZE = 128;
const int ARR_SIZE = 20;
const int LARGE_NUMBER = 1000;
const int ERROR = -1;
const int MAX_COUNT = 300;
const int MAX_CHAR = 101;

// Libraries
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Struct
struct Airplane {
  char model[STR_SIZE];
  char make[STR_SIZE];
  double maxFuel;      // in gallons
  int emptyWeight;     // in pounds
  int engineHP;        // horsepower
  int maxRange;        // nautical miles
  int cruiseSpeed;     // knots
};

// Function Prototypes
int loadPlanes(Airplane planes[], ifstream & inFile);
bool addPlane(Airplane planes[], int &count, int &newIndex);
bool insertPlane(Airplane planes[], Airplane newPlane, int & count);
void printPlanes(Airplane planes[], int count);
bool openTheFile(ifstream & inFile);
void writePlane(Airplane planes[], int count);
void search(Airplane planes[], int count, const char searchName[]);
void readInt(const char prompt[], int &result);
void searchByModel(Airplane planes[], int count);
void listByMake(Airplane planes[], int count);
void convertCase(char tempStr[]);


#endif // airplane.h
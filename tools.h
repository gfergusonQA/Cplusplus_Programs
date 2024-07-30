#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "Fleet.h"

using namespace std;

const int STR_SIZE = 100;

void displayMenu();
bool validateInput(const char* input, float& value);
bool validateInput(const char* input, int& value);

#endif // TOOLS_H

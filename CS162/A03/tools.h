#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int STR_SIZE = 100;

void welcome();
void displayMenu();
bool validateInput(double &value, double min, double max);
bool validateInput(int &value, int min, int max);

#endif // TOOLS_H

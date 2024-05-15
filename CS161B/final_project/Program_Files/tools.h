#pragma once

#include "movie_operations.h"

// function prototypes
void welcome();
void displayMenu();
void readOption(char &option);
void exeOption(Movie movies[], int &count, char option);
void readInt(const char prompt[], int &temp);
void toLowerCase(char str[]);

#pragma once
/******************************************************************************
#******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_TITLES = 100;
const int MAXCHAR = 250;

struct Movie {
    char title[MAXCHAR];
    char releaseDate[11]; // YYYY-MM-DD format
    double voteAverage;
    int voteCount;
};

// Function prototypes
void loadMovies(Movie movies[], int& count, const char* filename);
void addMovie(Movie movies[], int& count);
void removeMovie(Movie movies[], int& count);
void findMovie(const Movie movies[], int count);
void printMovies(const Movie movies[], int count);
void findMaxRating(const Movie movies[], int count);
void saveMovies(const Movie movies[], int count, const char* filename);
bool isValidDate(const char* date);



/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       CS161B Final Project: Gina's movie database program
# Date:             03-17-24
# Description:      This program starts with 10 movies from the TMDB Box Office
#                   database. The user can add, print, remove, find, see which
#                   movie has the highest rating, and quit the program from a
#                   menu. There is data validation and other scenarios in mind.
# Input:            None
# Output:           saves movies to "movies_output.txt" & prints menu to console
# Sources:          Zybooks & Shawli's notes
#******************************************************************************/
#include "movie_operations.h"
#include "tools.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    Movie movies[MAX_TITLES] = {};
    int count = 0;
    char option = ' ';
    ofstream outFile;
  
    loadMovies(movies, count, "movies.txt");
    welcome();
    do {
      displayMenu();
      readOption(option);
      exeOption(movies, count, option);
      
    } while(option != 'Q' && option != 'q');

    saveMovies(movies, count, "movies_output.txt"); // save on exit
    return 0;
}

//Name:   displayMenu()
//Desc:   This function displays the menu to the console
//input:  None
//output: strings for menu options
//return: none (void)
void displayMenu() {
    cout << "\nPick an option from below:\n\n";
    cout << "(A)DD\n";
    cout << "(R)EMOVE\n";
    cout << "(P)RINT\n";
    cout << "(F)IND\n";
    cout << "(M)AX\n";
    cout << "(Q)UIT\n\n";
}


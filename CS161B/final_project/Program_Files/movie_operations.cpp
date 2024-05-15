/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       CS161B Final Project: Gina's movie database program
# Date:             03-17-24
# Description:      Example: This file is file for movie_operations.cpp
# Input:            movies[]: array of movie structs, and modified by functions
# Output:           movies[]: to the movie_output.txt file
# Sources:          Zybooks & Shawli's notes
#******************************************************************************/
#include "movie_operations.h"
#include "tools.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//Name:   loadMovies(Movie movies[], int& count, const char* filename)
//Desc:   Loads movies from a file into the movies array
//input:  filename (const char*), reference to movies array Movie[],
//        count: reference to the count of movies (int&)
//output: None directly, but loadMovies loads movies and updates the count
//return: None
void loadMovies(Movie movies[], int& count, const char* filename) {
    ifstream file(filename);
    count = 0;
    if (!file) {
        cout << "\nFailed to open file." << endl;
        return;
    }
    while (file.getline(movies[count].title, MAXCHAR, ';') &&
           file.getline(movies[count].releaseDate, 11, ';') &&
           file >> movies[count].voteAverage &&
           file.ignore() && // Ignores the semicolon after voteAverage
           file >> movies[count].voteCount) {
        file.ignore(1000, '\n'); // Ignores the rest of the line
        if (count++ >= MAX_TITLES) break;
    }
    file.close();
}

//Name:   addMovie(Movie movies[], int& count)
//Desc:   adds a new movie to the movies array
//input:  movie[]: movies array, count: count of movies
//output: None directly, but adds a new movies to movies array and increments+1
//return: returns to the program based on conditions, but void otherwise
void addMovie(Movie movies[], int& count) {
    char dateInput[11] = {};
    if (count >= MAX_TITLES) {
        cout << "\nMovie list is full." << endl;
        return;
    }
    cout << "\nEnter the movie title that you would like to add: ";
    cin.getline(movies[count].title, MAXCHAR);

    // Handling the release date input and validation
    do {
        cout << "\nEnter the release date in YYYY-MM-DD format: ";
        cin.getline(dateInput, 11);
        if (!isValidDate(dateInput)) {
            cout << "\nInvalid date format. Please enter in YYYY-MM-DD "
                    " format." << endl;
        }
    } while (!isValidDate(dateInput));
    strcpy(movies[count].releaseDate, dateInput);

    // Handling the vote average input with validation
    cout << "\nEnter the vote average (Decimals ok!): ";
    while (!(cin >> movies[count].voteAverage) || 
                    movies[count].voteAverage < 0) {
        cout << "\nInvalid input. Please enter a non-negative number for the"
                " vote average: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin.ignore(100, '\n'); 
    int tempVoteCount = 0;
    readInt("\nEnter the total number of votes: ", tempVoteCount);
    movies[count].voteCount = tempVoteCount;
    count++; // Incrementing the movie count after a successful addition
}

//Name:   isValidDate(const char* date)
//Desc:   Helper function that validates date format for Release date
//input:  none
//output: true or false (boolean)
//return: returns true if conditions are met
bool isValidDate(const char* date) {
    // Simple format validation: YYYY-MM-DD
    if (strlen(date) != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    // Further checks for month and day validity could be added here
    return true;
}

//Name:   removeMovie(Movie movies[], int& count)
//Desc:   removies a movie from movies array based on user's index input
//input:  movies[] array, and reference to count, index (integer): holds input
//output: prompts for user, movies & count
//return: return to program, or nothing otherwise (void function)
void removeMovie(Movie movies[], int& count) {
    int index = 0;
    int i = 0;
    string removedMovieTitle = "";
    cout << "Enter the index of the movie to remove: ";
    cin >> index;
    cin.ignore();
    if (index < 0 || index >= count) {
        cout << "\nInvalid index. No movie removed." << endl;
        return;
    }
    // capture the title of the movie removed
    removedMovieTitle = movies[index].title;
    for (i = index; i < count - 1; i++) {
        movies[i] = movies[i + 1];
    }
    count--;
    cout << "\nThe movie, " << removedMovieTitle << ", was removed "     
            "successfully.\n\n";
    printMovies(movies, count); // This will show remaining movies
}

//Name:   findMovie(const Movie movies[], int count)
//Desc:   Finds and prints a movie deatils but its title
//input:  movies array and count gets altered
//output: prompts and movie array
//return: return true or false in some areas but none otherwise (void)
void findMovie(const Movie movies[], int count) {
    char searchQuery[MAXCHAR];
    char titleLower[MAXCHAR];
    int i = 0;
    bool found = false;
    cout << "\nEnter partial or entire movie title to find: ";
    cin.getline(searchQuery, MAXCHAR);
    toLowerCase(searchQuery); // convert the search query to lowercase 
    for (i = 0; i < count; i++) {
        strcpy(titleLower, movies[i].title); // copy movie title
        toLowerCase(titleLower); // conver movie title to lowercase
        if (strstr(titleLower, searchQuery) != NULL) { // using lowercase
            cout << "\nMovie found: ";
            cout << "\nTitle: " << movies[i].title << "\nRelease Date:" << 
                    movies[i].releaseDate << "\nVote Average: "<<
                    movies[i].voteAverage << "\nVote Count: " <<       
                    movies[i].voteCount << endl;
            found = true;
            break; // or continue to find all matches
        }
    }
    if (!found) {
        cout << "\nMovie not found.  :(\n\n";
    }
}

//Name:   printMovies(const Movie movies[], int count)
//Desc:   Prints all movies from movies array
//input:  none
//output: movies array with formatting
//return: None (void)
void printMovies(const Movie movies[], int count) {
    cout << "\n"
         << left << setw(5) << "Index #"
         << right << setw(40) << "Movie_Title" 
         << setw(15) << "Release_Date"
         << setw(15) << "Vote_Average"
         << setw(15) << "Vote_Count\n\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << i
             << right << setw(40) << movies[i].title
             << setw(15) << movies[i].releaseDate
             << setw(15) << movies[i].voteAverage
             << setw(15) << movies[i].voteCount << endl;
    }
}

//Name:   findMaxRating(const Movie movies[], int count)
//Desc:   Finds and prints the movie with the highest rating
//input:  movies array / count of movies
//output: all details of movie w/ max rating to the user side
//return: None (void_)
void findMaxRating(const Movie movies[], int count) {
    int maxIndex = 0;
    int i = 0;
    if (count == 0) {
        cout << "\nNo movies to evaluate." << endl;
        return;
    }
    for (i = 1; i < count; i++) {
        if (movies[i].voteAverage > movies[maxIndex].voteAverage) {
            maxIndex = i;
        }
    }
    cout << "\nThe movie with the highest rating is: " << movies[maxIndex].title << " with an average rating of " << movies[maxIndex].voteAverage << " out of 10!\n" << endl << endl;
}

//Name:   saveMovies(const Movie movies[], int count, const char* filename)
//Desc:   Saves the current list of movies back to the file
//input:  movies array, count of movies, and filename const char
//output: saves to the movies array to the movie_output.txt file
//return: NOne (void)
void saveMovies(const Movie movies[], int count, const char* filename) {
    int i = 0;
    ofstream file(filename);
    if (!file) {
        cout << "Failed to open file for writing." << endl;
        return;
    }
    for (i = 0; i < count; ++i) {
        file << movies[i].title << ";" << movies[i].releaseDate << ";" 
             << movies[i].voteAverage << ";" << movies[i].voteCount << endl;
    }
    file.close();
}

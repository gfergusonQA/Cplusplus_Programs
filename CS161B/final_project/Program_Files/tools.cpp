#include "tools.h"
// #include "movie_operations.h"
#include <iostream>
#include <cstring>
/******************************************************************************
#******************************************************************************/
using namespace std;


//Name:   welcome()
//Desc:   This function displays the welcome message
//input:  None
//output: messages
//return: None (void)
void welcome() {
 cout << "\n\nWelcome! This program gives statistical information from the TMDB "
         "Box Office where movies have been ranked popularity from 1-10, and "
         "average vote of movie. There will also be vote count, and release "            
         "date columns.\n\nYou can Add to the dataset, Print the dataset, "
         "Find the movie title with the highest rating, or Quit the program.\n";
}

//Name:   readOption()
//Desc:   validates char option data
//input:  option(char reference)
//output: option
//return: None (void)
void readOption(char &option) {
  cin >> option;
  cin.ignore(100, '\n');
}

//Name:   exeOption(Movie movies[], int &count, char option)
//Desc:   This function has the switch statement for the user's menu choice
//input:  option (char): uses the user input to go through the switch statement
//output: exit message
//return: None (void)
void exeOption(Movie movies[], int &count, char option) {
    switch (option) {
        case 'A':
        case 'a':
            addMovie(movies, count);
            break;
        case 'R':
        case 'r':
            removeMovie(movies, count);
            break;
        case 'P':
        case 'p':
            printMovies(movies, count);
            break;
        case 'F':
        case 'f':
            findMovie(movies, count);
            break;
        case 'M':
        case 'm':
            findMaxRating(movies, count);
            break;
        case 'Q':
        case 'q':
            cout << "\nThank you so much for using my movie rating "
                    "program! I hope you can watch one of these "
                    "feature films soon :)\n";
            saveMovies(movies, count, "movies_output.txt"); 
            // Save changes made during the session ^
            break;
        default:
            cout << "\nInvalid option. Please try again.\n";
            break;
    }
}

//Name:   readInt(const char prompt[], int &temp)
//Desc:   This function reads the integers from the user's menu choice
//input:  temp variable for user choice (integer)
//output: char prompt array, it holds the choice
//return: None (void)
void readInt(const char prompt[], int &temp) {
  cout << prompt;
  while (!(cin >> temp)) {
    cout << "\nInvalid input. Please enter a valid number: ";
    cin.clear();
    cin.ignore(100, '\n');
  }
  cin.ignore(100, '\n');
}

//Name:   toLowerCase(char str[])
//Desc:   Helper function to specifically help the findMovie search be more
//        user friendly. If they type "bear" instead of "Bear", it will locate
//        the correct movie
//input:  char str[] array for moving through the loop to change all chars to 
//        lowercase
//output: lowercase letters
//return: None (void)
void toLowerCase(char str[]) {
  int i = 0;
  for (i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

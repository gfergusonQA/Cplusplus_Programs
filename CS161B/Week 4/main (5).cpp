/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Assignment 4: Course Roster Program
# Date:             Saturday, February 3, 2024
# Description:      This is a program for reading course numbers, number of
#                   students enrolled, and from user input. Then the program 
#                   will cancel any courses that have < 10 student and remove 
#                   them from the courses list, and shift the array to do so. 
#                   The maximum number of students is <= 25, and the maximum 
#                   number of courses is 20, with maximum characters of 51.
#                   
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Zylabs Chapter 11, and Ms. Sengupta's weekly notes/labs
#*****************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

// my constant variables
const int MAXCOURSES = 20;
const int MAXCHAR = 51;

// my function prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);

//Name:   main()
//Desc:   This function reads a string from the user and returns it
//input:  None
//output: prompt
//return: string name
int main() {
    char courseNums[MAXCOURSES][MAXCHAR];
    int students[MAXCOURSES];
    int count = 0;

    welcome();
    readInput(courseNums, students, count);
    printList(courseNums, students, count);

    cancelCourses(courseNums, students, count);

    cout << "List after cancellations:" << endl;
    printList(courseNums, students, count);

    cout << "\nThank you for checking out my Course Rosters program!" << endl;

    return 0;
}

//Name: welcome()
//Desc: This function displays the welcome message
//input: None
//output: welcome message
//return: None
void welcome() {
    cout << "Welcome to my Course Rosters program!!" << endl;
}

//Name: readInt(string prompt, int &num)
//Desc: This function reads the course and checks for fail 
//input: num (integer)
//output: prompt
//return: None
void readInt(string prompt, int &num) {
    cout << prompt;
    cin >> num;

    while (!cin) {
      cout << "Invalid input. Please enter a valid number." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << prompt;
      cin >> num;
    }
  cin.ignore(100, '\n');
}

//Name: displayMenu()
//Desc: This function displays the menu to the user
//input: None
//output: None
//return: None
void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  // Implement this function to read course numbers and students from 
    // the user
    // Use readInt for reading the number of students
  char userInput[MAXCHAR];
  int num = 0;
  int i = 0;

  cout << "Enter course number and students enrolled when prompted. "
        "Enter Quit or quit for course number when you are done." << endl;
  cout << "Enter course number: ";
  cin.ignore();
  cin.getline(userInput, MAXCHAR);

  while (strcmp(userInput, "Quit") != 0 && strcmp(userInput, "quit") != 0 && count < MAXCOURSES) {
      readInt("Number of students enrolled: ", num);

      // Validating num of students
      while (num < 0 || num > 25) {
        cout << "Invalid number!! Please enter a number between 0 and 25"
          << endl;
        readInt("Number of students enrolled: ", num);
      }
      i = count;
      while(i > 0 && strcmp(courseNums[i - 1], userInput) > 0) {
        strcpy(courseNums[i], courseNums[i-1]);
        students[i] = students[i-1];
        i--;
      }
      strcpy(courseNums[i], userInput);
      students[i] = num;

      count++;

      if(count < MAXCOURSES) {
        cout << "Enter course number: ";
        cin.ignore();
        cin.getline(userInput, MAXCHAR);
      }
    }
  }

//     char userInput[MAXCHAR] = {0};
//     int num = 0;

//     cout << "Enter course number and students enrolled when prompted."
//       "Enter Quit or quit for course number when you are done." << endl;

//     while (count < MAXCOURSES) {
//         cout << "Enter course number: ";
//         cin.ignore();
//         cin.getline(userInput, MAXCHAR);

//         if (strcmp(userInput, "quit") != 0 || 
//             strcmp(userInput, "Quit") != 0) {
//             break;
//         }

//         readInt("Enter number of students enrolled: ", num);

//         while (num < 0 || num > 25) {
//             cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
//             readInt("Enter number of students enrolled: ", num);
//         }

//         int i = count - 1;

//         while (i >= 0 && strcmp(userInput, courseNums[i]) < 0) {
//             strcpy(courseNums[i + 1], courseNums[i]);
//             students[i + 1] = students[i];
//             i--;
//         }

//         strcpy(courseNums[i + 1], userInput);
//         students[i + 1] = num;

//         count++;
//     }
// }



//Name: displayMenu()
//Desc: This function displays the menu to the user
//input: None
//output: None
//return: None
void printList(char courseNums[][MAXCHAR], int students[], int count) {
    int i = 0;
  
    cout << "\nList of courses and students:" << endl;
    for (i = 0; i < count; i++) {
        cout << courseNums[i] << "\t" << students[i] << endl;
    }
}

//Name: displayMenu()
//Desc: This function displays the menu to the user
//input: None
//output: None
//return: None
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count) {
    int i = 0; // index for count
    int j = 0;

    for (i = 0; i < count; i++) {
      if (students[i] < 10) {
        for (j = 1; j < count - 1; j++) {
          strcpy(courseNums[j], courseNums[j + 1]);
          students[j] = students[j + 1];
        }
      count --;
      i--;
      }
    }
}
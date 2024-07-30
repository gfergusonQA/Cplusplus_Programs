/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Assignment 4: Course Roster Program
# Date:             Tuesday, February 6, 2024
# Description:      This is a program for reading course numbers, number of
#                   students enrolled, and from user input. Then the program 
#                   will cancel any courses that have < 10 student and remove 
#                   them from the courses list, and shift the array in 
#                   ascending order by student count to do so. 
#                   The maximum number of students is <= 25, and the maximum 
#                   number of courses is 20, with maximum characters of 51.
#                   
# Input:            char courseNums[]: stores classe names, int students[]:
#                   stores student numbers, and int &count: stores # of courses
# Output:           printList() prints out the list of courses & # of students
# Sources:          Zylabs Chapter 11, Zain (tutor) session, & class notes
#*****************************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// my constant variables
const int MAXCOURSES = 25;
const int MAXCHAR = 51;
const int CAP = 25;

// my function prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);

//Name:   main()
//Desc:   This function uses all of the functions above to print out courses
//input:  int students[MAXCOURSES]: array to store # of students in each course
//        int courseNums[MAXCOURSES][MAXCHAR]: array to store courses 
//        numbers/names
//output: prompts
//return: 0
int main() {
    char courseNums[MAXCOURSES][MAXCHAR];
    int students[MAXCOURSES];
    int count = 0;

    welcome();
    readInput(courseNums, students, count);
    cout << "\nList of courses and students:" << endl;
    printList(courseNums, students, count);
    cancelCourses(courseNums, students, count);
    cout << "\nList after cancellations:" << endl;
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
    cout << "Enter course number and students enrolled when prompted." << endl;
    cout << "Enter Quit or quit for course number when you are done." << endl;
}

//Name: readInt(string prompt, int &num)
//Desc: This function checks for data validation for # enrolled students
//input: num (integer): whatever # function is using
//output: prompt (string): stores any characters from user input
//return: None
void readInt(string prompt, int &num) {
    cout << prompt;
    cin >> num;
  
    while (!cin || num < 0 || num > 25) {
      cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << prompt;
      cin >> num;
    }
}

//Name: readInput()
//Desc: This function updates course & student count and sorts the parallel arrays
//input: count (integer) - count of students, students[] (integer): array to 
//       store # of students from user input, 
//       int courseNums[MAXCOURSES][MAXCHAR]: 
//       array to store courses numbers/names
//output: strings for user prompts
//return: None
void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  char tempName[MAXCHAR];
  int i = 0;
  int j = 0;
  
  cout << "Enter course number and students enrolled when prompted.\n"
          "Enter Quit or quit for course number when you are done." << endl;
  cout << "Enter course number: ";
  cin.getline(tempName, MAXCHAR);

  while (strcmp(tempName, "Quit") != 0 && strcmp(tempName, "quit") != 0){

    if(count == CAP) {
      cout << "Array is full!" << endl;
    } else {
    if(!count) {
      strcpy(courseNums[count], tempName);
      readInt ("Number of students enrolled: ", students[i]);
    } else {
         while(i < count && strcmp(courseNums[i], tempName) < 0) {
        i++;
      }
      for (j = count; j > i; j--) {
        strcpy(courseNums[j], courseNums[j-1]);
        students[j] = students[j - 1];
      }
      strcpy(courseNums[i], tempName);
      readInt ("Number of students enrolled: ", students[count]);
    }
    count++;
    cin.ignore(100, '\n');
    cout << "Enter course number: ";
    cin.getline(tempName, MAXCHAR);
    }
    }
}

//Name: printList(char courseNums[][MAXCHAR], int students[], int count)
//Desc: This function prints out courseNums, students, and count using
//      a for loop that is paired with the courseNums[] and students[] arrays
//input: courseNames, students, count - same as above
//output: Prints 2 columns for course name and # of students in a format
//return: None
void printList(char courseNums[][MAXCHAR], int students[], int count) {
    int i = 0;
  
    for (i = 0; i < count; i++) {
        cout << left << setw(10) << courseNums[i] << setw(10)
          << students[i] << endl;
    }
}

//Name: cancelCourses(char courseNums[][MAXCHAR], 
//      int students[], int &count
//Desc: This function cancels courses w/ students < 10
//input: i (int) iterates over each course as index placeholder
//       j (int) iterates to match the index of i's loop for
//       courseNums/students
//output: None
//return: None
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count) {
    int i = 0; // index for count
    int j = 0; // index for courseNum / student paired locations

    for (i = 0; i < count; i++) {
      if (students[i] < 10) {
        for (j = i; j < count - 1; j++) {
          strcpy(courseNums[j], courseNums[j + 1]);
          students[j] = students[j + 1];
        }
      count--;
      i--;
      }
    }
}
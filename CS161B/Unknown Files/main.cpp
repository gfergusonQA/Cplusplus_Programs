//The client file or the driver file
//This file has the main() function
//Add header comments here.
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"

using namespace std;

int main() {
  // INitialize the course
  Course course = initCourse();

  // Try opening the file containing student data
  ifstream inFile("students.txt");
  if(!inFile)
  {
    cout << "File did not open! Program Exiting!!" << endl;
    return 1; // exit if the file doesn't open
  }

  //calls readStudent to read from the file and add them
  readStudent(inFile, course);

  //calls printRoster to print the roster
  cout << "Welcome to my Course Roster Program" << endl;
  cout << "\nHere is the course roster: " << endl;
  printRoster(course);

  // Prompt to drop a student from the roster
  char lastNameToDrop[20];
    cout << "\nEnter the last name of the student to drop: ";
    cin >> lastNameToDrop;
    dropStudent(lastNameToDrop, course);

    // print the roster after dropping the student
    cout << "\nHere is the course roster after dropping"
            " a student: " << endl;
    printRoster(course);

    // find and print the student w the highest GPA
    Student topStudent = findStudentHighestGPA(course);
    cout << "\nThe student with the highest GPA is: " << endl;

    //calls printStd to print the student with the highest GPA
    printStd(topStudent);

    /*Add code here to call function*/
    inFile.close();
    cout << "\nThank you for using my Student Roster program!!" << endl;
          return 0;
  }


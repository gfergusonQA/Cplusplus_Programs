//The implementation file for Course.h
//It loads students from a text file.
#include <iostream>
#include <cstring>
#include <fstream>
#include "Course.h"
#include "Student.h"

using namespace std;

//initiaizes a course variable and returns it. The array is empty
//and the number of students is set to 0.
Course initCourse() {
  Course course;
  course.numStudents = 0;
  return course;
}

// EDITED FUNCTION FROM IDE BECAUSE OF KNOW EOF() ERROR WITH VIM/LINUX
void readStudent(ifstream &inFile, Course &course)
{
  Student student;

  // Attempt to read the first name; if successful, continue with the rest
  while(inFile.get(student.first, 20, ';') && course.numStudents <= 19)
  {
    inFile.ignore(100, ';');
    inFile.get(student.last, 20, ';');
    inFile.ignore(100, ';');
    inFile >> student.gpa;
    inFile.ignore(100, '\n'); // Ignore the newline character at the end

    addStudent(student, course);
    }
  }

//adds a student to the roster, and increment count
//modify this function to add the student sorted by name
//do not use any sorting functions.
//See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course) {
  if (course.numStudents < 20) {
    course.roster[course.numStudents++] = student;
  }
}

/*Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
void dropStudent(char *lastname, Course &course);
*/
void dropStudent(char *lastname, Course &course) {
  int i = 0;
  int j = 0;
  
  for (i = 0; i < course.numStudents; i++) {
    if (strcmp(course.roster[i].last, lastname) == 0) {
      for (j = i; j < course.numStudents - 1; j++) {
        course.roster[j] = course.roster[j + 1];
      }
      course.numStudents--; // Correctly decrease student count
      break; // Assuming unique last names
    }
  }
}

Student findStudentHighestGPA(Course course){
  int i = 0;

  if (course.numStudents == 0) {
    return initStudent((char*)"None", (char*)"None", 0.0);
  }
  Student topStudent = course.roster[0];
  for (i = 1; i < course.numStudents; i++) {
    if (course.roster[i].gpa > topStudent.gpa) {
      topStudent = course.roster[i];
    }
  }
  return topStudent;
}

//prints a whole Course roster calling student print.
//use a for loop and print all the students
//must call the printStd function in Student.h
void printRoster(Course course) {
  int i = 0;
  cout << endl;
  for (i = 0; i < course.numStudents; i++) {
    printStd(course.roster[i]);
  }
}


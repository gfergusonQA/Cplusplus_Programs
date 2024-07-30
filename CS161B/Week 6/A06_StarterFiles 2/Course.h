//The Course struct that uses the Student struct to create a list of students.
#ifndef COURSE_H_
#define COURSE_H_

#include "Student.h"
#include <fstream>

using namespace std;

struct Course {
	Student roster[20];
	int numStudents;
};

//Function Prototypes
//Check Course.cpp and the Assignment document for details 
//on each function.
Course initCourse();
void readStudent(ifstream &inFile, Course &course);
void addStudent(Student student, Course &course);

/*Based on the grade level you are doing: 
Please read the appropriate level assignment document.
If you are not writing some functions for the grade level you choose, remove the function prototypes.
*/
void dropStudent(char *lastname, Course &course);
Student findStudentHighestGPA(Course course);

//You need the printRoster for all levels.
void printRoster(Course course);

#endif
//The implementation file for Course.h
//It loads students from a text file.
#include <iostream>
#include <cstring>

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

//reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{
 /*Add code here to read from the file and call addStudent to add each student to the roster.*/ 
}

//adds a student to the roster, and increment count
//modify this function to add the student sorted by name
//do not use any sorting functions.
//See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course) {
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	course.numStudents++;
}

//prints a whole Course roster calling student print.
//use a for loop and print all the students
//must call the printStd function in Student.h
void printRoster(Course course)
{
  /*Add your code here*/
}

/*Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
void dropStudent(char *lastname, Course &course);
Student findStudentHighestGPA(Course course);
*/
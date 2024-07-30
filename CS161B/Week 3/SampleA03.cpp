/*This program manages 3 parallel arrays. Employee ID (int), Employee Salary (double), and Percentage Raise (double) based on their salary. Emp ID and Salary are inputs from the user. Raise is calculated based on their salary - see note at the end of this comment section. Functions are used to read the input, print the list, and calculate the raise. The Raise is then entered in another parallel array and then passed to the print function. The list CAP is 20 employees. This is the bare minimum. Add better UI and comments etc.
  Salary                  Raise %
  <1000                    1.5
  >=1000 and < 5000        2.0
  >=5000 and < 10000       2.7
  >=10000                   3.5
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
//constants
const int CAP = 20;
const int MAXCHAR = 101;

//Function Prototypes
void welcome();
void readInput(int empId[], int salary[], int &count);
void calcRaise(int empId[], int salary[], double raise[], int count);
//overloaded printData function
void printData(int empId[], int salary[], int count);
void printData(int empId[], int salary[], double raise[], int count);
//validating functions
void readInt(char prompt[], int &num);
bool validNum(char prompt[], int &tempNum);

int main() 
{
  //declare arrays and variables
  int empId[CAP] = {0};
  int salary[CAP] = {0};
  int count = 0;
  double raise[CAP] = {0};
  //welcome message here.
  welcome();
  //call function to read input
  readInput(empId, salary, count);
  printData(empId, salary, count);
  calcRaise(empId, salary, raise, count);
  printData(empId, salary, raise, count);
  cout << "Thank you for using my raise calculator!!" << endl;
  return 0;
}

//Name:   readInt(string prompt)
//Desc:   This function reads an int, validates and returns it
//input:  None
//output: Maybe error message
//return: int tempVar
void readInt(char prompt[], int &num)
{
  cout << prompt;
  cin >> num;
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

//multiline comments here
//validate that ID is > 0 as an example
bool validNum(char prompt[], int &tempNum)
{
  while(tempNum <= 0)
  {
    cout << "Invalid number!! Please try again!!" << endl;
    readInt(prompt, tempNum);
  }
  return true;
}

//multiline comments here
//use a sentinel of 99999 to end reading input
void readInput(int empId[], int salary[], int &count)
{
  int tempId = 0, tempSal = 0;
  char prompt[MAXCHAR] = {0};
  strcpy(prompt, "Enter Employee ID: ");
  readInt(prompt, tempId);
  validNum(prompt, tempId);
  while(tempId != 99999)
  {
    empId[count] = tempId;
    strcpy(prompt, "Enter Employee Salary: ");
    readInt(prompt, tempSal);
    validNum(prompt, tempSal);
    salary[count] = tempSal;
    count++;
    strcpy(prompt, "Enter Employee ID: ");
    readInt(prompt, tempId);
    validNum(prompt, tempId);
  }
}

//multiline comments here
//print without raise
void printData(int empId[], int salary[], int count)
{
  cout << endl;
  for(int i = 0; i < count; i++)
    {
      cout << empId[i] << ";" << salary[i] << endl;
    }
  cout << endl;
}

//multiline comments here
//print with raise
void printData(int empId[], int salary[], double raise[], int count)
{
  cout << endl;
  for(int i = 0; i < count; i++)
    {
      cout << fixed << showpoint << setprecision(1);
      cout << empId[i] << ";" << salary[i] << ";"
           << raise[i]*100 << "%" << endl;
    }
  cout << endl;
}

//multiline comments here
void calcRaise(int empId[], int salary[], double raise[], int count)
{
  for(int i = 0; i < count; i++)
  {
    if(salary[i] < 1000)
    {
      raise[i] = .015;
    }
    else if(salary[i] >= 1000 && salary[i] < 5000)
    {
      raise[i] = 0.02;
    }
    else if(salary[i] >= 5000 && salary[i] < 10000)
    {
      raise[i] = 0.02;
    }
    else if(salary[i] >= 10000)
    {
      raise[i] = 0.035;
    }
    else
    {
      raise[i] = 0;
    }
  }
}

void welcome()
{
  cout << "Welcome to my Parallel Arrays Employee Program!" << endl;
}
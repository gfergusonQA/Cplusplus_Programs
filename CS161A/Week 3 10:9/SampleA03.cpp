/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A03 Sample (CS161A)
# Date:             March 30, 2022
# Description:      This program will read the number of chickens in 2 coops 
#                   (integer) and calculate the average number of chickens per coop
#                   (double).
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 3 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

//constants
//constant for number of coops
const int NUM_COOPS = 2;

//main function
int main() 
{
  //variables declared for average chickens calculations
  int numChicks1 = 0;
  int numChicks2 = 0;
  int totalChicks = 0;
  double avgChicks = 0;

  //user input
  cout << "Enter the number of chickens in coop 1: ";
  cin >> numChicks1;
  cout << "Enter the number of chickens in coop 2: ";
  cin >> numChicks2;

  //calculations
  totalChicks = numChicks1 + numChicks2;
  avgChicks = static_cast<double>(totalChicks) / NUM_COOPS;

  //output to the user
  //set fixed and showpoint with precision set to 1 decimal place
  cout << fixed << showpoint << setprecision(1);
  cout << "You have a total of " << totalChicks << " chickens!" << endl;
  cout << "The average number of chickens per coop = " <<  avgChicks << endl;
  cout << "Thank you for using my program!" << endl;
  //end program
  return 0;
}
/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A03 (CS161A)
# Date:             October 18, 2023
# Description:      This program will read the calories in a user's Oreo Cookie serving for the company Oreo Cookies and their website. 
#(integer) and calculate the number of calories
#                   (double).
# Input:            User enters the number of whole Oreo cookies eaten (integer)
# Output:           Calculate amount of servings eaten (double), and the number of calories consumed (double)
# Sources:          Assignment 3 specifications, and Zybooks notes/practice
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

//constants
const int COOKIES_PER_SERVING = 5;
const int CALORIES_PER_SERVING = 160;

int main() 
{
  int numCookies = 0;
  double numCalories = 0;
  double numServings = 0;

  cout << "Welcome to Oreo Cookie’s Calorie and Serving Calculator!" << endl;
  cout << "Enter the number of Oreo Cookies using a whole number: " << endl;
  
  // user input 12
  cin >> numCookies;

  // calculations
  numServings = static_cast<double>(numCookies) / COOKIES_PER_SERVING;
  numCalories = numServings * CALORIES_PER_SERVING;
  
  // output
  cout << fixed << setprecision(1) << showpoint;
  cout << "With " << static_cast<double>(numCookies) << " cookies, you will have " << numServings << " servings and " << numCalories << " calories. Happy snacking!" << endl;
  
  cout << setw(25) << left << (setfill('-')) << "-" << endl;
  cout << "Oreo Cookie Amount: " << static_cast<double>(numCookies) << endl;
  cout << "Oreo Cookie Servings: " << numServings << endl;
  cout << "Oreo Cookie Calories: " << numCalories << endl;
  cout << setw(25) << left << (setfill('-')) << "-" << endl;

  cout << "Thank you for using the Oreo Cookie Calorie and Serving Calculator program!" << endl;

  return 0;
}
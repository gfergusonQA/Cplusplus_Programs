/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A02 Sample (CS161A)
# Date:             March 29, 2022
# Description:      This program will read the principal amount, rate, and period #                   in years and calculate Simple Interest for the user.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 1 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

//main function
int main() {
  //variables declared for simple interest calculations
  float principal = 0;
  float rate = 0;
  float interest = 0;
  float totalAmount = 0;
  int period = 0;

  //user input
  cout << "Enter the principal amount: $";
  cin >> principal;
  cout << "Enter the rate in percentage and period in years separated by space: ";
  cin >> rate >> period;

  //calculations
  interest = principal * (1 +((rate / 100) * period)) - principal;
  totalAmount = principal + interest;

  //output to the user
  //set fixed and showpoint with 2 precision set to 2 decimal places
  cout << fixed << showpoint << setprecision(2);
  cout << "Your interest accrued is $" << interest << endl;
  cout << "Your total amount with interest is $" << totalAmount << endl;

  //end program
  return 0;
}
/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A02 Sample (CS161A)
# Date:             October 8, 2023
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
  int employeeId;
  int hoursWorked;
  double hourlyRate;
  double federalWithholdingRate = 0.15;
  double totalGrossPay;
  const double FICADEDUCT = 7.65;

  cout << "Welcome to Gina's Weekly Payroll program..." << endl;
  //user input
  cout << "Please enter your employee number (numbers only): ";
  cin >> employeeId;
  cout << "Please enter number of hours worked (whole numbers): ";
  cin >> hoursWorked;
  cout << "Please enter the hourly rate: ";
  cin >> hourlyRate;

  //calculations
  totalGrossPay = hoursWorked * hourlyRate;
  double ficaDeduction = totalGrossPay * FICADEDUCT / 100;
  double federalTaxWithholding = totalGrossPay * federalWithholdingRate;
  double totalDeductions = ficaDeduction + federalTaxWithholding;
  double netPay = totalGrossPay - totalDeductions;
  
  //output
  cout << fixed << setprecision(2);
  cout << "\nYour Payroll Summary:" << endl;
  cout << "Total Gross Pay: $" << totalGrossPay << endl;
  cout << "FICA deductions: $" << ficaDeduction << endl;
  cout << "Federal Tax Withholding: $" << federalTaxWithholding << endl;
  cout << "Total deductions: $" << totalDeductions << endl;
  cout << "Net Pay: $" << netPay << endl;
  cout << "\nThank you for using my Weekly Payroll program!!" << endl;

  //end program
  return 0;
}
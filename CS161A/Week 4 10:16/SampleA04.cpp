/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A04 Sample (CS161A)
# Date:             March 30, 2022
# Description:      This program will give the user a choice of Stocks or Bonds and will calculate the commission based on conditions. The program will read the number of stocks or bonds and the stock price or the bond price from the user, calculate the total stock (or bond) price, and the commission. The commission percentage for Stocks and Bonds are set as two separate constants. If the commission for Stocks is over $3000.00, then the commission is capped at $3000.00. There is no limit to the commission on Bonds.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 4 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

//constants
//constant for commissions and CAP
const double ST_COMM = 0.05;
const double BD_COMM = 0.02;
const double ST_CAP = 3000.00;

//main function
int main() 
{
  //variables declared for commission calculations
  char choice = ' ';
  int numShare = 0;
  double price = 0;
  double shareCost = 0, commPercent = 0, commission = 0;
  double totalCost = 0;

  //user input
  cout << "Would you like to calculate commission for: ";
  cout << "(s) Stocks" << endl;
  cout << "(b) Bonds" << endl;
  cout << ">>";
  cin >> choice;
  //convert choice to lowercase for easy condition check
  choice = tolower(choice);
  //conditions to check if choice is not s or b
  //choice validation
  if (choice != 's' && choice != 'b')
  {
    cout << "Invalid option!! Please try again later!!!" << endl;
  }
  //if it is s or b, then do the following
  else
  {
    if (choice == 's')  //if choice is stocks
    {
      cout << "Enter the number of stocks: ";
      cin >> numShare;
      cout << "Enter the price of each stock: $";
      cin >> price;
      commPercent = ST_COMM;
    }                //end if choice is stocks
    else if (choice == 'b')  //if choice is bonds
    {
      cout << "Enter the number of bonds: ";
      cin >> numShare;
      cout << "Enter the price of each bond: $";
      cin >> price;
      commPercent = BD_COMM;
    }              //end if choice is bonds
      //now do all the calculations
    shareCost = numShare * price;
    commission = shareCost * commPercent;
    //do this if it is stocks and if the commission is >= $3000
    if (choice == 's' && commission >= ST_CAP)
    {
      commission = ST_CAP;
    }
    //else don't do anything.
    //calculate the totalCost for stocks or bonds
    totalCost = shareCost + commission;
  
    //output information to the user
    //set fixed and showpoint with precision set to 2 decimal places
    cout << fixed << showpoint << setprecision(2);
    cout << "Amount paid for stock = $" << shareCost << endl;
    cout << "Amount of commission paid = $" <<  commission << endl;
    cout << "Total amount paid = $" << totalCost << "\n" << endl;
    cout << "Thank you for using my program!" << endl;
  }            //end else for choice
  
  //end program
  return 0;
}
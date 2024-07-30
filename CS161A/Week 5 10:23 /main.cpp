/******************************************************************************
# Author:           Corinne Fargo & Gina Ferguson
# Assignment:       D05 (CS161A)
# Date:             October 28, 2023
# Description:      This program will generate a login handle for the user, 
                    based on three pieces of user input: first name, last name, 
                    and an integer. The final login handle will be the first 
                    five letters of the last name, then the first letter of the 
                    first name, then the last two digits of the integer. If the 
                    last name is less than five letters long, the entire last 
                    name will be used without fulfilling the five letter 
                    requirement.
# Input:            firstName, lastName, userNum
# Output:           userID
# Sources:          Discussion 5 aids & Zybooks
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
// input integers
string firstName;
string lastName;
int userNum;
string userID;

cout << "What is your first name, last name, and an integer (separate each " 
        "with a space)?" << endl;
cin >> firstName >> lastName >> userNum;
  
lastName = lastName.substr(0,5);

if (lastName.size() < 5) {
  lastName = lastName.substr(0, lastName.size());
}
  
firstName = firstName.substr(0,1);

  
userNum = userNum % 100;
string sUserName = to_string(userNum);

userID = lastName + firstName + sUserName;
  
cout << "Your username is: " << userID << endl;
  
return 0;
}
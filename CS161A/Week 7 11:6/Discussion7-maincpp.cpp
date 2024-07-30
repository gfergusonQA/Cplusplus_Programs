/******************************************************************************
# Author:           Gina Ferguson & Corinne Fargo
# Lab:              Discussion 7
# Date:             November 15, 2023
# Description:       This program is a palindrome detector. Take an input and
check whether it is the same backwards and forwards (ignoring spaces and 
capitalization). It will then output a response as either yes a palindrome, 
or not a palindrome.
# Input:            
# Output:           
# Sources:          Discussion 7 prompt, Zybooks
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string userString;
  string copy;
  bool isPal = false;
  int spaceIndex = 0;
  int length = 0;

  cout << "Type in a word or phrase: ";
  getline(cin, userString);
  cout << endl;

  copy = userString;

  // Remove any spaces, by finding and replacing " " with ""
  while (userString.find(" ") != string::npos) {
    spaceIndex = userString.find(" ");
    userString.replace(spaceIndex, 1, "");
  }

  length = userString.size();

  // Make everything lowercase
  for (int i = 0; i < length; i++) {
    userString.at(i) = tolower(userString.at(i));
  }
  cout << endl;

  // Check if userString is a palindrome
  for (int i = 1; i <= length; i++) {
    if (userString.at(i - 1) == userString.at(length - i)) {
      isPal = true;
    } else {
      isPal = false;
    }
  }

  // Detect if bool variable is true or false, given the input
  if (isPal) {
    cout << copy << " is a palindrome!" << endl;
  } else {
    cout << copy << " is NOT a palindrome!" << endl;
  }

  return 0;
}
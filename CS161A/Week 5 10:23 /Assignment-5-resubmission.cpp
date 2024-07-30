/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A05 Phrase Scrambler (CS161A)
# Date:             November 7, 2023
# Description:      This program will collect 2 phrases and scramble them in a 
                    certain way.
# Input:            string phrase1, string phrase2
# Output:           See algorithmic design doc
                    
# Sources:          Assignment 5 specifications, Zybooks, and C++ website
#     
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <string>
using namespace std;

int main() {
  string phrase1= " ";
  string phrase2 = " ";
  size_t position;

  cout << "Welcome to Gina's Phrase Scrambler!" << endl;
  cout << "\n";
  cout << "We are going to scramble 2 phrases for you!"
    " Please enter phrase 1: " << endl;
  getline(cin, phrase1);
  cout << "You entered: " << phrase1 << endl;
  cout << "\n";
  
  cout << "Please enter phrase 2: " << endl;
  getline(cin, phrase2);
  cout << "You entered: " << phrase2 << endl;
  cout << "\n";

  // Check for equality first
  if (phrase1 == phrase2) {
    cout << "Both phrases match" << endl;
  } else {
  // check if phrase 1 is found within phrase 2
    position = phrase2.find(phrase1);
    if (position != string::npos) {
      cout << phrase1 << " is found in " << phrase2 << endl;
      cout << phrase2.substr(position) << endl;
    } else {
      // Check if phrase 2 is found within phrase 1
        position = phrase1.find(phrase2);
        if (position != string::npos) {
         cout << phrase2 << " is found in " << phrase1 << endl;
         cout << phrase1.substr(position) << endl;
       } else {
        cout << "No match" << endl;
      }
    }
  }
  cout << "\n";
  cout << "Thank you for using Gina's Phrase Scrambler! Have"      
  " a great day!" << endl;
    
  return 0;
}
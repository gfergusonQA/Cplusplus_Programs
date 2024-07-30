/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A05 Sample (CS161A)
# Date:             March 30, 2022
# Description:      This program will read one String separated by : from the user, and break it down into 3 strings. For example, if the user enters apple:banana:water melon, it should print apple, banana and water melon on 3 separate lines.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 5 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  //user defined variables for Strings and indices
  string userText = " ";
  string userMsg1 = " ";
  string userMsg2 = " ";
  string userMsg3 = " ";
  string tmpStr = " ";
  //int variables for index,
  int index1 = 0;
  int index2 = 0;

  //welcome message
  cout << "Welcome to my Strings program!!" << endl;
  cout << "If you enter a string like this:" << endl;
  cout << "apple is red:banana is yellow:watermelon is also red" << endl;
  cout << "I will print the 3 strings on separate lines. " << endl;
  cout << "My program is limited:) You can only enter 3 sections separated by 2 colons (:)." << endl;
  //read input from the user. Use cin.getline() to read strings separated by space.
  cout << "Please enter a string separated by \":\"" << endl;
  getline(cin, userText);    //use getline to read string with spaces
  //get the position of ':'
  index1 = userText.find(':');
  //if the position is a null position (meaning there is no : in the string)
  //output an error message
  if(index1 == string::npos)
  {
    cout << "String is missing \":\" that is required!" << endl;
  }    //end if for ':' not found
  //if ':' is found the do the following
  else
  {
    //Get the first part of the string till index1
    userMsg1 = userText.substr(0, index1);
    //store the rest of the string from index1 in a temp string
    tmpStr = userText.substr(index1+1);
    //use that and index2 to find the next ':'
    index2 = tmpStr.find(':');
    //get the second part of the string using the 2 indices
    //You can do this a couple of other ways using tmpStr as well.
    //try this program in a different way
    userMsg2 = userText.substr(index1+1, index2);
    //find the last ':' from the temp string
    index2 = tmpStr.find(':');
    //get the last part using index2
    userMsg3 = tmpStr.substr(index2+1);

    //print the 3 strings to the user
    cout << "Here are your 3 strings: " << endl;
    cout << "String 1: " << userMsg1 << endl;
    cout << "String 2: " << userMsg2 << endl;
    cout << "String 3: " << userMsg3 << endl;
  }    //end else for if ':' not found
  cout << "Thank you for using my program!" << endl;
  return 0;
}
    
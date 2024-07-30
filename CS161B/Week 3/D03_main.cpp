// /******************************************************************************
// # Author:           Josh H., Idris L., Gina F., Thien B.
// # Assignment:       Discussion 3
// # Date:             Monday 1/25/2024
// # Description:      This program reads a list of integers from input into an array and outputs "yes" if the list is sorted in ascending order between two provided positions. Otherwise, output "no". The first input specifies the number of items in the list. The next set of inputs is the list. The last two inputs are the start and end positions (inclusive, between 0 and count where count is the number of values in the array). Assume the list contains no more than 20 integers and position 0 is the first element. 
// # Input:            numberOfIntegers (int), userNum(int) start (int), end (int)
// # Output:           Ascending(int userNum[], int start, int end)
// # Sources:          Zybooks Chapter 11, and class notes/examples
// #*****************************************************************************

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int CAP = 20;

bool Ascending(int userNum[], int start, int end);

int main() {
  // variable declarations
  int numberOfIntegers;
  int userNum[CAP];
  int start;
  int end;

  // cout << "Initiating section 1" << endl;
  cout << "Number of integers: ";
  cin >>  numberOfIntegers;

  // cout << "Initiating section 2" << endl;
  cout << "Enter integer: ";
  for (int j = 0; j < numberOfIntegers; j++) {
    // create an array, each iteration adds to that array
    cin >> userNum[j];
  }

  cout << "Enter start and end index: ";
  cin >> start >> end;

  //cout << "Initiating section 3" << endl;

  // check if the start and end are in ascending order
  if (Ascending(userNum, start, end)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}

//Name:   Ascending()
//Desc:   This boolean function reads the user's #, and the start and end index of the list of numbers by using a for loop and if statement to make sure the list is in ascending order.
//input:  int userNum[], int start, int end
//output: Ascending() ? 
//return: true or false

bool Ascending(int userNum[], int start, int end) {
  for (int i = start; i < end; i++) {
    if (userNum[i] > userNum[i + 1]) {
      return false;
    }
  }
  return true;
}
 /*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 1
# Date:             09/20/23
# Description:      Example:  Ask for a length. Then calculate
#                      The area of a square.
# Input:            None
# Output:           The area of a square.
# Sources:          None
#*****************************************************************************/

#include <iostream>

using namespace std;

// main: Ask for length, calculate area of a square and print it.
//    -parameters: none
//    -return: 0 for sucessful completion 
//
int main() {
  int side;
  int area;
  
  cout << "*** Area of a square app ***" << endl;
  cout << "Enter side length: ";
  cin >> side;
  
  area = side*side;
  
  cout << "The area is: " << area << endl;
  
  return 0;
}

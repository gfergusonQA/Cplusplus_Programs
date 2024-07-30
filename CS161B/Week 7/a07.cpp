/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A07 - Pointers are fun!
# Date:             03/14/24
# Description:      This program asks the user for 2 input integers, then
#                   manipulates these numbers (dereferences) through a series of 
#                   functions that swap their values, divide them to find the 
#                   quotient and remainder, and raise the first number to the 
#                   power of the 2nd
# Input:            a (int): The first integer input by the user.
#                   b (int): The second integer input by the user.
#                   swapArgs(int*, int*): Swaps the values of the two 
#                   integer pointers.
#                   divideArgs(int*, int*): Calculates the quotient and 
#                   remainder of the first integer divided by the second, 
#                   updating the first integer to the quotient and the 
#                   second to the remainder.
#                   powerArgs(int*, int*): Raises the first integer to the 
#                   power of the second integer and stores the result in the 
#                   first integer.
# Output:           There are outputs of the values swapping etc
# Sources:          Zybooks & Shawli's notes
#******************************************************************************/
#include <iostream>

using namespace std;

// FUNCTION PROTOTYPES
void swapArgs(int *a, int *b);
void divideArgs(int *a, int *b);
void powerArgs(int *a, int *b);

int main() {
  int a = 0;
  int b = 0;

  cout << "Enter integer 1: ";
  cin >> a;
  cout << "Enter integer 2: ";
  cin >> b;

  // if a or b are 0, print out error message and quit program
  if (a == 0 && b == 0) {
    cout << "\nNo operations performed!\n";
    return 0;
  }

  
  cout << "\nBefore call to swapArgs a: " << a << " b: " << b << endl;
  // swap values of the 2 integer pointers
  swapArgs(&a, &b);
  cout << "After call to swapArgs a: " << a << " b: " << b << endl;

  // calcs quotient and remainder of a divided by b, updating the first
  // integer to the quotient and the second to the remainder
  divideArgs(&a, &b);
  cout << "After call to divideArgs a: " << a << " b: " << b << endl;

  // raises a to the power of b and stores the result in a
  powerArgs(&a, &b);
  cout << "After call to powerArgs a: " << a << " b: " << b << endl;

  cout << "\nGoodbye!\n";
  return 0;
}

// ---- FUNCTION DEFINITIONS BELOW ------
//Name: swapArgs(int *a, int *b)  
//Desc: This function swaps the pointers for variables a & b  
//input: *a & *b & temp (int)
//output: *b & *a & temp (int)
//return: none (void)
void swapArgs(int *a, int *b) {
  int temp = 0;
  
  temp = *a;
  *a = *b;
  *b = temp;
}

//Name:   divideArgs(int *a, int *b)
//Desc:   This function divides the arguments if *b is not 0
//        then turns *a into quotient and *b into the remainder
//input:  *a & *b
//output: *a (as tempQuotient) and *b (as tempRemainder)
//return: none (void)
void divideArgs(int *a, int *b) {
  int tempQuotient = 0;
  int tempRemainder = 0;
  
  if (*b != 0) {
    tempQuotient = *a / *b;
    tempRemainder = *a % *b;
    *a = tempQuotient;
    *b = tempRemainder;
  }
}

//Name:   powerArgs(int *a, int *b)
//Desc:   This function does nothing if the power is negative
//        but if power is 0 the output is 1, and then runs a
//        for loop in order to raises the first integer to the
//        power of the second integer & updates accordingly
//input:  *a & *b & result (integer)
//output: *a, result
//return: none (void)
void powerArgs(int *a, int *b) {
  int i = 0;
  int result = 0;
  
  if (*b < 0) {
    // power must be non-negative
    return;
  } else if (*b == 0) {
    // Any number to the power of 0 is 1.
    *a = 1;
  } else {
    result = 1;
    for (i = 0; i < *b; i++) {
      result *= *a;
    }
    *a = result;
  }
}



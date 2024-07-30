/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 2
# Date:             09/20/23
# Description:      Asks user for two numbers.  Does various 
#                     math with the values
# Input:            two numbers
# Output:           various results
# Sources:          none
#*****************************************************************************/

#include <iostream>
#include <cmath>  // for pow() function 
 
using namespace std;

// main:  See above
//    -parameters: none
//    -return: 0 for sucessful completion 
//
int main() 
{ 
	// good practice is to initialize your numberic 
	// variables to zero when you declared them.  
	// Some compilers wont do this for you.
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    int product = 0;
    int quotient = 0;
    int difference = 0;
    
    cout << "*** Math 1 App ***" << endl;
    
    // get the two numbers (note: the user can type them 
    // on the same line with a space between OR on two
    // separate lines).
    cout << "type two numbers: ";
    cin >> num1 >> num2;  // yes you can do this
    
    //add two numbers
    sum = num1 + num2;
    //subtract two numbers
    difference = num1 - num2;
    //multiply two numbers
    product = num1 * num2;
    //divide one number into the other
    // (try and see what happens when num2 is 0)
    quotient = num1 / num2;
        
    //print out results
    cout << num1 << " + " << num2 << " = " << sum << endl;
    cout << num1 << " - " << num2 << " = " << difference << endl;
    cout << num1 << " * " << num2 << " = " << product << endl;
    cout << num1 << " / " << num2 << " = " << quotient << endl;
    
    return 0; 
}

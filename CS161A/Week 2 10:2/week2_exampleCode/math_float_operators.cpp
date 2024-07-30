/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 2
# Date:             09/20/23
# Description:      Asks user for two numbers.  Does various 
#                     math with the values.
# Input:            two numbers
# Output:           various results
# Sources:          none
#*****************************************************************************/

#include <iostream>
#include <iomanip>  // this for setprecision and fixed
 
using namespace std;

// main:  See above
//    -parameters: none
//    -return: 0 for sucessful completion 
//
int main() 
{ 
	// a 'double' has twice the number of decimal places
	// as a 'float' type.  Doubles are the standard type
	// for floating point numbers.
	//   Use 0.0, 1.0 and so on for assigning a whole literal
	//   to a floating point. 
    double num1 = 0.0;
    double num2 = 0.0;
    double num3 = 0.0;
    double result1 = 0.0;
    double result2 = 0.0;
    double result3 = 14.0;
    double result4 = 7.0;
    
    cout << "*** Math 1 App ***" << endl;
   
    // uncomment this line and try changing setprecision number 
    // to see the effects.  
    // The two iomanipulators only need to be done once before
    // printing any values.  The 'fixed' combined with the 
    // setprecision(n) will always print the n digits after the 
    // decimal point.
    
    cout << setprecision(2) << fixed;  // use this for currency
    
    // get the two numbers (note: the user can type them 
    // on the same line with a space between OR on two
    // separate lines).
    cout << "type three numbers: ";
    cin >> num1 >> num2 >> num3;
    
    //no parenthesis
    result1 = num1 + num2 * num3;
    //with parenthesis
    result2 = (num1 + num2) * num3;
    //compound operator:  equivalent to result3 = result3 / 5.0
    // note: try changing the 5.0 to 0.0 and see what is result3 is
    result3 /= 5.0;
    //another compound example
    // this is the same as:  result4 = result4 * result3 - (result2 + result1)
    result4 *= result3 - (result2 + result1);
        
    
    //print out results
    cout << "result1 is: " << result1 << endl;
    cout << "result2 is: " << result2 << endl;
    cout << "result3 is: " << result3 << endl;
    cout << "result4 is: " << result4 << endl;
    
    return 0; 
}

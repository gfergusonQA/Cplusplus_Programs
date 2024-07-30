
/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 3
# Date:             09/20/23
# Description:      this runs through many useful
#                   math operators and some cmath
#                   functions
# Input:            two floating point numbers
# Output:           Results from various math functions
# Sources:          none
#
#*****************************************************************************/



#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double number1 = 0.0;
    double number2 = 0.0;
    int num1 = 0.0;
    int num2 = 0.0;
    double ans = 0.0;
    
    // using cmath library
    
    cout << "Enter two numbers: " << endl;
    cin >> number1 >> number2;
   
    // modulo doesn't take floating point
    // so I'm typecasting to int
    // the modulo gives the remainder of
    // dividing the first number by the
    // second number. For example:
    //     7 % 3 = 1 because after dividing
    //       by 3 you get 6 with 1 left over.
    // the modulo is always less than the
    //   second number so it can be used
    //   to limit numbers to a range.
    num1 = static_cast<int> (number1);
    num2 = static_cast<int> (number2);
    ans = num1 % num2;
    cout << num1 << " % " << num2
         << " = " << ans << endl;
    
    // this is number1 taken to the power of number2
    // number2 needs to be a whole number, otherwise 
    // you get 'nan' which is 'not a number'. 
    ans = pow(number1, number2);
    cout << number1 << " ^ " << number2
         << " = " << ans << endl;
      
    // this is floating point verison of 'abs'. 
    // it switches the sign to positive on number1.   
    ans = fabs(number1);
    cout << "absolute value of " << number1
         << " is " << ans << endl;

    // this takes the square root of number2
    // if number2 is negative, it will return a
    // 'nan' value
    ans = sqrt(number2);
    cout << "the square root of " << number2
         << " is " << ans << endl;
    
    
    return 0;
}

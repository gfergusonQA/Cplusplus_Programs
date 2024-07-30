
/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 3
# Date:             09/23/23
# Description:      examples of mixed floats and integers in 
#                   arithmetic expressions
#                   and using typecasting
# Input:            none
# Output:           various mixed expression results
# Sources:          none
#
#*****************************************************************************/


 
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intNum1 = 5, intNum2 = 2;
    double floatNum1 = 5.0, floatNum2 = 2.0;
    int intAns = 0;
    double floatAns = 0;
    
    // mixed expressions and results:
    
    // two ints will always result in
    // truncation (the decimal part
    // being removed) even if you 
    // put them in a double.
    floatAns = intNum1 / intNum2;
    cout << "division with two ints: " << floatAns << endl;
    
    // note that if one of the two
    // numbers is a floating point
    // (double or float) there is
    // no truncation. 
    floatAns = floatNum1 / intNum2;
    cout << "division with one float and one int: " << floatAns << endl;
    
    // two floating point numbers always
    // gives a floating point number.
    floatAns = floatNum1 / floatNum2;
    cout << "division with two floats " << endl
         << "with the results stored in a float: " << floatAns << endl;
    
    // here the division results in a
    // floating point number but since
    // it needs to store this in a 
    // integer it truncates the result
    intAns = floatNum1 / floatNum2;
    cout << "division with two floats " << endl
         << "with the results stored in an int: " << intAns << endl;
    
    // using typecasting to change the
    // type to another
    floatAns = static_cast<double> (intNum1) / intNum2;
    cout << "using C++ static typecasting: " << floatAns << endl;
    
    // older C type casting (or C++ earlier than 2011)
    floatAns = (double) intNum1 / intNum2;
    cout << "using older C style typecasting: " << floatAns << endl;
    
    
    return 0;
}

/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      shows the use of many types 
#                      of relational operators.
# Input:            a number
# Output:           the relationships of the number with other numbers.
# Sources:          none
#
#*****************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    // relational operators
    if(number == 10)  // ==   is equal to
    {
        cout << "This number is 10." << endl;
    }
    
    if(number != 1)  //  !=  is not equal to
    {
        cout << "This number is NOT equal to 1" << endl;
    }
    
    
    if(number > 2) // > is (strictly) larger than (doesn't include 2)
    {
        cout << number << " is larger than 2." << endl;
    }
    
    if(number >= 2) // > is larger than or equal to (does include 2)
    {
        cout << number << " is larger than or equal to 2." << endl;
    }
    
    if(number < 4) // > is (strictly) smaller than (does NOT include 4)
    {
        cout << number << " is smaller than 4." << endl;
    }
    
    if(number <= 4) // > is smaller than or equal to (does include 4)
    {
        cout << number << " is smaller than or equal to 4." << endl;
    }
    
    return 0;
}

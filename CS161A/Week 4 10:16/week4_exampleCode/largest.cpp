/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      find largest of three numbers.
#                     This illustrates three methods of getting
#                     the largest number amoung 3 numbers.
# Input:            three numbers
# Output:           the largest of the three
# Sources:          none
#
#*****************************************************************************/


#include <iostream>


using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int max = 0;
    
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    
    
    // using if/else statements
    if(num1 > num2) {
        
        if(num1 > num3) {
           max = num1;
        }
        else {
           max = num3;
        }
    }
    else {  // num 2 > num1
        
        if(num2 > num3) {
            max = num2;
        }
        else {
            max = num3;
        }
    }
    
    cout << "+++ METHOD 1+++" << endl;
    cout << max << " is the largest number." << endl;
    
    // using straight if statements and a compound
    // conditional with logical operators (&& and ||)
    
    if( (num1 > num2) && (num1 > num3) ) {
        max = num1;
    }
    else if ( (num2 > num1) && (num2 > num3) ) {
        max = num2;
    }
    else { // num1 and num2 are not so num3 is our only choice
    
        max = num3;
    }
    
    cout << "+++ METHOD 2+++" << endl;
    cout << max << " is the largest number." << endl;
    
    // this method is a good one. Only takes two conditionals.
    // later, you will see how to expand this to find a maximum
    // in to any amount of numbers using a loop.
    
    max = num1; //assume this is the max
    
    if(max < num2) { 
        // now we know that max wasn't right. so set it to the new
        // assumed max of num2 (since it is larger it may be max
        // or not).
        max = num2;
    }
    
    if(max < num3) {
        // again, max isn't correct. So set it to num3.
        max = num3;
    }
    
    cout << "+++ METHOD 3+++" << endl;
    cout << max << " is the largest number." << endl;
    
    
    return 0;
}

 /*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      Shows the use of compound conditionals
#                     checks to see if the given number
#                     is between 10 and 50 or NOT between
#                     10 and 50.
# Input:            a number
# Output:           whether or not between 10 and 50
# Sources:          none
#
#*****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int number = 0;
    
    cout << "Enter number:";
    cin >> number;
    
    // for checking between 10 and 50
    // inclusively (include 10 and 50)
    // need to use AND here as both conditionals 
    // need to be true
    if(number >= 10 && number <= 50)
    {
        cout << number << " Is between 10 and 50 "
             << "(including 10 and 50)" << endl;
             
    }
    
    // for checking between 10 and 50 exclusively
    //   (not include 10 and 50)
    if(number > 10 && number < 50)
    {
        cout << number << " Is between 10 and 50 "
             << "(NOT including 10 and 50)" << endl;
    }
    
    // for checking if NOT between 10 and 50 inclusively
    //   (include 10 and 50)
    // note that you need to use || as it's not possible for
    // both conditionals to be true
    if (number <= 10 || number >= 50)
    {
        cout << number << " Is NOT between 10 and 50 "
             << "(NOT including 10 and 50)" << endl;
    }
    //for checking of NOT between 10 and 50 exclusively 
    // (not include 10 and 50)
    if(number < 10 || number > 50)
    {
        cout << number << " Is NOT between 10 and 50 "
             << "(NOT including 10 and 50)" << endl;
    }
    
    //for inverting a complex set of conditionals, use the !
    // in front of the whole thing
    
    // Note that it is best to put the entire compound statement
    // in paranthesis to make it clear that the whole thing is
    // be inverted (or negated).
    if(!(number < 10 || number > 50))
    {
        cout << number << " Is between 10 and 50 "
             << "(including 10 and 50)" << endl;
    }
    
    
    
    return 0;
}

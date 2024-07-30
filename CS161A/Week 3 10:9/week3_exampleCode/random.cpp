/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 3
# Date:             09/23/23
# Description:      using rand() function
#                   in the C standard lib. 
#                   to print out 3 random numbers.    
# Input:            none
# Output:           3 random numbers
# Sources:          none
#
#*****************************************************************************/


#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for time function

using namespace std;

int main()
{
    
    int from=0, to=0;
    int sizeOfRange=0;
    int number=0;
    
    // this is needed to get a
    // different set of random
    // values each time the 
    // rand() is called.
    srand(time(0));
    
    cout << " enter a range (from to)" << endl;
    cin >> from >> to;
    
    cout << " I will now generate three random"
         << " numbers between " << from 
         << " and " << to << endl;
         
    // this will include end points
    sizeOfRange = to - from + 1;

    number = (rand() % sizeOfRange) + from;
    cout << number << endl;
    
    number = (rand() % sizeOfRange) + from;
    cout << number << endl;
    
    number = (rand() % sizeOfRange) + from;
    cout << number << endl;
 
    return 0;   
}

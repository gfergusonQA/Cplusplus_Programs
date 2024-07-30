
/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 2
# Date:             03/08/22
# Description:      Calculate the equivalent dog years for a given 
#                      human's age. 
#                      uses the formula:
#                             dogyears = 7 x humanyears
# Input:            name and age of human
# Output:           Equivalent age of dog in human years.
# Sources:          none
#
#*****************************************************************************/


#include <iostream>
 
using namespace std;

int main() 
{ 
    string name = ""; 
    int age = 0;
    int dogYears = 0;
    
    // print out prompt
    cout << "What is your name? ";
    // get user's name (this is typed in from the keyboard)
    // NOTE: this won't work if the user types any spaces
    cin >> name;
    
    // print out prompt and ask user for age
    cout << "What is your age in years? ";
    cin >> age;
    
    // set dogYears to 7 times the given age
    // NOTE: 7 should be a constant.
    dogYears = 7*age;
    
    // print out all information
    cout << "Well, " << name;
    cout << ", you might be " << age << " years old." << endl;
    cout << "But if you were a dog, you would be " << dogYears;
    cout << " years old!" << endl;
    
    
    return 0; 
}

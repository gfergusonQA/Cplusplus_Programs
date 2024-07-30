/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      Asks user for a favorite animal.
#                     prints out a message when the
#                     animal is a cat.
# Input:            animal as string
# Output:           goodbye message or if ansimal is cat,
#                      more elaborate message
# Sources:          none
#
#*****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string animal;
    
    //ask for animal
    cout << "enter favorite animal:";
    getline(cin, animal);   // use getline in case animal name has spaces
    
    // print out favorite animal
    cout << "your favorite animal is " << animal << endl << endl;
    
    // check to see if the favorite animal is a cat
    if(animal == "cat") {
		// these lines inside the { } will only run
		// if the above is true
        cout << "that's my favorite animal!" << endl;
        cout << "    ^     ^" << endl;
        cout << "  >>(o v o)<<" << endl << endl;
    }
    
    // this will print out whether the animal is a cat or not.
    cout << "Goodbye!" << endl;
    return 0;
}

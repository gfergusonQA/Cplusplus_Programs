/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      Asks user for a favorite animal.
#                     prints out a message when the
#                     animal is a cat.
#                     if not a cat, prints out another message
# Input:            animal as string
# Output:           different message depending on what the animal is
# Sources:          none
#
#*****************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string animal;

    cout << "enter favorite animal:";
    getline(cin, animal);
    cout << "your favorite animal is " << animal << endl << endl;
    
    // this has an else clause which will run when the conditional
    // is false (when animal is not a cat).
    if(animal == "cat") {
		// runs when conditional (animal == "cat") is true
        cout << "that's my favorite animal!" << endl;
        cout << "    ^     ^" << endl;
        cout << "  >>(o v o)<<" << endl << endl;
    }
    else { 
		// runs when conditional (animal == "cat") is false
        cout << "That's not my favorite but an OK animal" << endl << endl;
    }  
      
    cout << "Goodbye!" << endl;
    
    return 0;
}

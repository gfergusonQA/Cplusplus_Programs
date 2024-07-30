/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      Asks user for a favorite animal.
#                     nested if/else statement
#                     prints a message for cat, snake and horse
#                     and will print a message for any other animal
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
    
    if(animal == "cat") {
        cout << "that's my favorite animal!" << endl;
        cout << "    ^     ^" << endl;
        cout << "  >>(o v o)<<" << endl << endl;
    }
    else if(animal == "snake") {
        cout << "Ewww! I hate snakes!" << endl << endl;
        cout << "   mmmmmmm(o..o)~~" << endl << endl;
    }
    else if(animal == "horse") {
        cout << "There not my favorite animal but I like horses" << endl << endl;
    }
    else /* everything else that isn't a cat, snake or horse */ {
        cout << "That's not my favorite but an OK animal" << endl << endl;
    }
        
    cout << "Goodbye!" << endl;
    
    return 0;
}

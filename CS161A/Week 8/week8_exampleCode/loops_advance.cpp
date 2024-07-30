/* week 8 - advance loop examples
 * examples of using break and continue,
 * and stepping through strings
 * 
 */

#include <iostream>
#include <cctype>  // for isspace function

using namespace std;

int main() 
{

    int num = 0;
    int sum = 0;
    
    // note that this is an infinite loop
    // without the break statement

    while(true) //this is an infinite loop
    {
        cout << "enter a number: (enter 0 to quit) " << endl;
        cin >> num;
        if (num == 0) 
        {
            break;  // this will leave the loop and run
                    // next line after the loop.
        }
        // this won't be run if the break statement has
        // been run
        sum += num; // sum = sum + num
    }
    cout << "the sum is " << sum << endl;
    
    // this is an example of continue statement.
    // unlike the break, it doesn't go out of the loop
    // but circles back up to the top of the loop
    // and continues from the beginning of the loop.
    double quotient = 100;
    num = 0;
    
    for(int i=0; i<5; i++)
    {
        cout << "enter number: ";
        cin >> num;
        if(num == 0)
        {
            cout << "cannot divide by zero. please re-enter" << endl;
            continue; //goes to top of loop
        }
        quotient /= num;  // quotient = quotient / num;
    }
    cout << "the quotient is " << quotient << endl;
 
    //you can step through individual strings using 
    // loops and the at() function
    string name = "Alyona Diana Zyma";
    int size = name.size(); // for efficiency, get
                            // the size of the string first
                            // and put it in a variable
    // this prints the name and converts spaces
    // to underscores.
    for(int i=0; i < size; i++)
    {
        // get letter at 0 (strings start at 0 and go
        // to size-1.
        char letter = name.at(i);
        if(isspace(letter))
        {
            cout << "_";
        }
        else
        {
            cout << letter;
        }
        
    }
    cout << endl;
  
}
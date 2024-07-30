
/* week 5 example - 
 *   1
 *   string comparisions
 *   shows the use of relational operators
 *  with strings.
 * 
 */

#include <iostream>

using namespace std;

int main()
{
    string word = "";
    
    cout << "Enter a word: ";
    cin >> word;
    
    // strings can be used with relational operators
    if(word == "sun")  // ==   is equal to
    {
        cout << ">>(  )<<" << endl;
    }
    
    // note that is can be done with an else clause
    // to the previous if statement
    if(word != "sun")  //  !=  is not equal to
    {
        cout << "It's cloudy! :(" << endl;
        cout << "    {} {{}{}}{{}}} {{}" << endl;
    }
    
    // can also determine where in alphabetical order a string
    // is (this has some limitations when using both upper and 
    // lower case letters)
    if(word > "moth")
    {
        cout << word << " is after 'moth' in alphabetical order" << endl;
    }
    
    if(word < "moth")
    {
        cout << word << " is before 'moth' in alphabetical order" << endl;
    }    
    
    
    return 0;
}


/* week 5 example - 
 *   2
 *    string type
 *   demo of basic behavior and
 * functions used with the type string.
 * 
 */

#include <iostream>
#include <string> // not actually needed if you are
                  // including iostream. But if you
                  // are not include iostream this
                  // is how you include the string
                  // type

using namespace std;

int main()
{
    string line = "";
    string word = "";
    
    cout << "Enter a line of text: ";
    getline(cin, line);

    cout << "Enter a word: ";
    cin >> word;
    cin.ignore(100,'\n');
    
    
    int pos = line.find(word,0);
    if(pos == (int) string::npos) // this is typically -1
    {
        cout << word << " isn't in the line" << endl;
    }
    else
    {
        cout << word << " is at position " << pos << endl;    
    
    }
    
    
    // getting the length or size of a string (both functions can be used)
    
    int size = line.size();
    
    //  Using at() to get individual letter
    // NOTE: string positions start at 0 not 1
    
    cout << "position? ";
    cin >> pos;
    
    if(pos >= 0 || pos < size)
    {
        cout << " the letter at " << pos << " is: " << line.at(pos) << endl;
    }
    else
    {
        cout << pos << " isn't a valid position" << endl;
    }
    
    int num = 0;
    cout << "Enter number:";
    cin >> num;
    
    // converting a number to a string use to_string
    string snum = to_string(num);
    
    cout << snum << endl;
    
    // can then concatenate it to another string. Concatenation
    // means putting one string on the end of the other string
    // (putting them together)
    string concat = line + snum;
    
    cout << concat << endl;
    
    // if you need to get a substring of a string, use substr() function
    // a substring is part of a string:  the string 'cat' is part of 'concatenation'
    // substr takes a start position and a length (or string::npos if 
    // you want to go to the end of the string).
    int start = 0;
    int length = 0;
    cout << "Enter start: ";
    cin >> start;
    cout << "Enter length: ";
    cin >> length;
    
    string part = line.substr(start, length);
    cout << " substring is: " << part << endl;
    
    
    return 0;
}


/* week 5 example - 
 *  4
 *  bools and multiples
 *  more on comparisons using bool types
 *  and finding multiples of a number.
 * 
 */

#include <iostream>

using namespace std;

int main()
{
    // using bool types. These variables
    // can only take values of true or false

    bool tooHigh = false; // no quotes on this
    int num = 0;
    
    // can use = to set bools to true or false
    tooHigh = true; 
    
    cout << "Enter number: " << endl;
    cin >> num;
    
    // you can actually use conditionals for setting these values    
    tooHigh = (num > 5);
    
    if(tooHigh)  // note that we don't need to compare tooHigh to true or false
    {
       cout << num << " is too high." << endl;
    }
    else
    {
       cout << num << " is okay." << endl;
    }
    
    bool done = false;
    
    if(!done)  // tests for done being false
    {
        cout << "Were not done yet!" << endl;
    }
    
    
    // conditionals with just numbers. if your using a 
    // numeric variable (or a arithmetic expression)
    
    cout << "Enter number: ";
    cin >> num;
    
    // zero (0): - false
    // all other numbers (non-zero): true
    if(num) 
    {
        cout << "This is non-zero" << endl;
    }
    else 
    {
        cout << "This is zero" << endl;
    }
    
    // how to get a multiple of a number
    // using modulo. A multiple of a A
    // is a number when divide into by A
    // has a product of a whole number OR
    // a remainder of 0. For example:
    //     9/3 = 3  with 0 remainder
    //     so 9 is a multiple of 3
    //     OR 9 is evenly divisible by 3
    //     10/3 = 3 with 1 remainder
    //     so 10 is NOT a multiple of 3
    //
    // detect odd/even.  Even numbers
    // are multiples of 2 and odd numbers
    // are not. 
    //     11/2 = 5 remainder 1
    //       so 11 is NOT even
    //     12/2 = 6 remainder 0
    //       so 12 is even
    if(num % 5 == 0)
    {
        cout << num << " is a multiple of 5" << endl;
    }
    if(num % 2 != 0)
    {
        cout << num << " is an odd number" << endl;
    }
    else
    {
        cout << num << " is an even number" << endl;
    }
    
    // you can also use % to get individual digits in
    // a number (or a group of digits)
    
    int digit = num % 10;  // gets last digit
    int threeDigits = num % 1000; // gets three last digits
    
    cout << "last digit: " << digit 
         << " last three digits: " << threeDigits << endl;
    
    return 0;
}

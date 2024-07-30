
/* week 5 example - 
 *   3
 *    floats and ternary
 *    comparing floating point (doubles) and using
 * the ternary operator.
 */

#include <iostream>
#include <iomanip>
#include <cmath> // for using fabs

using namespace std;

int main()
{
    cout << setprecision(16) << fixed << showpoint;
       
    double num1 = 1.1;
    double num2 = 1.4;
    double num3 = .3;
    
    double ans = 0;
    
    
    // doing so arithmetic on floating point
    // numbers causes problems when doing 
    // comparisons
    ans = num2 - num1;
    if(ans == .3)
    {
        cout << ans << " this is true!" << endl;
    }
    else
    {
        cout << ans << " is NOT true!" << endl;
    }
    
    // This is due to the rounding of the results
    // of arithmetic in floating point.
    
    
    // In fact, just setting the number is 
    // not a problem because there is no math
    // being done to get this result.
    ans = num3;
    if(ans == .3)
    {
        cout << ans << " this is true!" << endl;
    }
    else
    {
        cout << ans << " is NOT true!" << endl;
    }
    
    // one way to deal with round-off errors and
    // comparisons is to use a tolerance value
    // if the result is less than this value then
    // take it to be the number. Use fabs so that
    // we don't need to worry about the number
    // going negative from the subraction.
    // for non-zero numbers, subtract a number
    // from the result that would make the value
    // zero. 
    double tol = .00001; 
    
    ans = num2 - num1;
    if(fabs(ans - .3) < tol)
    {
        cout << ans << " this is true!" << endl;
    }
    else
    {
        cout << ans << " is NOT true!" << endl;
    }
    
    // a nice shortcut for doing the following
    // type of if statement is using the 
    // conditional expression (also know as the
    // ternary operator statement).
    int num=0;
    int result=0;
    
    cout << "Enter number" << endl;
    cin >> num;
    
    if(num > 10)
    {
        result = 8;
    }
    else
    {
        result = 12;
    }
    cout << "result is " << result << endl;
    
    // the above can done using the ternary
    // operator statement
    result = (num > 10 ? 8 : 12);
    
    cout << "result is " << result << endl;
    
    return 0;
}

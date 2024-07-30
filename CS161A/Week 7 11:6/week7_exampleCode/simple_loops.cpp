/* week 7 - loop examples
 * examples of while, do/while
 * and for loops. 
 */

#include <iostream>

using namespace std;

int main() {

    // while loop
    // with a flag

    int num = 0;
    int sum = 0;
    bool cont = true;
    
    // runs body ( between { } ) over and over again
    // if conditional remains true. When conditional 
    // becomes false, it goes to the next statement
    // after the while loop. The conditional can be
    // any conditional that an if statement can take.
    
    // Note that if the conditional is false to start
    // the body is never run. 

    while (cont) //same as cont==true
    {
        cout << "enter a number: (enter 0 to quit) " << endl;
        cin >> num;
        if (num == 0) {
            cont = false;
        } else {
            sum += num; // sum = sum + num
        }
    }
    cout << "the sum is " << sum << endl;
    
    //do while loop
    // with sentinel
    sum = 0;
    int count = 0;
    char ans = '\0';
    
    // the do/while loop is simular to a while except that
    // the check for the conditional is at the end of the
    // loop. So the body is always run once no matter what
    // the conditional is.
    do {
        cout << "enter number: ";
        cin >> num;
        sum += num;
        count++; // count = count + 1
        cout << "do you want to continue? ('y' or 'n')" << endl;
        cin >> ans;
        cin.ignore(10, '\n');
    } while (ans == 'y');
    cout << "the sum is " << sum << endl;
    cout << "the count is " << count << endl;
    cout << "the average is " << sum / count << endl;

    sum = 0;
    //for loop using a counter
    // for loops are more compact representation
    // for doing counter loops. A counter loop
    // counts up or down using a variable called
    // a counter. Here, i is the counter variable
    // 
    for (int i = 0; i < 10; i++) {  // i++ (or ++i) is i = i + 1
        cout << i << endl;
        sum += i;   // this is sum = sum + i
    }
    cout << "the sum from 0 to 9 is " << sum << endl;
}
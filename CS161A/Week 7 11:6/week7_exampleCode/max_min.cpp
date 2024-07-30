/* week 7 - finding max and min
 *   asks for how many numbers
 * and then asks for each number
 * Finds the max and min of each
 * set of numbers.
 */

#include <iostream>

using namespace std;

int main() {
    
    int num = 0;
    int max = 0; // this will be set inside the for loop
    int min = 0; // this will be set inside the for loop
    int count = 0; 
    
    cout << "How many numbers? ";
    cin >> count;
    
    while(count <= 0)
    {
        cout << "Wrong value. Please re-enter.";
        cin >> count;
    }
    
    
    for (int i = 1; i <= count; i++) {  
       cout << "Enter number: ";
       cin >> num;
       if(i == 1) // initialize max and min to first value
       {
           max = num;
           min = num;
       }
       // check for new max
       if(num > max) 
       {
           //if so, replace max with this value
           max = num;
       }
       // check for new min
       if(num < min)
       {
            //if so, replace min with this value
           min = num;
       }
       
       
    }
    cout << "the max is " << max << endl;
    cout << "the min is " << min << endl;
}
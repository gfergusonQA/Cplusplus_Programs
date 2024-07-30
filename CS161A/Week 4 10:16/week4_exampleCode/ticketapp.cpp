 /*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 4
# Date:             09/23/23
# Description:      ticket app - using if statements
#                   1. Ask for an age. then:
                    2. If age less than 0. re-ask for an age
                    3. If age between 0 and 15
                       price of ticket is 50% adult ticket
                    4. If age between 15 and 18 - 70% of adult ticket
                    5. If age between 18 and 64 - adult price
                    6. If age older than 65 - 80% of adult price
# Input:            age of patron
# Output:           ticket price for that patron
# Sources:          none
#
#*****************************************************************************/



#include <iostream>
#include <iomanip>

using namespace std;

// you can put constants here (they have 'const'
// before them) but NO variables

const double ADULT = 15.00;
const double CHILD = ADULT*.5;
const double TEEN = ADULT*.7;
const double SENIOR = ADULT*.8;

int main()
{

    int age = 0;
    double ticketPrice = 0.0;
    
    // for printing currency
    cout << setprecision(2) << fixed;
    
    cout << "== Welcome to movie ticket price"
         << " determinator app =="
         << endl;
         
    cout << "Enter your age: ";
    cin >> age;
    
    if(age < 0) {
        cout << "This age is invalid."
             << " Please re-enter." << endl;
        cin >> age;
    }
    
    // using nested if/else to check for ranges
    // note that you don't need to check the
    // lower range as the conditional above
    // has already done so.
    if(age < 15) {      // age >= 0 and age < 15
       ticketPrice = CHILD;
    }
    else if(age < 18) { // age >=15 and age < 18
       ticketPrice = TEEN;
    }
    else if(age < 65) { // age >= 18 and age < 65
        ticketPrice = ADULT;
    }
    else {               // age >= 65
        ticketPrice = SENIOR;
    }
    
    cout << endl << "Your ticket price is: $" << ticketPrice << endl;
    cout << "Thank you for using our app!" << endl;
    
    
    return 0;
}

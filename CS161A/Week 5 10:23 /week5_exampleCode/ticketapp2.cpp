/* week 4 example - ticket app
 *   5
 *  buy one ticket. ask for
 * an age. then:
 *   - age less than 0. re-ask for
 *     an age
 *   - child: age greater than or equal to zero
 *     to age less than 15:  50% of adult ticket
 *   - teen: age is greater than or equal to 15 but
 *     less than 18:  70% of adult ticket (30% off)
 *   - adult: age greater than or equal to 18 to
 *     less than 65:  $15.00
 *   - senior: age greater than or equal to 65:
 *         80% of adult ticket (20% off)
 * 
 */

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

    int choice = 0;
    double ticketPrice = 0.0;
    
    cout << setprecision(2) << fixed;
    
    cout << "== Welcome to movie ticket app ==" << endl;
         
    cout << "Choose the following ticket type: " << endl;
    cout << "  1 - child (14 or under)" << endl;
    cout << "  2 - teen (15 to 17 years of age)" << endl;
    cout << "  3 - adult (18 to 64 years of age)" << endl;
    cout << "  4 - senior (65 or over)" << endl;
    cin >> choice;
    
    switch(choice) {
        case 1:  cout << "You have chosen a child ticket" << endl;
                 ticketPrice = CHILD;
                 break;
        case 2:  cout << "You have chosen a teen ticket" << endl;
                 ticketPrice = TEEN;
                 break;
        case 3:  cout << "You have chosen a adult ticket" << endl;
                 ticketPrice = ADULT;
                 break;
        case 4:  cout << "You have chosen a senior ticket" << endl;
                 ticketPrice = SENIOR;
                 break;
        default: cout << "This choice is invalid." << endl;
                 cout << "Thank you for using our app." << endl;
                 return 0;
    }
    
    cout << endl << "Your ticket price is: $" << ticketPrice << endl;
    
    cout << "Thank you for using our app!" << endl;
    
    
    return 0;
}

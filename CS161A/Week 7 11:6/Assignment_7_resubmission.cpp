/****************************************************************
# Author:           Gina Ferguson
# Assignment:       A07 Coffee/Tea Vending Machine
# Date:             November 17, 2023 (Resubmitted/updated on Dec. 8, 2023)
# Description:      This program will be a vending machine where 
                    the user tells how they pay in coins, and 
                    then it will print a menu for dispensing 
                    coffee or tea to the user to choose from, 
                    and then a prompt for quantity. If the money
                    deposited is enough, you will receive the 
                    item or it will tell you ask you for more 
                    cash. 
# Input:            coin (integer), choice (string), 
                    quantity (integer)
# Output:           balance (double), total (double)
# Sources:          Assignment 7 specifications & Zybooks     
#****************************************************************/

#include <iostream>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

int main() {
    const double COST_PER_ITEM = 0.25;
    int coin;
    int quantity;
    double balance = 0;
    double total;
    char choice;

    cout << "Welcome to Gina's Coffee/Tea Vending Machine!\n\n";

    // Collecting money
    do {
        cout << "Enter coins - 5, 10, or 25 only: ";
        cin >> coin;
        while (coin != 5 && coin != 10 && coin != 25 && coin != 0) {
            cout << "Invalid coin! Enter 5, 10, or 25 only: ";
            cin.clear(); // clear error flag
            cin.ignore(10000, '\n'); // Ignore characters up to newline
            cin >> coin;
        }
        balance += coin / 100.0; // converting cents to dollar bills
    } while (coin != 0);

    cout << fixed << setprecision(2); // setting coins for 2 decimal places

    // Menu & Money status
    while (true) {
        cout << "Your balance is $" << balance << endl << endl;
        cout << "Please pick an option ($0.25 each): " << endl <<
            "C/c: Coffee\nT/t: Tea\nQ/q: Quit\n>> ";
        cin >> choice;

        if (choice == 'Q' || choice == 'q') {
            cout << "\nThank you! Your balance is $" << balance << endl;
            break;
        }

        if (choice != 'C' && choice != 'c' && choice != 'T' && choice != 't') {
            cout << "Invalid Option! Please choose a valid option!\n";
            continue;
        }

        cout << "\nHow many would you like?\n>>> ";
        cin >> quantity;
        while (!cin || quantity < 1) {
            cout << "Invalid Option! How many would you like?\n>> ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> quantity;
        }

        total = COST_PER_ITEM * quantity;

        if (total > balance) {
            cout << "\nNot enough balance! Your total is $" << total << 
                    ".\nYour balance is $" << balance << "\nPlease add more coins.\n";
            do {
                cout << "Enter coins - 5, 10, or 25 only: ";
                cin >> coin;
                while (coin != 5 && coin != 10 && coin != 25 && coin != 0) {
                    cout << "Invalid coin! Enter 5, 10, or 25 only: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cin >> coin;
                }
                balance += coin / 100.0;
            } while (coin != 0);
            cout << "\nYour balance is $" << balance << endl; // Display updated balance after adding more coins
        } else {
            balance -= total;
            cout << "\nYour total is $" << total << "\nYour balance is $" 
                    << balance << endl;
        }
    }

    cout << "Happy Snacking!";

    return 0;
}

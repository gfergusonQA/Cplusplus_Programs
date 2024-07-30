/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A01 Final Version (CS161B - Sengupta)
# Date:             January 9-15, 2023
# Description:      This C++ program will calculate the price for a customer’s order, using menu with two choices: input a menu item name and price, or QUIT the program. The user will be able to select many choices until they quit the program manually. The code will be using several functions, a do-while loop, and an exit condition without breaks or returns in the loop.
# Input:            itemName (string), num (integer), anotherItem(string)
# Output:           
displayFees(double, int) [void function], 
# Sources:          Assignment 1 specifications & Zybooks
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>

using namespace std;

// the function prototypes
void welcome();
void displayMenu();
void readOption(int &option);
void readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
void placeOrder(double &cost);
double tipDiscount(double &tip, double &discount, double cost);

// the constants (For discounts)
const double DISCOUNT1 = 50.0;
const double DISCOUNT2 = 35.0;
const double DISCOUNT_AMOUNT1 = 0.10;
const double DISCOUNT_AMOUNT2 = 0.05;

int main() {
    int option;
    double totalCost = 0.0;

    do {
        if (totalCost == 0.0) {
          welcome(); // Display welcome message only if totalCost is 0
        }
    
        displayMenu();
        readOption(option);

        if (option == 1) {
            placeOrder(totalCost);
            double tip;
            double discount;

            cout << fixed << setprecision(2);
            cout << "\nYour total is: $" << totalCost << endl << endl;

            readDouble("Enter the amount of tip you want to add $: ", tip);
            totalCost += tip;
          
            totalCost = tipDiscount(tip, discount, totalCost);
          
            cout << fixed << setprecision(2);
            cout << "\nYour total is: $" << totalCost << endl;
          
            if (discount > 0) {
                cout << "You get a " << 
                  (discount == DISCOUNT_AMOUNT1 ? "10%" : "5%") << " discount!" << endl;
                cout << "Your discount is: $" << discount << endl;
            }
            double finalTotal = totalCost - discount;
            cout << "Your final total is: $" << finalTotal << endl << endl;
            
            totalCost = 0.0; // Need to reset totalCost for the next Iteration
          
        } else if (option == 2) {
            cout << "Thank you for using my program!" << endl;
        } else {
            cout << "Invalid Option! Please choose 1-2!" << endl;
            cout << "<< ";
        }

    } while (option != 2);

    return 0;
}

void welcome() {
    cout << "Welcome to my Food Cart Program!" << endl;
    cout << "What would you like to do today?" << endl;
}

void displayMenu() {
    cout << "Pick an option from below:" << endl;
    cout << right << setw(25) << "1. Place an order" << endl;
    cout << right << setw(15) << "2. Quit" << endl;
    cout << ">> ";
}

void readOption(int &option) {
    readInt("", option);
    while (option < 1 || option > 2) {
        cout << "Invalid Option! Please choose 1-2!" << endl;
        cout << ">> ";
        readInt("", option);
    }
}

void readInt(string prompt, int &num) {
    while (true) {
        cout << prompt;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else {
            cin.ignore();
            break;
        }
    }
}

void readDouble(string prompt, double &num) {
    while (true) {
        cout << prompt;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            cin.ignore();
            break;
        }
    }
}

void placeOrder(double &cost) {
    char anotherItem;

    do {
        string itemName;
        double itemCost;

        cout << "Enter the name of your item: ";
        getline(cin, itemName);
        readDouble("Enter the cost of your item $: ", itemCost);

        cost += itemCost;

        cout << "Do you want another item? (y/n): ";
        cin >> anotherItem;
        cin.ignore();

        while (tolower(anotherItem) != 'y' && tolower(anotherItem) != 'n') {
            cout << "Invalid Option! Please choose y/n!" << endl;
            cout << ">> ";
            cin >> anotherItem;
            cin.ignore();
        }

    } while (tolower(anotherItem) == 'y');
}

double tipDiscount(double &tip, double &discount, double cost) {
    double total = cost + tip; // Including the tip in my total

    if (cost > DISCOUNT1) {
        discount = cost * DISCOUNT_AMOUNT1;
    } else if (cost > DISCOUNT2) {
        discount = cost * DISCOUNT_AMOUNT2;
    } else {
        discount = 0.0;
    }

    return total - discount;
}

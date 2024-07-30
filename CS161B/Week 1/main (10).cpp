/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A01 Final Version (CS161B - Sengupta)
# Date:             January 9-15, 2023 (Updated 3/3/23)
# Description:      This C++ program will calculate the price for a customer’s order, using menu with two choices: input a menu item name and price, or QUIT the program. The user will be able to select many choices until they quit the program manually. The code will be using several functions, a do-while loop, and an exit condition without breaks or returns in the loop.
# Input:            itemName (string), num (integer), anotherItem(string)
# Output:           displayFees(double, int) [void function], 
# Sources:          Assignment 1 specifications & Zybooks
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

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
  double tip = 0.0;
  double discount = 0.0;
  double finalTotal = 0.0;

  welcome(); 
  do {
    displayMenu();
    readOption(option);

    if (option == 1) {
      placeOrder(totalCost);
      cout << fixed << setprecision(2);
      cout << "\nYour total is: $" << totalCost << endl;
      
      finalTotal = tipDiscount(tip, discount, totalCost);

      cout << "Your final total is: $" << finalTotal << endl <<             endl;
      totalCost = 0.0; // reset for next order
    } else if (option ==2) {
      cout << "Thank you for using my program!" << endl;
    }
  } while (option != 2); // continue until user chooses to quit
  
  return 0;
}

// Name:   welcome()
// Desc:   This function displays a welcome message to the user.
// Input:  None
// Output: Displays "Welcome to my Food Cart Program!" to the console.
// Return: None (void)
void welcome() {
    cout << "Welcome to my Food Cart Program!" << endl;
}

// Name:   displayMenu()
// Desc:   This function prints the menu options to the user.
// Input:  None
// Output: Displays menu options to the console.
// Return: None (void)
void displayMenu() {
  cout << "What would you like to do today?" << endl;
  cout << "Pick an option from below:" << endl;
  cout << right << setw(25) << "1. Place an order" << endl;
  cout << right << setw(15) << "2. Quit" << endl;
}

// Name:   readOption()
// Desc:   Reads an integer option from the user and ensures it is valid.
// Input:  None directly, reads user input.
// Output: Prompts user for input and may print validation messages.
// Return: Integer representing the user's menu option.
void readOption(int &option) {
  readInt(">> ", option);
  while (option < 1 || option > 2) {
    cout << "Invalid Option! Please choose 1-2!" << endl;
    cout << ">> ";
    readInt("", option);
  }
}

// Name:   readInt()
// Desc:   Prompts the user with a message and reads an integer.
// Input:  String prompt message.
// Output: Prompts user for input and may print validation messages.
// Return: Integer value input by the user, returned by reference.
void readInt(string prompt, int &num) {
  cout << prompt;
  while (!(cin >> num) || num < 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Please enter a valid integer (1 or 2):         " << endl;
    }
  cin.ignore(1000, '\n'); // clear buffer
}

// Name:   readDouble()
// Desc:   Reads a floating-point number from the user after prompting.
// Input:  String prompt message.
// Output: Prompts user for a floating-point number.
// Return: Double value input by the user, returned by reference.
void readDouble(string prompt, double &num) {
  cout << prompt;
  while (!(cin >> num)) { // change IF to WHILE to keep running
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Please enter a valid number: " << endl;
  }
}

// Name:   placeOrder()
// Desc:   Allows the user to place an order by entering item names and costs.
// Input:  None directly, reads user inputs for item names and costs.
// Output: Prompts for entering item names and costs, and asks if the user wants to add more items.
// Return: None (void), but updates the total cost by reference.
void placeOrder(double &cost) {
  string itemName;
  char anotherItem = ' ';
  double itemCost = 0.0;

  cost = 0.0; // ensure cost is reset for each new order

  do {    
    cout << "Enter the name of your item: ";
    getline(cin, itemName);
    
    readDouble("Enter the cost of your item $: ", itemCost);
    cost += itemCost;

    cout << "Do you want another item? (y/n): ";
    cin >> anotherItem;
    cin.ignore(1000, '\n'); // clear the newline left in buffer

    while (tolower(anotherItem) != 'y' && tolower(anotherItem) != 'n') {
      cout << "Invalid Option! Please choose y/n!" << endl;
      cin >> anotherItem;
      cin.ignore(1000, '\n');
    }
  } while (tolower(anotherItem) == 'y');
}

// Name:   tipDiscount()
// Desc:   Calculates the final total cost including tip and applicable discounts.
// Input:  Tip amount and initial cost.
// Output: Prompts for entering tip, displays new total with tip, and shows discount info if applicable.
// Return: Double value representing the final total cost after applying tip and discounts.
double tipDiscount(double &tip, double &discount, double cost) {
  double finalTotal = 0.0;
  double total = 0.0;
  
  cout << "\nEnter the amount of tip you want to add: $";
  readDouble("", tip);
  total = cost + tip; 

  cout << "\n\nYour total is: $" << total << endl;

  if (total > DISCOUNT1) {
      discount = total * DISCOUNT_AMOUNT1; // Apply 10% discount
  } else if (total > DISCOUNT2) {
      discount = total * DISCOUNT_AMOUNT2; // Apply 5% discount
  } else {
      discount = 0.0; // No discount applied
  }

  finalTotal = total - discount;

  // Only show discount information if a discount has been applied
  if (discount > 0) {
      cout << "You get a " << ((total > DISCOUNT1) ? "10%" : "5%") << " discount!" << endl;
      cout << "Your discount is $" << discount << endl;
  }

  return finalTotal; // Return the final total after discount
}

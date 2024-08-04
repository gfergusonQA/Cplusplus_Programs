#include "tools.h"

// Function: welcome()
// Description: Displays a welcome message and prompts
//              the user for the name of the airplane collection file
// Inputs: none
// Outputs: none
// Return: none
void welcome() {
cout << "\n\nWelcome to the airplane collection program!\n"
  "What is the name of the airplane collection file? ";
}

// Function: displayMenu()
// Description: Displays the menu options for the user to choose from
// Inputs: none
// Outputs: none
// Return: none
void displayMenu() {
    cout << "\nChoose an option:\n";
    cout << "L: List All Planes\n";
    cout << "M: List Planes by Make\n";
    cout << "A: Add a New Plane\n";
    cout << "R: Remove a Plane\n";
    cout << "Q: Save and Quit\n\n";
}

// Function: validateInput(double &value, double min, double max)
// Description: Validates that the user input is a double within 
//              the specified range
// Inputs: value - reference to the double to be validated, 
//         min - minimum acceptable value, max - maximum 
//         acceptable value
// Outputs: none
// Return: bool - true if the input is valid, false otherwise
bool validateInput(double &value, double min, double max) {
    cin >> value;
    if (cin.fail() || value < min || value > max) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// Function: validateInput(int &value, int min, int max)
// Description: Validates that the user input is an 
//              integer within the specified range
// Inputs: value - reference to the integer to be 
//         validated, min - minimum acceptable value, 
//         max - maximum acceptable value
// Outputs: none
// Return: bool - true if the input is valid, false otherwise
bool validateInput(int &value, int min, int max) {
    cin >> value;
    if (cin.fail() || value < min || value > max) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true; 
}



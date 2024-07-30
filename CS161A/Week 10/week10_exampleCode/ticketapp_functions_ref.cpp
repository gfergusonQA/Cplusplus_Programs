/* Example code - Ticket App with functions
 * Dona Hertel
 * 
 *  Examples of functions. Asks user for a name
 * and an age. Prints out cost of ticket.
 * Uses pass by value here.
 * 
 */
#include <iostream>

using namespace std;

const double ADULT = 15.00;
const double CHILD = ADULT*.5;
const double TEEN = ADULT*.7;
const double SENIOR = ADULT*.8;

//For now, put your functions ABOVE main
// so that your code will compile.
// OR read further on using prototypes.


// this is a void function because it doesn't return
// a value to main.
void printMessage()
{
    cout << "== Welcome to movie ticket price"
         << " determinator app =="
         << endl;
}

// This is a void function as we are passing back the values
// through the parameters.  Make sure you have the reference
// operator '&' in front of the variable name to do this.
void getNameAndAge(string &name, int &age) {
    
    cout << "Enter your name: " << endl;
    
    getline(cin, name);  // writing straight into the parameter.
                         // note that we don't need a local variable
                         
    cout << "Enter age: " << endl;
    cin >> age;  // again, this goes into the parameter
    
    while(age < 0) {
        cout << "This age is invalid."
             << " Please re-enter." << endl;
        cin >> age;
    }
    cin.ignore(100,'\n');
    
}

//a function with parameters. Parameters are like
// local variables to a function but they are 
// initialized with values when the function
// is called. See main for more details
void printTicket(string personName, int personAge)
{
    double ticketPrice = 0.0;
    
    if(personAge < 15) {      // age >= 0 and age < 15
       ticketPrice = CHILD;
    }
    else if(personAge < 18) { // age >=15 and age < 18
       ticketPrice = TEEN;
    }
    else if(personAge < 65) { // age >= 18 and age < 65
        ticketPrice = ADULT;
    }
    else {               // age >= 65
        ticketPrice = SENIOR;
    }
    
    cout << "Well, " << personName << " your ticket is $"
         << ticketPrice << endl;
    cout << "Enjoy the movie!" << endl;
    
}

int main()
{
	string name = ""; // this is only available in main.
    int age = 0; // this is only available in main.
    
    
    // calls the function printMessage()
    // where it will run the code inside
    // printMessage and return to the line
    // after this call
    printMessage(); 
    
    // Here, we are using reference paramters 
    // to change name and age.
    getNameAndAge(name, age);
    
    
    cout << endl << "your name is: " << name << endl;
    cout << "your age is: " << age << endl << endl;
    
    //You can optionally include input to your
    // function by using parameters. The call
    // takes a list of arguments and sets the
    // values of the arguments to the corresponding
    // list of parameters.
    printTicket(name, age); // <- argument list
    // The argument list must match the parameter list
    // in number of values and types of values.
    // NOTE: it's the POSITION in the list that determines
    // which parameter gets what argument value NOT THE
    // NAME of the argument.
    
	return 0;
}

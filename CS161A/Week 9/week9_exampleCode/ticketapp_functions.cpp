/* Example code - Ticket App with functions
 * Dona Hertel
 * 
 *  Examples of functions. Asks user for a name
 * and an age. Prints out cost of ticket.
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

// these are non-void functions. they return a value using 
// a return statement.
string getName()
{
    // this is a local variable that is NOT the same
    // variable as the one called 'name' in main.
    // it only exists within this function.
    string name = "";
    
    cout << "Enter your name: " << endl;
    
    getline(cin, name);
    
    return name; // returns the value of name
}

int getAge()
{
    int age = 0;
    
    cout << "Enter age: " << endl;
    cin >> age;
    
    while(age < 0) {
        cout << "This age is invalid."
             << " Please re-enter." << endl;
        cin >> age;
    }
    
    cin.ignore(10,'\n');
    
    return age; // returns the value of age
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
    
    // you can optionally pass back a value when calling
    // a function.  The function will run and return a value
    // which is then assigned to a variable.
    name = getName();
    age = getAge();
    //NOTE: need to pick up return value with an assignment!
    // It doesn't automatically set variables. Also, variables
    // must match return type given.
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

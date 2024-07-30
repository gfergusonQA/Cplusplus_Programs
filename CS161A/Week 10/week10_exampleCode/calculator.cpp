/* Example code - calculator app
 * Dona Hertel
 * 
 *  shows the use of functions. The
 * app is a menu-driven program that
 * allows the user to add, subract
 * multiply or divide numbers and
 * get a subtotal each time.
 * 
 * 
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int STR_SIZE = 200;

/* Purpose: prints the main menu
 * Parameters: none
 * Return:  none
 */
void printOpMenu()
{
	cout << "*** operations ***" << endl;
	cout << "    a  - add " << endl;
	cout << "    s  - subtract " << endl;
	cout << "    m  - multiply " << endl;
	cout << "    d  - divide " << endl;
	cout << "    q  - quit program " << endl;
	cout << " choice: " << endl;
}

/* Purpose: asks user for operation from menu
 * Checks to see if valid. passes back operation
 * Parameters: none
 * Return:  returns operation
 */
char getOperation()
{
    char op = 'z';
    bool first = true;
    while(op != 'a' && op != 's' && op != 'm' && op != 'd' && op != 'q')
    {
		if(!first) {
			cout << "invalid operation. please re=-enter" << endl;
		 }
		 cin >> op;
		 cin.ignore(10,'\n');
		 first = false;
	}
	
	return op;
}

/* Purpose: does the given operation on the
 * passed in numbers. returns the result.
 * Parameters: op - operation to perform
 *             a  - first number
 *             b  - second number
 * Return:  returns result of operation
 */
double doOperation(char op, double a, double b)
{
	double res = 0.0;
	switch(op) {
		case 'a': res = a+b;
		          break;
		case 's': res = a-b;
		          break;
		case 'd': if (b == 0.0)
		          {
					  cout << "can't divide by zero." << endl;
				  }
				  else
				  {
					  res = a/b;
				  }
				  break;
	  case 'm':   res = a*b;
	              break;
	  case 'q':   break;
	  default:    cout << "don't recognize the operation" << endl;
  }
  return res; 
}

/* Purpose: main. Runs the main menu loop
 * parameters: none
 * Return:  exit code of 0
 */
int main()
{
	char op = 'z';
	double b = 0, res = 0;
	
	cout << "*** Calculator Program ***" << endl;
	cout << "Enter first Number: " << endl;
	cin >> res;
	cin.ignore(10,'\n');
	while(op != 'q')
	{
		printOpMenu();
		op = getOperation();
		if( op != 'q' )
		{
		   cout << "Enter second Number " << endl;
		   cin >> b;
		   cin.ignore(10,'\n');
           // the returned res value is the first number
           // for the next operation
		   res = doOperation(op, res, b);
		   cout << "The subtotal is: " << res << endl;
	    }
	}
	cout << "The Final Total is: " << res << endl;
	cout << "*** Thank you for using our app! " << endl;
	
	
	return 0;
}

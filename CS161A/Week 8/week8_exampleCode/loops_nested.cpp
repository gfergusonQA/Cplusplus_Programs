/* week 8 - nested loop examples
 * examples of nested loops
 * 
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // this prints out a nice ASCII art triangle
  
  int size = 0;
  
  cout << "Enter size: ";
  cin >> size;
  while(size <= 0 || size > 30)
  {
      cout << "Wrong size. needs to be between 1 and 30" << endl;
      cin >> size;
  }
  
  for(int i=0; i<size; i++) //OUTER LOOP
  {
      // this is right side up. for upside down
      // do j < size; j++
      for(int j = i; j>0; j--)
      {
         cout << "*";
      }
      cout << endl;
      
  }
  
  // prints a multiplication table
  cout << "Enter size of table (up to 10): ";
  cin >> size;
  while(size <= 0 || size > 10)
  {
      cout << "Wrong size. needs to be between 1 and 10" << endl;
      cin >> size;
  }
  
  // print header
  for(int i=1; i<=size; i++)
  {
      cout << setw(6) << i;   
  }
  cout << endl;
  // this trick gets a proportional line
  // I put some spaces in front to center it.
  cout <<"   " 
       << setfill('-') 
       << setw(6*size) << "-" 
       << setfill(' ') << endl;
  
  //print body of table
  for(int i=1; i<=size; i++) // for one row
  {
      for(int j=1; j<=size; j++) // for each col in a row
      {
          cout << setw(6) << i*j;
      }
      cout << endl;  // moves to next row
  }
  
  return 0;
}

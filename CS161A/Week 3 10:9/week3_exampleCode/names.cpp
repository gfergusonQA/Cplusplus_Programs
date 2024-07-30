/* week 3 examples 
 * strings, chars and using 
 * getline
 */
/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 3
# Date:             09/23/23
# Description:      examples of using string type, char type
#                   getting input from getline, using ignore   
# Input:            an int, char and 2 strings
# Output:           the input
# Sources:          none
#
#*****************************************************************************/


#include <iostream>
#include <string> 

using namespace std;

int main()
{
   string first, last;
   int age;
   char ans = 'y';
   
   cout << "Enter age: " << endl;
   cin >> age;
   //cin.ignore(100,'\n');

   cout << "your age is " << age << endl;
   
   // you can pick up a char but
   // if the user types more than
   // a char, it will skip input
   // later.
   cout << "Is this okay?" << endl;
   cin >> ans;
   //cin.ignore(100,'\n');
   
   cout << "you answered: " << ans << endl;
   
   cout << "Enter first name: " << endl;
   cin >> first;
   //cin.ignore(100,'\n');
   
   // without the cin.ignore() after
   // the last cin >>, this will 
   // skip entering a value.
   cout << "Enter last name: " << endl;
   getline(cin,last);
   
   cout << endl;
   
   cout << "Age: " << age << endl;
   cout << "Name: " << first
        << " " << last << endl;
        
    
   return 0;
}

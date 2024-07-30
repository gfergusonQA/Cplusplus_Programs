/* week 3 example - reference operator
 *   shows the use of reference operator
 *    to make reference parameters
 */
#include <iostream>

using namespace std;

void valueParam(int a);
void refParam(int &a);


int main()
{
    int a = 1;
    
    cout << "a BEFORE call to valueParam() " 
         << a << endl;
    
    valueParam(a);
    
    cout << "a AFTER call to valueParam() " 
         << a << endl;
         
    cout << endl;
         
    cout << "a BEFORE call to refParam() " 
         << a << endl;
    
    refParam(a);
    
     cout << "a AFTER call to refParam() " 
         << a << endl;
    
    
    return 0;
}

void valueParam(int a)
{
    a = 100;
}

void refParam(int &a)
{
    a = 100;
}
    
/* week 3 example - default parameters
 *  shows the use of default values for
 * parameters.
 */
 
#include <iostream>

using namespace std;

void twoDefaults(int a, int b = 20, int c = 30);
void oneDefault(int a = 10);

int main()
{
    int a = 1, b = 2, c = 3;
    
    oneDefault();
    oneDefault(a);
    
    twoDefaults(a);
    twoDefaults(a,b);
    twoDefaults(a,c); // doesn't set c as 
                      //expected. it sets b
                      // instead because b
                      // is the second param
    twoDefaults(a,b,c);
    //twoDefaults();  // doesn't compile 
                      // because one parameter is needed
    
   
    return 0;
}


void oneDefault(int a)
{
    cout << "a is " << a << endl;
    
}
    
void twoDefaults(int a, int b, int c)
{
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
}


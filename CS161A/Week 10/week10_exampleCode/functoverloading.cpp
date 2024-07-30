/* week 3 - function overloading
 *   can use the same name for
 *   a function if there is different
 *   list of parameters. 
 */
#include <iostream>
#include <iomanip>

using namespace std;

//float add(int a, int b);
int add(int a, int b);
double add(double a, double b);


int main()
{
    int a = 1;
    int b = 3;
    double af = 3.1;
    double bf = 2.5;
    int total=0;
    double ftotal=0.0;
    
    cout << setprecision(3) << fixed; 
   
    total = add(a,b);
    cout << total << endl;
         
    cout << endl;
         
    ftotal = add(af,bf);
    cout << ftotal << endl;
    
    
    return 0;
}

/*
// below function won't compile
// because it's only different by
// return type
float add(int a, int b)
{
    return a + b;
}
*/

int add(int a, int b)
{
    cout << "adding two ints" << endl;
    return a + b;
}

double add(double a, double b)
{
    cout << "adding two doubles" << endl;
    return a + b;
}
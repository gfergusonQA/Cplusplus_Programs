/*****************************************************************************
# Author:           Dona Hertel
# Assignment:       Example Code Week 2
# Date:             03/08/22
# Description:      Asks user for radius and prints volume of a sphere
#                     with the given radius
# Input:            Radius of the sphere
# Output:           Volume of the sphere with the given radius
# Sources:          My formulas were obtained from:
#              https://www.thoughtco.com/surface-area-and-volume-2312247
#*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>  // for M_PI 
 
using namespace std;

// main:  Asks user for radius and prints volume of a sphere
//                     with the given radius
//    -parameters: none
//    -return: 0 for sucessful completion 
//
int main() 
{ 
    const double PI = M_PI;
    const double FOUR_THIRDS = 4.0/3.0;
    double radius = 0.0;
    double sphereVolume = 0.0;
    double cubeVolume = 0.0;
    
    // set this to however digits you want after the decimal point
    cout << setprecision(3) << fixed;
    // you can also print floating point in scientific notation
    // good for compacting big numbers.
    cout << scientific;
    
    cout << "*** Volume App ***" << endl;
    
    // get radius
    cout << "enter radius of sphere: ";
    cin >> radius;
    
    //cube volume - r^3
    cubeVolume = radius * radius * radius;  // next week, we'll talk about a
                                        // function you can use to do exponents
                                        
        
    //sphere - 4/3 x M_PI x radius^3 (r cubed)
    sphereVolume = FOUR_THIRDS * PI * cubeVolume;
    
    //print out volume
    cout << "The volume of the sphere is " 
         << sphereVolume << endl;
    cout << "A cube with the same size side as the radius is " 
         << cubeVolume << endl;
    
    return 0; 
}

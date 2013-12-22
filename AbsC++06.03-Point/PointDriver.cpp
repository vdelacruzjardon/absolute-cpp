/* 
Absolute C++ (5e); Ch. 6 "Structures and Classes"; Project 3

The type Point is a fairly simple data type, but under another name (the template 
class pair) this data type is defined and used in the C++ Standard Template Library, 
although you need not know anything about the Standard Template Library to do 
this exercise. Write a definition of a class named Point that might be used to store 
and manipulate the location of a point in the plane. You will need to declare and 
implement the following member functions: 
  a. A member function set that sets the private data after an object of this class 
is created. 
  b. A member function to move the point by an amount along the vertical and 
horizontal directions specified by the first and second arguments. 
  c. A member function to rotate the point by 90 degrees clockwise around the origin. 
  d. Two const inspector functions to retrieve the current coordinates of the point. 
Document these functions with appropriate comments. Embed your class in a test 
program that requests data for several points from the user, creates the points, then 
exercises the member functions. 
*/

#include "Point.h"
#include <iostream>
using namespace std;

int main( ) {
    // declare test points and get input
    Point p1, p2;
    cout << "Enter the coordinates of point p1 as X Y: ";
    cin >> p1;
    cout << "Now enter the coordinates of another point p2 as X Y: ";
    cin >> p2;
    cout << endl;

    // <<, + and - operator overloads
    cout << "p1: " << p1 << " and p2: " << p2 << endl << endl;
    cout << "p1 + p2: " << (p1 + p2) << " and p1 - p2: " << (p1 - p2) << endl << endl;

    // rotate, move and set member functions
    double x, y;
    p1.rotate( );
    cout << "p1 rotated 90 degrees: " << p1 << endl << endl;

    x = 5.5, y = -2.2;
    p2.move( x, y );
    cout << "p2 moved by ( " << x << ", " << y << " ): " << p2 << endl << endl;

    x = -3.0/7, y = 40000.1;
    p1.set( x, y );
    cout << "p1 set to ( " << x << ", " << y << " ): " << p1 << endl << endl;

    return 0;
}

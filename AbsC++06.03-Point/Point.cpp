/* 
Absolute C++ (5e); Ch. 6 "Structures and Classes"; Project 3
*/

#include "Point.h"
#include <iostream>

// default constructor sets x and y to zero
Point::Point( ) : x(0.0), y(0.0)
{}

// constructor specifies x and y
Point::Point( double x, double y ) : x(x), y(y)
{}

// accessor for x
double Point::getX( ) const {
    return x;
}

// accessor for y
double Point::getY( ) const {
    return y;
}

// mutator sets both x and y
void Point::set( double newX, double newY ) {
    x = newX;
    y = newY;
}

// modify x and y by specified amounts
void Point::move( double dx, double dy ) {
    x += dx;
    y += dy;
}

// adjust x and y such that they are rotated 90 degrees clockwise about the origin
void Point::rotate( ) {
    // if x and y are the same sign, invert y's sign
    double yTemp = x * (x * y > 0 ? -1.0 : 1.0); 
    x = y; // set new x to old y
    y = yTemp; // set new y to old x, with sign set accordingly
}

// overload the + operator to add x and y of both operands
const Point operator +(const Point& p1, const Point& p2) {
    return Point( p1.x + p2.x, p1.y + p2.y );
}

// overload the + operator to subtract x and y of p2 from p1
const Point operator -(const Point& p1, const Point& p2) {
    return Point( p1.x - p2.x, p1.y - p2.y );
}

std::istream& operator >>( std::istream& inputStream, Point& point) {
    double x, y;
    inputStream >> x >> y;
    point.set(x, y);
    return inputStream;
}

// overload the << operator to output x and y to stream as "(x,y)"
std::ostream& operator <<( std::ostream& outputStream, const Point& point ) {
    outputStream << "(" << point.getX() << "," << point.getY() << ")";
    return outputStream;
}

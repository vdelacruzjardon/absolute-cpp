/* 
Absolute C++ (5e); Ch. 6 "Structures and Classes"; Project 3
*/

#include <iostream>

class Point
{
public:
    Point();
    Point( double, double );

    double getX( ) const;
    double getY( ) const;

    void set( double, double );
    void move( double, double );
    void rotate( );

    friend const Point operator +( const Point&, const Point& );
    friend const Point operator -( const Point&, const Point& );
    friend std::istream& operator >>( std::istream&, Point& );
    friend std::ostream& operator <<( std::ostream&, const Point& );

private:
    double x, y;

};


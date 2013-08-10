/* 
Absolute C++ (5e); Ch. 8 "Operator Overloading, Friends, and References"; Project 3
*/

#include <iostream>

class Complex {
public:
    // the constructors are simple, so inline them
    Complex( ) : real(0), imaginary(0) {}; // both components zero
    Complex( double realPart )
        : real(realPart), imaginary(0) {}; // set real component, imaginary is zero
    Complex( double realPart, double imaginaryPart )
        : real(realPart), imaginary(imaginaryPart) {}; // set real component, imaginary is zero

    friend const Complex operator +( const Complex&, const Complex& );
    friend const Complex operator -( const Complex&, const Complex& );
    friend const Complex operator *( const Complex&, const Complex& );
    friend const Complex operator /( const Complex&, const Complex& );
    friend bool operator ==( const Complex&, const Complex& );

    friend std::istream& operator >>( std::istream&, Complex& );
    friend std::ostream& operator <<( std::ostream&, const Complex& );

    double real, imaginary;
};

const Complex i( 0, 1 );

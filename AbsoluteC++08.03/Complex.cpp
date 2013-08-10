/* 
Absolute C++ (5e); Ch. 8 "Operator Overloading, Friends, and References"; Project 3
*/

#include "Complex.h"

const Complex operator +( const Complex& c1, const Complex& c2 ) {
    return Complex( c1.real + c2.real, c1.imaginary + c2.imaginary );
}

const Complex operator -( const Complex& c1, const Complex& c2 ) {
    return Complex( c1.real - c2.real, c1.imaginary - c2.imaginary );
}

// (a+b*i) * (c+d*i) == (a*c -b*d) + (a*d+b*c)*i
const Complex operator *( const Complex& c1, const Complex& c2 ) {
    return Complex( c1.real * c2.real - c1.imaginary * c2. imaginary, 
        c1.real * c2.imaginary + c1.imaginary * c2.real );
}

// http://www.clarku.edu/~djoyce/complex/div.html
const Complex operator /( const Complex& c1, const Complex& c2 ) {
    double denom = c2.real * c2.real + c2.imaginary * c2.imaginary;
    if (denom == 0) {
        std::cout << "Complex number division by zero" << std::endl;
        exit( 1 );
    }
    return Complex( (c1.real * c2.real + c1.imaginary * c2.imaginary) / denom, 
        ( -c1.real * c2.imaginary + c2.real * c1.imaginary ) / denom );
}

bool operator ==( const Complex& c1, const Complex& c2 ) {
    return (c1.real == c2.real) && (c1.imaginary == c2.imaginary);
}

std::istream& operator >>( std::istream& inputStream, Complex& c ) {
    inputStream >> c.real >> c.imaginary;
    return inputStream;
}

std::ostream& operator <<( std::ostream& outputStream, const Complex& c ) {
    // don't print any sign for imaginary part if it's already negative
    outputStream << c.real << (c.imaginary < 0 ? "" : "+") << c.imaginary << "i";
    return outputStream;
}

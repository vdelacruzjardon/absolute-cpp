/* 
Absolute C++ (5e); Ch. 8 "Operator Overloading, Friends, and References"; Project 3

Define a class for complex numbers. A complex number is a number of the form 
a + b*i
where for our purposes, a and b are numbers of type double, and i is a number 
that represents the quantity sqrt(-1). Represent a complex number as two values 
of type double. Name the member variables real and imaginary. (The variable 
for the number that is multiplied by iis the one called imaginary.) Call 
the class Complex. Include a constructor with two parameters of type double
that can be used to set the member variables of an object to any values. Include a 
constructor that has only a single parameter of type double; call this parameter 
realPart and define the constructor so that the object will be initialized to 
realPart + 0*i. Include a default constructor that initializes an object to 0 (that is, to 
0+0*i). Overload all the following operators so that they correctly apply to the 
type Complex: ==, +, -, *, >>, and <<. You should also write a test program to test 
your class. Hints: To add or subtract two complex numbers, add or subtract the 
two member variables of type double. The product of two complex numbers is 
given by the following formula: 
(a+b*i) * (c+d*i) == (a*c -b*d) + (a*d+b*c)*i
  In the interface file, you should define a constant i as follows: 
const Complex i(0, 1); 
  This defined constant i will be the same as the i discussed above. 
*/

#include "Complex.h"
using namespace std;

int main( ) {
    cout << "~~~ Complex numbers driver ~~~\n\n";

    Complex c0, c1( -4.24 ), c2( 2, -3 ), c3;
    cout << "(0 arg) c0: " << c0 << "\n(1 arg) c1: " << c1 << "\n(2 arg) c2: " << c2 << "\nconst i: " << i;
    cout << "\n\nInput real and imaginary parts for a complex number c3: ";
    cin >> c3;
    cout << "c3: " << c3 << endl << endl;

    cout << "c2 + c3: " << c2 + c3 << endl;
    cout << "c2 - c3: " << c2 - c3 << endl;
    cout << "c2 * c3: " << c2 * c3 << endl;
    cout << "c2 / c3: " << c2 / c3 << endl;
    cout << "c2 ==? c3: " << (c2==c3 ? "yes" : "no") << endl << endl;

    return 0;
}
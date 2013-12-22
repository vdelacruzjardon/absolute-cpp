/*
Absolute C++ (5e); Ch. 10 "Pointers and Dynamic Arrays"; Project 2

Using dynamic arrays, implement a polynomial class with polynomial addition, 
subtraction, and multiplication. 

  Discussion: A variable in a polynomial does nothing but act as a placeholder for 
the coefficients. Hence, the only interesting thing about polynomials is the array 
of coefficients and the corresponding exponent. Think about the polynomial 
x*x*x + x + 1 
  Where is the term in x*x? One simple way to implement the polynomial class is to 
use an array of doubles to store the coefficients. The index of the array is the 
exponent of the corresponding term. If a term is missing, then it simply has a zero 
coefficient.
  There are techniques for representing polynomials of high degree with many missing 
terms. These use so-called sparse matrix techniques. Unless you already know 
these techniques, or learn very quickly, do not use these techniques. 
  Provide a default constructor, a copy constructor, and a parameterized constructor 
that enables an arbitrary polynomial to be constructed. 
  Supply an overloaded operator = and a destructor. 
  Provide these operations: 
polynomial +polynomial, constant +polynomial, polynomial + constant, 
polynomial -polynomial, constant -polynomial, polynomial - constant. 
polynomial *polynomial, constant *polynomial, polynomial * constant, 
  Supply functions to assign and extract coefficients, indexed by exponent. 
  Supply a function to evaluate the polynomial at a value of type double. 
  You should decide whether to implement these functions as members, friends, or 
standalone functions. 
*/

#include "Polynomial.h"
using std::cout;
using std::cin;
using std::endl;
using ncoop::Polynomial;

typedef double* DblPtr;

int main( ) {
    cout << "~~~ Polynomial class driver ~~~\n";
    cout << "Reminder: an n-term polynomial goes up to x^(n-1).\n\n";

    double init[] = {1.1, -2.2, 3.3};

    Polynomial p0(3, init);
    p0.setCoef(0, 3.3);
    p0.setCoef(4, -1.1);
    p0.setCoef(2, +2.2);

    cout << "p0 after default constructor and set coef:\n";
    cout << p0 << endl << endl;

    cout << "copy p0 to p1:\n";
    Polynomial p1(p0);
    cout << p0 << endl << endl;

    cout << "testing getCoef:\n";
    cout << "p1.getCoef(3) = " << p1.getCoef(3) << ", p1.getCoef(4) = " << p1.getCoef(4) << 
        ", p1.getCoef(-5) = " << p1.getCoef(-5) << endl << endl;

    cout << "p1 = p1 * 3, clearCoef(0):\n";
    p1 = p1 * 3;
    cout << p1.clearCoef(0) << endl;
    cout << "p1 at x = 2.0: " << p1.eval(2.0) << endl << endl;
    /*
    cout << "-p1:\n";
    cout << -p1 << endl;
    cout << "p1 + 8.8:\n";
    cout << p1 + 8.8 << endl;
    cout << "-7.7 + p1:\n";
    cout << 7.7 + p1 << endl;
    cout << "p1 - 4.4:\n";
    cout << p1 - 4.4 << endl;
    cout << "5.5 - p1:\n";
    cout << 5.5 - p1 << endl;
    cout << "-4 * p1:\n";
    cout << -4 * p1 << endl;
    */
    cout << "p0 + p1:\n";
    cout << p0 + p1 << endl;
    cout << "p0 - p1:\n";
    cout << p0 - p1 << endl;

    cout << "p0 * p1:\n";
    cout << p0 * p1 << endl;

    cout << "\n~~~ driver program complete ~~~\n";

    return 0;
}

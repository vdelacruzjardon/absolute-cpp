/*
Absolute C++ (5e); Ch. 10 "Pointers and Dynamic Arrays"; Project 2
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream> // for << and >> overloads

namespace ncoop {
    class Polynomial {
    public:
        Polynomial( ); // construct a polynomial of order 0
        Polynomial( size_t n ); // construct a polynomial of order n with all zero coefficients
        Polynomial( size_t n, const double* cArray ); // construct a polynomial with n terms and the given coefficients
        Polynomial( const Polynomial& ); // copy constructor
        ~Polynomial( );

        const Polynomial operator -( ) const; // negation
        Polynomial& operator =( const Polynomial& ); // = operator returns a reference to a new object

        friend const Polynomial operator +( const Polynomial&, const Polynomial& );
        friend const Polynomial operator +( double, const Polynomial& );
        friend const Polynomial operator +( const Polynomial&, double );

        friend const Polynomial operator -( const Polynomial&, const Polynomial& );
        friend const Polynomial operator -( double, const Polynomial& );
        friend const Polynomial operator -( const Polynomial&, double );

        friend const Polynomial operator *( const Polynomial&, const Polynomial& );
        friend const Polynomial operator *( double, const Polynomial& );
        friend const Polynomial operator *( const Polynomial&, double );

        friend std::ostream& operator <<( std::ostream&, const Polynomial& );
        friend std::ostream& operator <<( std::ostream&, const Polynomial* );

        double getCoef( size_t ) const;
        // setter members return a reference to the modified "this"
        Polynomial& setCoef( size_t, double );
        Polynomial& clearCoef( size_t );

        double eval( double ); // evaluates the entire polynomial given the value of x

    private:
        double *coef; // an array of coefficients where coef[n] is c in c*x^n
        size_t terms; // the highest x^n index n in this polynomial is terms-1

        Polynomial& multiplyBy( double c, size_t n ); // multiplies this by c*x^n
        static double pow( size_t n, double x ); // evaluates x to the n power (non-negative integer)

    }; // class Polynomial
} // namespace ncoop

#endif

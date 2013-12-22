/*
Absolute C++ (5e); Ch. 10 "Pointers and Dynamic Arrays"; Project 2
*/

#include "Polynomial.h"
using ncoop::Polynomial;

// default constructor creates only a polynomial with one x^0 term which is zero
Polynomial::Polynomial( ) : terms(1) {
    coef = new double[terms];
    coef[0] = 0.0;
}

// parameterized constructor with only array size
Polynomial::Polynomial( size_t n ) : terms(n) {
    coef = new double[terms];
    for (size_t i = 0; i < terms; i++)
        coef[i] = 0.0;
}

// parameterized constructor with both size and array contents
Polynomial::Polynomial( size_t n, const double* cArray ) : terms(n) {
    coef = new double[terms];
    for (size_t i = 0; i < terms; i++)
        coef[i] = cArray[i];
}

// copy constructor
Polynomial::Polynomial( const Polynomial& source ) : terms(source.terms) {
    coef = new double[terms];
    for (size_t i = 0; i < terms; i++)
        coef[i] = source.coef[i];
}

Polynomial::~Polynomial( ) {
    delete [] coef;
}

// unary - overload
const Polynomial Polynomial::operator -( ) const {
    Polynomial neg(*this); // copy
    for (size_t i = 0; i <= neg.terms; i++)
        neg.coef[i] *= -1; // negate each coefficient
    return neg;
}

// = operator overload
Polynomial& Polynomial::operator =( const Polynomial& rValue ) {
    if (terms != rValue.terms) {
        delete [] coef;
        coef = rValue.coef;
    }

    terms = rValue.terms;
    for (size_t i = 0; i < terms; i++)
        coef[i] = rValue.coef[i];

    return *this;
}

// multiplies this by c*x^n
Polynomial& Polynomial::multiplyBy( double c, size_t n ) {
    size_t newTerms = terms + n;
    double *newCoef = new double[newTerms];
    for (size_t i = 0; i < terms; i++)
        newCoef[i + n] = c * coef[i]; // multiply and promote the old terms
    for (size_t i = terms; i < newTerms; i++)
        newCoef[i - terms] = 0.0; // initialize the new, lower terms

    delete [] coef; // dismiss old array
    coef = newCoef; // link new array
    terms = newTerms;
    return *this;
}

namespace ncoop { // defining friend functions that were declared in this namespace

    // polynomial plus a polynomial
    const Polynomial operator +( const Polynomial& poly1, const Polynomial& poly2 ) {
        // make the sum object start as a copy of the operand that has more terms
        Polynomial larger = poly1, smaller = poly2;
        if ( poly1.terms < poly2.terms )
            larger = poly2, smaller = poly1;

        Polynomial sum(larger); // copy whichever had more terms
        for (size_t i = 0; i < smaller.terms; i++) // add coefs for smaller (shared) terms
            sum.coef[i] += smaller.coef[i];
        return sum;
    }

    // constant plus a polynomial
    const Polynomial operator +( double c, const Polynomial& poly ) {
        Polynomial copy(poly);
        copy.coef[0] += c;
        return copy;
    }

    // polynomial plus a constant
    const Polynomial operator +( const Polynomial& poly, double c ) {
        return c + poly; // reverse the operands
    }

    // polynomial minus a polynomial
    const Polynomial operator -( const Polynomial& poly1, const Polynomial& poly2 ) {
        return Polynomial(poly1 + -poly2); // add the negated right operand
    }

    // constant minus a polynomial
    const Polynomial operator -( double c, const Polynomial& poly ) {
        return c + -poly; // add the negated right operand
    }

    // polynomial minus a constant
    const Polynomial operator -( const Polynomial& poly, double c ) {
        return poly + -c; // add the negated right operand
    }

    // polynomial times a polynomial
    const Polynomial operator *( const Polynomial& poly1, const Polynomial& poly2 ) {
        //stub
        Polynomial prod(poly2); // copy the right operand
        //prod.multiplyBy(.5, 2);
        for (size_t i = 0; i < poly1.terms; i++) // multiply it by each term of the left operand
            prod.multiplyBy(poly1.coef[i], i);
        return prod;
    }

    // constant times a polynomial
    const Polynomial operator *( double c, const Polynomial& poly ) {
        Polynomial copy(poly);
        for (size_t i = 0; i < copy.terms; i++)
            copy.coef[i] *= c; // distribute the constant to each coef
        return copy;
    }

    // polynomial times a constant
    const Polynomial operator *( const Polynomial& poly, double c ) {
        return c * poly; // reverse operands
    }

    // overload the << operator
    std::ostream& operator <<(std::ostream& outputStream, const Polynomial& poly ) {
        outputStream << poly.terms << " terms: ";
        if (poly.terms <= 1)
            return outputStream << 0;
        for (size_t n = poly.terms-1; n < poly.terms; n--) { // start at the highest-order terms
            double c = poly.coef[n];
            if (c == 0.0)
                continue; // do not output zero coef terms
            if (n < poly.terms-1 && c > 0)
                outputStream << "+"; // append + sign if the coef is positive and not the first term
            outputStream << c; // append the coefficient
            if (n > 0)
                outputStream << "*x"; // do not output *x for x^0
            if (n > 1)
                outputStream << "^" << n; // do not output exponent for powers less than 2
            outputStream << " "; // space between each term
        }
        return outputStream;
    }

    // make << operate on the referent
    std::ostream& operator <<(std::ostream& outputStream, const Polynomial* poly ) {
        return outputStream << *poly;
    }

} // namespace ncoop

double Polynomial::getCoef( size_t n) const {
    if (n > terms-1)
        return 0.0; // undefined/out-of-range coefficients are zero
    return coef[n];
}

Polynomial& Polynomial::setCoef( size_t n, double c ) {
    if (n > terms-1) { // if the array is too small for the new coef...
        double *newCoef = new double[n+1]; // create and fill out a new coef array with the larger order
        for (size_t i = 0; i < terms; i++) // first copy over old coef values
            newCoef[i] = coef[i];
        for (size_t i = terms; i < n+1; i++) // fill out the new, higher values with zero
            newCoef[i] = 0.0;
        delete [] coef; // free up space taken by old array
        coef = newCoef; // assign coef to new array
        terms = n+1; // set to new order
    }
    coef[n] = c; // change coefficient
    return *this;
}

Polynomial& Polynomial::clearCoef( size_t n ) {
    if ( n < terms )
        coef[n] = 0.0;
    return *this;
}

double Polynomial::pow( size_t i, double x ) { // whole number exponentiation function
    if (i == 0) // x^0 = 1
        return 1;
    double total(x);
    for (size_t n = 1; n < i; n++)
        total *= x;
    return total;
}

// evaluates the entire polynomial given the value of x
double Polynomial::eval( double x ) {
    double total(coef[0]);
    if (x == 0.0) // if x is zero, all higher terms are zero
        return total;

    for (size_t i = 1; i < terms; i++) // skip x^0 case since total is already coef[0]
        if (coef[i] != 0.0) // skip term if coefficient is zero
            total += coef[i] * pow( i, x );
            //std::cout << "i: " << i << ", c[i]: " << coef[i] << ", x^i: " << pow( x, i ) << ", c[i] * x^i: " << coef[i] * pow( x, i ) << ", total: " << total << std::endl;
    return total;
}

/* 
Absolute C++ (5e); Ch. 4 "Parameters and Overloading"; Project 15

Write a function named convertToLowestTerms that inputs two integer parameters 
by reference named numerator and denominator. The function should treat 
these variables as a fraction and reduce them to lowest terms. For example, if 
numerator is 20 and denominator is 60, then the function should change the 
variables to 1 and 3, respectively. This will require finding the greatest common 
divisor for the numerator and denominator then dividing both variables by that 
number. If the denominator is zero, the function should return false, otherwise the 
function should return true. Write a test program that uses convertToLowestTerms
to reduce and output several fractions.
*/

#include <iostream>
using namespace std;

bool convertToLowestTerms( int& numerator, int& denominator );

int main( ) {
    cout << "~~~ convertToLowestTerms driver program ~~~\n";
    cout << "Enter numerator and denominator pairs to test. Enter two zeros to quit.\n";

    do {
        int num, denom;
        cout << "\nnum denom: ";
        cin >> num >> denom;
        if (num == 0 && denom == 0) 
            break;
        if (convertToLowestTerms( num, denom ))
            cout << "reduced to: " << num << "/" << denom << endl;
        else
            cout << "invalid denominator 0" << endl;
    } while (true);

    return 0;
}

bool convertToLowestTerms( int& numerator, int& denominator ) {
    if (denominator == 0) // invalid denominator; fail
        return false;
    if (numerator == 0) { // just return 0/1
        denominator = 1;
        return true;
    }

    // get absolute values to work with negatives, but preserve sign first
    int sign = numerator * denominator < 0 ? -1 : 1;
    numerator = numerator > 0 ? numerator : -numerator;
    denominator = denominator > 0 ? denominator: -denominator;

    // highest possible factor is the lower absolute value
    int highestPossible = numerator < denominator ? numerator : denominator;

    int factor;
    for (factor = highestPossible; factor > 0; factor--)
        if (numerator % factor == 0 && denominator % factor == 0) // check if the factor is common
            break; // this is the GCF, so stop

    // found the GCF: now divide both args by it
    numerator /= factor;
    denominator /= factor;

    // restore sign
    numerator *= sign;

    return true; // success
}

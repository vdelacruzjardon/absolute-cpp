/* 
Absolute C++ (5e); Ch. 1 "C++ Basics"; Project 8

The Babylonian algorithm to compute the square root of a positive number n is as 
follows:
  1.  Make a guess at the answer (you can pick n/2 as your initial guess). 
  2.  Compute r = n / guess. 
  3.  Set guess = (guess + r) / 2. 
  4.  Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 
      are repeated, the closer guess will become to the square root of n. 
  Write a program that inputs a double for n, iterates through the Babylonian algorithm 
  five times, and outputs the answer as a double to two decimal places. Your 
  answer will be most accurate for small values of n.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main( ) {
    const unsigned int PRECISION = 4, ITERATIONS = 5;
    double n, r, guess;

    cout << "Enter a positive number to get the square root of: ";
    cin >> n;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(PRECISION);

    guess = n/2;
    for (unsigned int i = 0; i < ITERATIONS; i++) {
        r = n / guess;
        guess = (guess + r) / 2;
        cout << guess << "\t";
    }
    cout << endl;
    cout << "math.h gives sqrt(" << n << ") = " << sqrt(n) << endl;

    return 0;
}
/* 
Absolute C++ (5e); Ch. 13 "Recursion"; Project 1

Write a recursive function definition for a function that has one parameter n of 
type int and that returns the nth Fibonacci number. The Fibonacci numbers are 
F(0) is 1, F(1) is 1, F(2) is 2, F(3) is 3, F(4) is 5, and in general 
F(i+2) = F(i) + F(i+1) for i = 0, 1, 2, ...

*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int fibonacciR( const int& n );

int main( ) {
    int n, f;
    cout << "~~~ Fibonacci numbers ~~~\n";
    cout << "Enter a negative integer to quit.\n";
    while (true) {
        cout << "\nEnter an integer n to find the nth Fibonacci number: ";
        cin >> n;
        if (n < 0) 
            break;
        f = fibonacciR(n);
        cout << "F(" << n << ") = " << f << endl;
    }

    return 0;
}

int fibonacciR( const int& n ) {
    if (n <= 1)
        return 1;
    else {
        return fibonacciR( n-2 ) + fibonacciR( n-1 );
    }
}

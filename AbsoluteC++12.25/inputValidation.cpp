/*
Absolute C++ (5e); Ch. 12 "Streams and File I/O"; Project 25

One problem using cin to read directly into a variable such as an int is that if the 
user enters non-integer data then the program will continue with erroneous data 
and usually crash. A solution to this problem is to input data as a string, perform 
input validation, and then convert the string to an integer. Write a function that 
prompts the user to enter an integer. The program should use getline to read the 
user’s input into a string. Then use the stringstream class to extract an integer 
from the string. If an integer cannot be extracted then the user should be prompted 
to try again. The function should return the extracted integer. 

*/

#define QUITCHAR 'X'
#include <iostream> // cin, cout, endl
#include "stringParser.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main( ) {
    cout << "~~~ Console input validation with stringstream ~~~\n";

    while (true) {
        string input;
        cout << "\nEnter a line with (or without) an integer, or " << QUITCHAR << " to quit: ";
        getline(cin, input);
        if ( input.size( ) < 1 ) // blank input; retry
            continue;
        if ( toupper(input.at(0)) == QUITCHAR ) // user wants to quit; break out
            break;
        cout << "   Entered string: " << input << endl;
        ncoop::stringParse sp(input);
        if ( sp.isValid( ) )
            cout << "Integer extracted: " << sp.getInt( ) << endl;
        else
            cout << "Could not extract an integer from the input." << endl;
    }

    return 0;
}

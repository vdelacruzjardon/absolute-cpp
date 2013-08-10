/* 
Absolute C++ (5e); Ch. 13 "Recursion"; Project 12

The following diagram is an example of a deterministic finite state automaton,  or 
DFA. This particular DFA describes an algorithm to determine if a sequence of 
characters is a properly formatted monetary amount with commas. For example, 
“$1,000” and “$25” and “$551,323,991,391” are properly formatted but “1,000” 
(no initial $) and “$1000” (missing comma) and “$5424,132” (missing comma) 
are not.

The DFA works by starting in the oval labeled IsMoney. This is the initial state. If 
the first character of the string is $, then we advance to the second character and 
move to state 0. Otherwise we conclude the string is not a proper monetary amount. 
In state 0, if the second character is a digit between 1 and 9, then we advance to 
the third character and move to state 1. Otherwise we conclude the string is not 
a proper monetary amount. In state 1, if we have no more characters left in the 
string, then we conclude that the string is a monetary amount. This is called a 
final state and is indicated by a bold oval. If the third character is a digit between 
0 and 9, then we advance to the fourth character and move to state 2. Otherwise 
if the third character is a comma then we advance to the fourth character and 
move to state 4. Otherwise we conclude the string is not a proper monetary 
amount. The rest of the DFA behaves in a similar manner. 
  Write a program that uses recursion to implement the DFA. Your program should 
have a separate function for each state in the DFA. Each function should invoke 
the function corresponding to the next state indicated by the arrows in the diagram. 
There is mutual recursion because of the loop from state 7 to state 4. Test 
your solution with several strings and output whether each string is a properly 
formatted monetary amount. 
  This solution calls a function for every character in the string. However, the solution 
may be written in a tail-recursive manner, so it is possible that long strings will 
not exhaust the stack if your compiler is efficient.

*/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

bool isMoney( const char*, size_t );
bool state0( const char*, size_t );
bool state1( const char*, size_t );
bool state2( const char*, size_t );
bool state3( const char*, size_t );
bool state4( const char*, size_t );
bool state5( const char*, size_t );
bool state6( const char*, size_t );
bool state7( const char*, size_t );
void recursivePrint( const char*, size_t );
void recursivePrint( const char& );

int main( ) {
    cout << "This program implements a DFA to decide if a character sequence is a properly\n" <<
        "formatted monetary amount with commas.\n" << 
        "  Valid example: \"$1,000\"\n" <<
        "Invalid examples: \"1,000\" \"$1000\" \"$10,00\"\n";

    while (true) {
        char input[CHAR_MAX];
        cout << "\nEnter a character sequence to test, or X to quit: ";
        cin >> input;
        if ( toupper(input[0]) == 'X' ) // sentinel breakout value
            break;
        cout << "That " << ( isMoney(input, 0) ? "is" : "is not" ) << " a valid monetary amount.\n";
        //recursivePrint( input, 0 );
    }

    return 0;
}

// first char must be $
bool isMoney( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c == '$' )
        return state0( cstr, i+1 );
    return false;
}

// first char after $ must be 1-9
bool state0( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '1' && c <= '9' )
        return state1( cstr, i+1 );
    return false;
}

// char after 1 digit must be 0-9 or , or end
bool state1( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c >= '0' && c <= '9' )
        return state2( cstr, i+1 );
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// char after 2 digits must be 0-9 or , or end
bool state2( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c >= '0' && c <= '9' )
        return state3( cstr, i+1 );
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// char after 3 digits must be , or end
bool state3( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// 1st char after , must be 0-9
bool state4( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state5( cstr, i+1 );
    return false;
}

// 2nd char after , must be 0-9
bool state5( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state6( cstr, i+1 );
    return false;
}

// 3rd char after , must be 0-9
bool state6( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return false;
    if ( c >= '0' && c <= '9' )
        return state7( cstr, i+1 );
    return false;
}

// after , and 3 digits, must be another digit or end
bool state7( const char* cstr , size_t i ) {
    char c = cstr[i];
    if ( c == NULL )
        return true;
    if ( c == ',' )
        return state4( cstr, i+1 );
    return false;
}

// testing C-string recursion
void recursivePrint( const char* cstr, size_t i ) {
    char c = cstr[i];
    if ( c == NULL ) // reached the end of the string
        return;
    cout << c; // print this char
    recursivePrint( cstr, i+1 ); // do the next char
}

void recursivePrint( const char& char_addr ) {
    char c = char_addr;
    cout << c;
}

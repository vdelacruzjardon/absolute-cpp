/* 
Absolute C++ (5e); Ch. 9 "Strings"; Project 1

Write a program that will read in a sentence of up to 100 characters and output 
the sentence with spacing corrected and with letters corrected for capitalization. 
In other words, in the output sentence all strings of two or more blanks should be 
compressed to a single blank. The sentence should start with an uppercase letter 
but should contain no other uppercase letters. Do not worry about proper names; 
if their first letter is changed to lowercase, that is acceptable. Treat a line break as 
if it were a blank in the sense that a line break and any number of blanks are compressed 
to a single blank. Assume that the sentence ends with a period and contains 
no other periods. For example, the input 

the Answer to life, the Universe, and everything 
IS 42. 
  should produce the following output: 

The answer to life, the universe, and everything is 42. 

*/

#define MAXCHARS 100
#define ENDCHAR '.'
#define SPACECHAR ' '
#include <iostream>
#include <string>
// #include <cctype> // not needed for toupper and tolower?
using namespace std;

const void processString( char tgt[], char src[] );
const void processString( string& tgt, char src[] );

int main( ) {
    char str[MAXCHARS], correctCstring[MAXCHARS]; // cstring with imposed size
    string correctString; // string object

    cout << "~~~ Capitalization and Spacing Corrector ~~~\n";
    cout << "\nEnter a sentence to check, up to " << MAXCHARS << 
        " characters long, ending with a period, \nand containing no other periods:\n";

    cin.getline(str, MAXCHARS, ENDCHAR); // this stops at the period but doesn't record it
    str[strlen(str) + 1] = str[strlen(str)]; // copy null char one space over
    str[strlen(str)] = ENDCHAR; // add period to previous end of string

    cout << "\nOriginal string, " << strlen(str) << " characters long:\n";
    cout << str << endl << endl;

    processString( correctCstring, str );
    cout << "Processed as a cstring, " << strlen(correctCstring) << " characters long:\n";
    cout << correctCstring << endl << endl;

    processString( correctString, str );
    cout << "Processed as a string object, " << correctString.length() << " characters long:\n";
    cout << correctString << endl << endl;

    return 0;
}

const void processString( char tgt[], char src[] ) {
    bool firstChar(true), inSpace(false);
    int j(0); // position of index in corrected string
    for (int i = 0; i < MAXCHARS; i++) {
        if ( firstChar ) { // first character of the sentence
            if ( isalpha( src[i] ) ) { // copy alpha as toupper
                tgt[j++] = toupper( src[i] );
                firstChar = false;
            } // do not copy unless isalpha
        } else if ( !isspace( src[i] ) ) { // copy nonspace as tolower
            inSpace = false;
            tgt[j++] = tolower( src[i] );
        } else if ( !inSpace && isspace( src[i] ) ) { // first space after nonspace
            inSpace = true;
            tgt[j++] = SPACECHAR;
        } // subsequent spaces after first space do not get copied
    }
    if (tgt[strlen(tgt)-2] == SPACECHAR) { // correct it if a space precedes the period
        tgt[strlen(tgt)-2] = tgt[strlen(tgt)-1];
        tgt[strlen(tgt)-1] = tgt[strlen(tgt)];
    }

    return;
}

const void processString( string& tgt, char src[] ) {
    string ssrc = src; // convert C-string to string object

    bool firstChar(true), inSpace(false);
    for (unsigned int i = 0; i < ssrc.length(); i++) {
        if ( firstChar ) { // first character of the sentence
            if ( isalpha( ssrc.at(i) ) ) { // copy alpha as toupper
                tgt += toupper( ssrc.at(i) );
                firstChar = false;
            } // do not copy unless isalpha
        } else if ( !isspace( ssrc.at(i) ) ) { // copy nonspace as tolower
            inSpace = false;
            tgt += tolower( ssrc.at(i) );
        } else if ( !inSpace && isspace( ssrc.at(i) ) ) { // first space after nonspace
            inSpace = true;
            tgt += SPACECHAR;
        } // subsequent spaces after first space do not get copied
    }
    if ( tgt.at( tgt.length()-2 ) == SPACECHAR ) { // correct it if a space precedes the period
        tgt.erase( tgt.length()-2, 1 );
    }

    return;
}

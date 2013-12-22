/* 
Absolute C++ (5e); Ch. 9 "Strings"; Project 11

Write a function that determines if two strings are anagrams. The function 
should not be case sensitive and should disregard any punctuation or spaces. 
Two strings are anagrams if the letters can be rearranged to form each other. 
For example, “Eleven plus two” is an anagram of “Twelve plus one”. Each string 
contains one “v”, three “e’s”, two “l’s”, etc. Test your function with several 
strings that are anagrams and non-anagrams. You may use either the string class 
or a C-style string.

*/

#include "AnagramDetector.h"
#include <iostream>
using namespace std;

int main( ) {

    cout << "~~~ Anagram Detector ~~~\n";
    cout << "\nThis program checks if two strings are anagrams. Enter an empty string to quit.\n";
    do {
        string s1, s2;
        cout << "\nEnter string 1:\n";
        getline(cin, s1);
        if ( s1.empty( ) )
            break;
        cout << "\nEnter string 2:\n";
        getline(cin, s2);
        if ( s2.empty( ) )
            break;

        Anagram a( s1, s2 );
        try {
            a.process( ); // may throw BadString

            cout << endl;
            cout << "len " << a.getProcessed(1).length() << "\t" << a.getProcessed(1) << endl;
            cout << "len " << a.getProcessed(2).length() << "\t" << a.getProcessed(2) << endl;

            bool yes = a.isAnagram( ); // may throw BadString
            cout << "\nThe strings " << ( yes ? "ARE" : "ARE NOT" ) << " anagrams.\n";
        } 
        catch (Anagram::BadString e) {
            cout << endl << e.getMessage( ) << endl;
        }
    } while (true);

    return 0;
}

/* 
Absolute C++ (5e); Ch. 9 "Strings"; Project 11
*/

#include "AnagramDetector.h"

void Anagram::setString( string str, int i ) {
    if ( i == 1 ) {
        s1 = str;
        return;
    }
    if ( i == 2 ) {
        s2 = str;
        return;
    }
    throw BadString( "There is no string s" + i );
}

const string Anagram::getProcessed( int i ) const {
    if ( i == 1 ) return s1processed;
    if ( i == 2 ) return s2processed;
    throw BadString( "There is no string s" + i );
}

void Anagram::process( ) {
    if ( s1.empty( ) )
        throw BadString( "String 1 is empty." );
    if ( s2.empty( ) )
        throw BadString( "String 2 is empty." );

    s1processed = stringSort( lowerAlpha( s1 ) );
    s2processed = stringSort( lowerAlpha( s2 ) );
    return;
}

bool Anagram::isAnagram( ) const { 
    if ( s1processed.empty( ) )
        throw BadString( "String 1 is empty after processing." );
    if ( s2processed.empty( ) )
        throw BadString( "String 2 is empty after processing." );

    return s1processed == s2processed; // string objects can be compared with ==
}

const string Anagram::stringSort( const string& str ) const {
    char cstr[MAXSTRING]; // declare a big C-string
    strcpy_s( cstr, str.c_str( ) ); // convert object to C-string

    for (size_t i = 0; i < str.length(); i++ ) {
        for (size_t j = 0; j < str.length(); j++ ) {
            if (cstr[j] > cstr[i]) {
                char temp = cstr[j];
                cstr[j] = cstr[i];
                cstr[i] = temp;
            }
        }
    }

    return cstr; // returned C-string is converted back to a string object
}

const string Anagram::lowerAlpha( const string& str ) const {
    string tgt;
    for (size_t i = 0; i < str.length(); i++ ) {
        if ( isalpha( str.at(i) ) ) { // if alpha ...
            tgt += tolower( str.at(i) ); // tolower, then copy to target string
        } // ... don't copy if not alpha
    }
    return tgt;
}

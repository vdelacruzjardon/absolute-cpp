/* 
Absolute C++ (5e); Ch. 9 "Strings"; Project 11
*/

#define MAXSTRING 200
#include <string>
using namespace std;

class Anagram {
public:
    Anagram( );
    Anagram( string s1 ) : s1(s1) {};
    Anagram( string s1, string s2 ) : s1(s1), s2(s2) {};

    // set si to str
    void setString( string str, int i=1 );

    // return siprocessed
    const string getProcessed( int i=1 ) const;

    // convert s1 and s2 to their processed forms
    void process( );

    // return true if the strings are anagrams
    bool isAnagram( ) const;

private:
    // strip non-alpha characters, and make alpha lowercase
    const string lowerAlpha( const string& ) const;

    // sort the characters in a string as a char array
    const string stringSort( const string& ) const;

    string s1, s2, s1processed, s2processed;

public:
    // exception to be thrown if a string is empty during process or isAnagram
    class BadString {
        public:
            BadString( ) {};
            BadString( string message ) : message( message ) {};
            const string getMessage( ) const { return message; }

        private:
            string message;

    };

};

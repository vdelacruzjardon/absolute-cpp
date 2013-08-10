/*
Absolute C++ (5e); Ch. 12 "Streams and File I/O"; Project 25
*/

#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <sstream> // stringstream
#include <string> // string

namespace ncoop {
    using std::string;

    class stringParse {
    public:
        stringParse( ) : valid(false) {};
        stringParse( string s ) : str(s) { parseInt( ); };

        void setString( string s ) {str = s;};
        string getString( ) {return str;};
        int getInt( ) {return value;}
        bool isValid( ) {return valid;}

    private:
        string str;
        int value;
        bool valid;

        int parseInt( ) {
            // declare and initialize
            std::stringstream ss;
            ss.clear( );
            ss.str(str);

            valid = false;
            if (ss >> value)
                valid = true;
            return value;
        }

    };
} // namespace ncoop

#endif // STRING_PARSER_H

/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 5
*/

#include "userPassword.h"

namespace { // declaring local variable and function in unnamed namespace
    string password;

    bool isValid( ) {
        if (password.length( ) < 8)
            return false; // password requires at least 8 characters
        for (size_t i = 0; i < password.length( ); i++) {
            if (!isalpha( password.at(i) ) ) {
                return true; // found at least one non-letter
            }
        }
        return false; // didn't find any non-letters
    }
}

namespace Authenticate 
{
    void inputPassword( ) 
    {
        do
        {
            cout << "Enter your password (at least 8 characters " << 
            "and at least one non-letter)" << endl; 
            cin >> password; 
        } while (!isValid( )); 
    }
    string getPassword( ) 
    {
        return password; 
    }
}

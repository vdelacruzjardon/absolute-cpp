/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 5
*/

#include "userPassword.h"

namespace { // declaring local variable and function in unnamed namespace
    string username;

    bool isValid( ) {
        if (username.length() != 8)
            return false; // username must be exactly 8 characters
        for (size_t i = 0; i < username.length( ); i++) {
            if (!isalpha( username.at(i) ) ) {
                return false; // only letters allowed
            }
        }
        return true;
    }
}

namespace Authenticate 
{
    void inputUserName( ) 
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl; 
            cin >> username; 
        } while (!isValid( )); 
    }
    string getUserName( ) 
    {
        return username; 
    }
}

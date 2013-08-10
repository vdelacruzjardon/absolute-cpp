/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 5

This Programming Project explores how the unnamed namespace works. Listed are 
snippets from a program to perform input validation for a username and password. 
The code to input and validate the username is in a separate file than the code to 
input and validate the password.

Define the usernamevariable and the isValid( )function in the unnamed 
namespace so the code will compile. The isValid( )function should return true
if username contains exactly eight letters. Generate an appropriate header file for 
this code.

Repeat the same steps for the file password.cpp, placing the password variable 
and the isValid( ) function in the unnamed namespace. In this case, the 
isValid( ) function should return true if the input password has at least eight 
characters including at least one non-letter. 

At this point, you should have two functions named isValid( ), each in different 
unnamed namespaces. Place the following main function in an appropriate place. 
The program should compile and run. 

Test the program with several invalid usernames and passwords. 

*/

#include "userPassword.h"
using namespace Authenticate;

int main( ) 
{
    inputUserName( ); 
    inputPassword( ); 
    cout << "Your username is " << getUserName( ) << 
    " and your password is: " << 
    getPassword( ) << endl; 
    return 0; 
}
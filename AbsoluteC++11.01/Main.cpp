/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 1

This exercise is intended to illustrate namespaces and separate compilation in your 
development environment. You should use the development environment you regularly 
use in this course for this exercise. In a file f.h, place a declaration of void f( )
in namespace A. In a file g.h, place a declaration of void g( ) in namespace A. In files 
f.cpp and g.cpp, place the definitions of void f( ) and void g( ),  respectively. 
Place the definitions of void f( ) and void g( ) in namespace A. The functions 
can do anything you want, but to keep track of execution include something like 
cout << "Function_Name called" << endl; 
where Function_Name is the name of the particular function. In another file, main.cpp, 
put your main function, #include the minimum collection of files to provide 
access to the names from namespace A. In your main function call the functions 
f then g. Compile, link, and execute using your development environment. To provide 
access to names in namespaces, you may use local using declarations such as 
using std::cout; 
  or use local using directives such as 
using namespace std; 
  inside a block, or qualify names using the names of namespaces, such as std::cout. 
You may not use global namespace directives such as the following which are not 
in a block and apply to the entire file: 
using namespace std; 
  Of course you must handle namespace A and function names f and g, in addition 
to possibly std and cout. 
  After doing this, write a one page description of how to create and use namespaces 
and separate compilation in your environment. 
*/

#include "f.h"
#include "g.h"
using std::cout;

int main( ) {
    cout << "~~~ Namespace experiments ~~~\n\n";

    cout << "\ncalling from namespace A with \"A::\"\n";
    A::f( );
    A::g( );

    cout << "\ncalling from namespace A with \"using namespace A\" directive in a block\n";
    {
        using namespace A;
        f( );
        g( );
    }

    cout << "\ncalling from namespace A with \"using A::\" declarations\n";
    using A::f;
    using A::g;
    f( );
    g( );

    return 0;
}

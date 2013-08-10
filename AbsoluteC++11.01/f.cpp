/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 1
*/

#include "f.h"

namespace A {
    void f( ) {
        std::cout << "f called\n";
    }
}

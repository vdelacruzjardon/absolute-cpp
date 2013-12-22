/*
Absolute C++ (5e); Ch. 11 "Separate Compilation and Namespaces"; Project 1
*/

#include "g.h"

namespace A {
    void g( ) {
        std::cout << "g called\n";
    }
}

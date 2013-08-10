/* 
Absolute C++ (5e); Ch. 7 "Constructors and Other Tools"; Project 5
*/

#include "Suitors.h"

Suitors::Suitors( unsigned int initial, unsigned int letters) : letters(letters) {
    // declare the vector to the given size and populate it with ints counting from 1
    vector<unsigned int> newVector(initial);
    suitorList = newVector; 
    for (current = 0; current < suitorList.size( ); current++) {
        suitorList[current] = current + 1;
    }

    // reset current for the first elimination
    current = 0;
}

// accessors
unsigned int Suitors::getRemaining( ) const {
    return suitorList.size( );
}

unsigned int Suitors::getSuitor( unsigned int n ) const {
    return suitorList[n];
}

unsigned int Suitors::getCurrentSuitor( ) const {
    return suitorList[current];
}

unsigned int Suitors::getLetters( ) const {
    return letters;
}

// one round of elimination; returns eliminated member
unsigned int Suitors::eliminate( ) {
    // skip letters-1 suitors
    for (unsigned int n = 0; n < letters-1; n++) {
        current++;
        current = current >= suitorList.size( ) ? 0 : current; // current overflows to 0
    }
    // erase the (letters-1)th suitor
    unsigned int elim = suitorList[current];
    suitorList.erase(suitorList.begin( ) + current);
    current = current >= suitorList.size( ) ? 0 : current; // current overflows to 0
    return elim;
}

// overload the << operator to output a space separated list of each surviving member
std::ostream& operator <<( std::ostream& outputStream, const Suitors& suitors) {
    for (unsigned int n = 0; n < suitors.getRemaining( ); n++) 
        outputStream << suitors.getSuitor( n ) << " ";
    return outputStream;
}

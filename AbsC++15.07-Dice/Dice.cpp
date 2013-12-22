/*
Absolute C++ (5e); Ch. 15 "Polymorphism and Virtual Functions"; Project 7
*/

#include <cstdlib> // rand srand
#include "Dice.h"
using ncoop::Dice;
using ncoop::LoadedDice;

Dice::Dice( )
{
    numSides = 6; 
}

Dice::Dice(int numSides) 
{
    this->numSides = numSides; 
}

int Dice::rollDice() const
{
    return (rand() % numSides) + 1; 
}

int Dice::getSides( ) const {
    return numSides;
}

LoadedDice::LoadedDice( )
{
    numSides = 6; 
}

LoadedDice::LoadedDice(int numSides) 
{
    this->numSides = numSides; 
}

int LoadedDice::rollDice() const
{
    if (rand() % 2 == 0) // if rand is even; i.e. 50% chance
        return Dice::getSides( ); // returns numSides
    return Dice::rollDice( ); // else returns usual roll
}

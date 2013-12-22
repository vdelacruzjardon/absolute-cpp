/*
Absolute C++ (5e); Ch. 15 "Polymorphism and Virtual Functions"; Project 7

The following lists a Dice class that simulates rolling a die with a different number 
of sides. The default is a standard die with six sides. The rollTwoDice function 
simulates rolling two dice objects and returns the sum of their values. The srand
function requires including cstdlib.
...
Write a main function that creates two Dice objects with a number of sides of 
your choosing. Invoke the rollTwoDice function in a loop that iterates ten times 
and verify that the functions are working as expected. 
Next create your own class, LoadedDice, that is derived from Dice. Add a default 
constructor and a constructor that takes the number of sides as input. Override 
the rollDice function in LoadedDice so that with a 50% chance the function 
returns the largest number possible (i.e., numSides), otherwise it returns what 
Dice’s rollDice function returns. 
Test your class by replacing the Dice objects in main with LoadedDice objects. 
You should not need to change anything else. There should be many more dice 
rolls with the highest possible value. Polymorphism results in LoadedDice’s 
rollDice function to be invoked instead of Dice’s rollDice function 
inside rollTwoDice.

*/

#define ROLLS 20
#include "Dice.h"
#include <iostream> // cout endl
#include <time.h> // time
using ncoop::Dice;
using ncoop::LoadedDice;
using std::cout;
using std::endl;

void testDice( Dice & );
int rollTwoDice(const Dice& die1, const Dice& die2); 

int main( ) {
    cout << "~~~ Dice and LoadedDice driver ~~~\n";
    srand(static_cast<unsigned int>(time(NULL))); //Seeds random number generator

    cout << "\nFirst, normal dice";
    Dice d6, d4(4);
    testDice( d6 );
    testDice( d4 );

    cout << "\nNext, loaded dice";
    LoadedDice d6l, d10l(10);
    testDice( d6l );
    testDice( d10l );

    return 0;
}

void testDice( Dice &d ) {
    cout << endl << d.getSides( ) << "-sided die, single\n";
    for (size_t i = 0; i < ROLLS; i++)
        cout << d.rollDice( ) << " ";

    cout << endl << d.getSides( ) << "-sided dice, pair\n";
    for (size_t i = 0; i < ROLLS; i++)
        cout << rollTwoDice( d, d ) << " ";

    cout << endl;
}

// Take two dice objects, roll them, and return the sum 
int rollTwoDice(const Dice& die1, const Dice& die2) 
{
    return die1.rollDice() + die2.rollDice(); 
}

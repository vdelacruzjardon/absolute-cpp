/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 9

Suppose that you are creating a fantasy role-playing game. In this game, we have 
four different types of creatures: humans, cyberdemons, balrogs, and elves. To 
represent one of these creatures, we might define a Creature class as follows: 
...
The getDamage( ) function outputs and returns the damage this creature can 
inflict in one round of combat. The rules for calculating the damage are as follows: 
■ Every creature inflicts damage that is a random number r, where 0 < r <= 
strength. 
■ Demons have a 5% chance of inflicting a demonic attack, which is an additional 
50 damage points. Balrogs and Cyberdemons are demons.
■ Elves have a 10% chance to inflict a magical attack that doubles the normal 
amount of damage. 
■ Balrogs are very fast, so they get to attack twice.
...
One problem with this implementation is that it is unwieldy to add new creatures. 
Rewrite the class to use inheritance, which will eliminate the need for the variable 
type. The Creatureclass should be the base class. The classes Demon, Elf, and 
Human should be derived from Creature. The classes Cyberdemon and Balrog
should be derived from Demon. You will need to rewrite the getSpecies( ) and 
getDamage( ) functions so they are appropriate for each class. 
  For example, the getDamage( ) function in each class should only compute the 
damage appropriate for that object. The total damage is then calculated by combining 
the results of getDamage( ) at each level of the inheritance hierarchy. 
As an example, invoking getDamage( )for a Balrog object should invoke 
getDamage( ) for the Demon object, which should invoke getDamage( ) for the 
Creature object. This will compute the basic damage that all creatures inflict, 
followed by the random 5% damage that demons inflict, followed by the double 
damage that balrogs inflict. 
  Also include mutator and accessor functions for the private variables. Write a main
function that contains a driver to test your classes. It should create an object for 
each type of creature and repeatedly outputs the results of getDamage( ).

*/

#define ATTACKS 10
#include <iostream> // cout endl
#include <time.h> // time
#include "Creatures.h"
using ncoop::Creature;
using ncoop::Human;
using ncoop::Demon;
using ncoop::Cyberdemon;
using ncoop::Balrog;
using ncoop::Elf;
using std::cout;
using std::endl;

void testCreature( Creature* );

int main( ) {
    cout << "~~~ Creature driver program ~~~\n";
    //srand( 42 );
    srand( time(NULL) );

    // can create and test an object by value
    Human h;
    testCreature(&h);

    // can also dynamically create an object by pointer
    Cyberdemon *c;
    c = new Cyberdemon( 15, 100 );
    testCreature(c);
    delete c; // but then it should be deleted

    Balrog b;
    b.setStrength(30); // mutator functions by value
    b.setHitpoints(200);
    testCreature(&b);

    Elf *e;
    e = new Elf;
    e->setStrength(20); // mutator functions by reference
    testCreature(e);
    delete e;

    return 0;
}

// this function must take the Creature by reference to avoid the slicing problem
void testCreature( Creature* c ) {
    cout << endl << c;
    cout.setf(std::ios::right);
    for (size_t i = 0; i < ATTACKS; i++) {
        cout.width(2);
        cout << i+1 << ": ";
        c->getDamage( );
    }
}

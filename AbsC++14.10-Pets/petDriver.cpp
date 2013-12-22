/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 10

Define a Petclass that stores the pet’s name, age, and weight. Add appropriate 
constructors, accessor functions, and mutator functions. Also define a function 
named getLifespan that returns a string with the value “unknown lifespan.” 
  Next, define a Dog class that is derived from Pet. The Dog class should have a 
private member variable named breed that stores the breed of the dog. Add 
mutator and accessor functions for the breed variable and appropriate constructors. 
Redefine the getLifespan function to return “Approximately 7 years” if the 
dog’s weight is over 100 pounds and “Approximately 13 years” if the dog's weight 
is under 100 pounds. 
  Next, define a Rock class that is derived from Pet. Redefine the getLifespan
function to return “Thousands of years”. 
  Finally, write a test program that creates instances of pet rocks and pet dogs that 
exercise the inherited and redefined functions. 
*/

#include <iostream>
#include "Pets.h"
using std::cout;
using std::endl;
using ncoop::Pet;
using ncoop::Dog;
using ncoop::Rock;

int main( ) {
    Pet p1, p2;

    cout << p1 << endl;
    p1.setName( "Foo" );
    p1.setAge( 4 );
    p1.setWeight( 55 );
    cout << p1 << endl;

    p2 = p1;
    p2.setName( "Bar" );
    p2.setWeight( 77 );
    cout << p2 << endl;

    const Pet p3( "Baz", 6, 104 );
    cout << p3 << endl;

    cout << Dog( ) << endl;
    Dog d1("Spot", 9, 88, "Akita"), d2("Bowser", "Doberman");
    d1.setName("Pochi");
    d2.setWeight( 125 );
    d2.setAge( 3 );
    cout << d1 << endl;
    cout << d2 << endl;

    Rock r1;
    r1.setName( "Rockatansky" );
    r1.setWeight( 40 );
    r1.setAge( 50000 );
    cout << r1 << endl;
    cout << Rock( "Bomb Crag", 3, 500 ) << endl;

    return 0;
}

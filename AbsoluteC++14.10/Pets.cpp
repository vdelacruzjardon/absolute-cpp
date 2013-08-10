/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 10
*/

#include "Pets.h"
using ncoop::Pet;
using ncoop::Dog;
using ncoop::Rock;
using std::string;
using std::logic_error;

// Pet
Pet::Pet( string n, int a, int w ) {
    setName(n);
    setAge(a);
    setWeight(w);
}

void Pet::setName( string n ) {
    if (n.size( ) < 1)
        throw logic_error( "exception: name must not be blank" );
    name = n;
}

void Pet::setAge( int a ) {
    if (a < 0)
        throw logic_error( "exception: age must be non-negative" );
    age = a;
}

void Pet::setWeight( int w ) {
    if (w < 1)
        throw logic_error( "exception: weight must be positive" );
    weight = w;
}

const string Pet::getName( ) {return name;}
int Pet::getAge( ) {return age;}
int Pet::getWeight( ) {return weight;}

const string Pet::getLifespan( ) {
    return "Unknown lifespan.";
}

namespace ncoop {
    std::ostream& operator <<(std::ostream& outputStream, Pet& p) {
        return outputStream << "Pet name: " << p.getName( ) << "\nage: " << p.getAge( ) << " years\nweight: " << 
            p.getWeight( ) << " pounds\nlife span: " << p.getLifespan() << "\n";
    }

    std::ostream& operator <<(std::ostream& outputStream, const Pet& p) {
        Pet copy = p; // the copy is non-const
        return outputStream << copy;
    }
}

////////////////////////////////////////////////////////////////////////////////

void Dog::setBreed( string b ) {
    if (b.size( ) < 1)
        throw logic_error( "exception: breed must not be blank" );
    breed = b;
}

const string Dog::getBreed( ) {return breed;}
const string Dog::getLifespan( ) {
    return getWeight( ) > 100 ? "Approximately 7 years" : "Approximately 13 years";
}

namespace ncoop {
    std::ostream& operator <<(std::ostream& outputStream, Dog& d) {
        return outputStream << "Dog name and breed: " << d.getName( ) << ", " << d.getBreed( ) << 
            "\nage: " << d.getAge( ) << " years\nweight: " << 
            d.getWeight( ) << " pounds\nlife span: " << d.getLifespan() << "\n";
    }

    std::ostream& operator <<(std::ostream& outputStream, const Dog& d) {
        Dog copy = d; // the copy is non-const
        return outputStream << copy;
    }
}

////////////////////////////////////////////////////////////////////////////////

const string Rock::getLifespan( ) {
    return "Thousands of years";
}

namespace ncoop {
    std::ostream& operator <<(std::ostream& outputStream, Rock& r) {
        return outputStream << "Rock name: " << r.getName( ) << "\nage: " << r.getAge( ) << " years\nweight: " << 
            r.getWeight( ) << " pounds\nlife span: " << r.getLifespan() << "\n";
    }

    std::ostream& operator <<(std::ostream& outputStream, const Rock& r) {
        Rock copy = r; // the copy is non-const
        return outputStream << copy;
    }
}


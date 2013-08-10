/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 10
*/

#ifndef PETS_H
#define PETS_H

#include<string>

namespace ncoop {
    using std::string;

    class Pet {
    public:
        Pet( ) : name("unknown pet name"), age(0), weight(10) {};
        Pet( string n ) : age(0), weight(10) {setName(n);};
        Pet( string n, int a, int w );

        void setName( string n );
        void setAge( int a );
        void setWeight( int w );

        const string getName( );
        int getAge( );
        int getWeight( );

        const string getLifespan( );
        friend std::ostream& operator <<(std::ostream& outputStream, Pet& p);
        friend std::ostream& operator <<(std::ostream& outputStream, const Pet& p);

    private:
        string name;
        int age; // years
        int weight; // pounds

    };


    class Dog : public Pet {
    public:
        Dog( ) : Pet( ), breed( "unknown dog breed" ) {};
        Dog( string n, string b ) : Pet(n) {setBreed(b);};
        Dog( string n, int a, int w, string b ) : Pet(n, a, w) {setBreed(b);};

        void setBreed( string b );
        const string getBreed( );
        const string getLifespan( );
        friend std::ostream& operator <<(std::ostream& outputStream, Dog& p);
        friend std::ostream& operator <<(std::ostream& outputStream, const Dog& p);

    private:
        string breed;
    };


    class Rock : public Pet {
    public:
        Rock( ) : Pet( ) {};
        Rock( string n ) : Pet(n) {};
        Rock( string n, int a, int w ) : Pet(n, a, w) {};

        const string getLifespan( );
        friend std::ostream& operator <<(std::ostream& outputStream, Rock& p);
        friend std::ostream& operator <<(std::ostream& outputStream, const Rock& p);
    };

} // ncoop
#endif // PETS_H

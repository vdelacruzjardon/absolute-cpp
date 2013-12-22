/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 9
*/

#ifndef CREATURES_H
#define CREATURES_H

#include <string> // string
using std::string;

namespace ncoop {

    int randPercent( );

    class Creature
    {
    private:
        bool alive;
        int strength; // How much damage we can inflict 
        int hitpoints; // How much damage we can sustain 
        virtual string getSpecies() = 0; // Returns type of species 

    public:
        Creature( ) : alive(true), strength(10), hitpoints(10) {};
        Creature(int newStrength, int newHit); 

        void setStrength( int newStrength );
        void setHitpoints( int newHit );

        bool isAlive();
        int getStrength();
        int getHitpoints();
        virtual int getDamage() = 0; // Returns amount of damage this creature inflicts in one round of combat

        friend std::ostream& operator <<(std::ostream& outputStream, Creature * c);
    };

    class Human : public Creature {
    private:
        string getSpecies(); // Returns type of species 
    public:
        Human( ) : Creature( ) {};
        Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}; 
        int getDamage(); // Returns amount of damage this creature inflicts in one round of combat
        friend std::ostream& operator <<(std::ostream& outputStream, Human& h);
    };

    class Demon : public Creature {
    private:
        virtual string getSpecies() = 0; // Returns type of species 
    public:
        Demon( ) : Creature( ) {};
        Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}; 
        int getDamage(); // Returns amount of damage this creature inflicts in one round of combat
    };

    class Cyberdemon : public Demon {
    private:
        string getSpecies(); // Returns type of species 
    public:
        Cyberdemon( ) : Demon( ) {};
        Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit) {}; 
        int getDamage(); // Returns amount of damage this creature inflicts in one round of combat
        friend std::ostream& operator <<(std::ostream& outputStream, Cyberdemon& c);
    };

    class Balrog : public Demon {
    private:
        string getSpecies(); // Returns type of species 
    public:
        Balrog( ) : Demon( ) {};
        Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) {}; 
        int getDamage(); // Returns amount of damage this creature inflicts in one round of combat
        friend std::ostream& operator <<(std::ostream& outputStream, Balrog& b);
    };

    class Elf : public Creature {
    private:
        string getSpecies(); // Returns type of species 
    public:
        Elf( ) : Creature( ) {};
        Elf(int newStrength, int newHit) : Creature(newStrength, newHit) {}; 
        int getDamage(); // Returns amount of damage this creature inflicts in one round of combat
        friend std::ostream& operator <<(std::ostream& outputStream, Elf& e);
    };

} // namespace ncoop

#endif // CREATURES_H
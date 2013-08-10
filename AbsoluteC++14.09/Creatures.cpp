/*
Absolute C++ (5e); Ch. 14 "Inheritance"; Project 9
*/

#include <iostream> // cout endl
#include "Creatures.h"
#define DEMON_CHANCE 5 // chance of getting damage bonus
#define DEMON_BONUS 50 // damage bonus
#define ELF_CHANCE 10 // chance of getting double damage
using ncoop::Creature;
using ncoop::Human;
using ncoop::Demon;
using ncoop::Cyberdemon;
using ncoop::Balrog;
using ncoop::Elf;
using std::cout;
using std::endl;

int ncoop::randPercent( ) {
    return 100 * rand( ) / RAND_MAX;
}

// common constructor
Creature::Creature(int newStrength, int newHit) {
    setStrength(newStrength);
    setHitpoints(newHit);
} 

// common member functions
void Creature::setStrength( int newStrength ) {
    if (newStrength < 0)
        throw std::logic_error("strength cannot be negative");
    strength = newStrength;
}

void Creature::setHitpoints( int newHit ) {
    if (newHit < 0)
        alive = false;
    hitpoints = newHit;
}

bool Creature::isAlive() {
    return alive;
}

int Creature::getStrength() {
    return strength;
}

int Creature::getHitpoints() {
    return hitpoints;
}

// getSpecies
//string Creature::getSpecies() {return "Creature";}
string Human::getSpecies() {return "Human";}
//string Demon::getSpecies() {return "Demon";}
string Cyberdemon::getSpecies() {return "Cyberdemon";}
string Balrog::getSpecies() {return "Balrog";}
string Elf::getSpecies() {return "Elf";}

// getDamage
int Creature::getDamage() { // All creatures inflict damage, which is a random number up to their strength
    int damage = ( strength * randPercent( )/100 ) + 1; 
    cout << getSpecies( ) << " attacks for " << damage << " points!" << endl; 
    return damage;
}

int Human::getDamage() {
    return Creature::getDamage();
}

int Demon::getDamage() { // Demons can inflict damage of 50 with a 5% chance
    int damage = Creature::getDamage();
    if(randPercent( ) < DEMON_CHANCE) {
        damage += DEMON_BONUS; 
        cout << "Demonic attack inflicts " << DEMON_BONUS << " additional damage points!" << endl; 
    }
    return damage;
}

int Cyberdemon::getDamage() {
    int damage = Demon::getDamage();
    return damage;
}

int Balrog::getDamage() { // Balrogs are so fast they get to attack twice 
    int damage = Demon::getDamage();
    damage += Demon::getDamage();
    return damage;
}

int Elf::getDamage() { // Elves inflict double magical damage with a 10% chance
    int damage = Creature::getDamage();
    if(randPercent( ) < ELF_CHANCE) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl; 
        damage *= 2; 
    }
    return damage;
}

namespace ncoop {
    std::ostream& operator <<(std::ostream& outputStream, Creature * c) {
        return outputStream << "type " << c->getSpecies( ) << ", " << c->getStrength( ) << " strength, " << 
            c->getHitpoints( ) << " hit points " << (c->isAlive( ) ? "(alive)" : "(dead)") << endl;
    }
}

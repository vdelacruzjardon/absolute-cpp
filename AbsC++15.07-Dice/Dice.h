/*
Absolute C++ (5e); Ch. 15 "Polymorphism and Virtual Functions"; Project 7
*/

#ifndef DICE_H
#define DICE_H

namespace ncoop {

    class Dice
    {
    public:
        Dice( );
        Dice( int numSides); 
        virtual int rollDice() const;
        int getSides( ) const;
    protected:
        int numSides; 
    };

    class LoadedDice : public Dice {
    public:
        LoadedDice( );
        LoadedDice( int numSides); 
        virtual int rollDice() const;
    };

} // namespace ncoop

#endif // DICE_H
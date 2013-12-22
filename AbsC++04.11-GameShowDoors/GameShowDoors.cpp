/* 
Absolute C++ (5e); Ch. 4 "Parameters and Overloading"; Project 11

You are a contestant on a game show and have won a shot at the grand prize. 
Before you are three doors. $1,000,000 in cash has randomly been placed behind 
one door. Behind the other two doors are the consolation prizes of dishwasher 
detergent. The game show host asks you to select a door, and you randomly pick 
one. However, before revealing the prize behind your door, the game show host 
reveals one of the other doors that contains a consolation prize. At this point, the 
game show host asks if you would like to stick with your original choice or to 
switch to the remaining door. 
  Write a function to simulate the game show problem. Your function should randomly 
select locations for the prizes, select a door at random chosen by the contestant, 
and then determine whether the contestant would win or lose by sticking with
the original choice or switching to the remaining door. You may wish to create 
additional functions invoked by this function. 
  Next, modify your program so that it simulates playing 10,000 games. Count the 
number of times the contestant wins when switching versus staying. If you are 
the contestant, what choice should you make to optimize your chances of winning 
the cash, or does it not matter? 
*/

#include <iostream>
using namespace std;

bool gameShow( );
inline int getRand( int );

int main( ) {
    const int TRIALS = 10000;
    int wins = 0;

    // srand(42); // RNG seed
    for (int i=0; i < TRIALS; i++)
        wins += gameShow( );
    cout << "Won by switching choice " << wins << " out of " << TRIALS << " times. (" << 
        100.0 * wins / TRIALS << "%)" << endl;

    return 0;
}

bool gameShow( ) {
    // randomly pick from three options (0, 1, 2) for both the guess and the correct choice
    int contestantGuess = getRand( 3 ), correctChoice = getRand( 3 );
    // at this point one incorrect door is opened and there are two choices remaining (0, 1)
    // switching guesses corresponds to 1 and not switching is 0
    if (contestantGuess == correctChoice)
        // correct initial guess: switching means losing, so not switching (0) wins
        return getRand( 2 ) == 0;
    else
        // incorrect initial guess: switching means winning, so switching (1) wins
        return getRand( 2 ) == 1;
}

inline int getRand( int bound ) {
    return rand() * bound / RAND_MAX;
}

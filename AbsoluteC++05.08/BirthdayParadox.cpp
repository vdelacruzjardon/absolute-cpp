/* 
Absolute C++ (5e); Ch. 5 "Arrays"; Project 8

The birthday paradox is that there is a surprisingly high probability that two people 
in the same room happen to share the same birthday. By birthday, we mean the same 
day of the year (ignoring leap years), but not the exact birthday including the birth 
year or time of day. Write a program that approximates the probability that two 
people in the same room have the same birthday, for 2 to 50 people in the room. 
  The program should use simulation to approximate the answer. Over many trials 
(say, 5000), randomly assign birthdays to everyone in the room. Count up the 
number of times at least two people have the same birthday, and then divide by 
the number of trials to get an estimated probability that two people share the same 
birthday for a given room size.
*/

#define PRECISION 4
#define MAX_PEOPLE 50
#define TRIALS 5000
#define DAYS_IN_YEAR 365
#include <iostream>
using namespace std;

double getSameBDProb( const unsigned int people );

int main( ) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(PRECISION);

    //srand(42); // seed the RNG
    cout << "~~~ \"Birthday Paradox\" ~~~\n\n";
    for (unsigned int people = 2; people <= MAX_PEOPLE; people++) {
        cout << "For " << people << " people, " << 
            "the probability of 2+ same-birthdays is about " << getSameBDProb( people ) << endl;
    }

    return 0;
}

double getSameBDProb( const unsigned int people ) {
    unsigned int matches = 0; // number of times two or more same-day birthdays were detected

    for (unsigned int trial = 0; trial < TRIALS; trial++) {
        // create an initialize an array that records if a given day of the year is a known birthday
        bool birthdays[DAYS_IN_YEAR];
        for (int day = 0; day < DAYS_IN_YEAR; day++)
            birthdays[day] = false;

        for (unsigned int person = 0; person < people; person++) {
            int day = rand() * 365 / RAND_MAX;
            if (birthdays[day]) {
                matches++;
                break; // proceed to the next trial
            }
            birthdays[day] = true;
        } // end person loop

    } // end trial loop
    //cout << matches<< "\t";

    return static_cast<double>(matches)/TRIALS;
}

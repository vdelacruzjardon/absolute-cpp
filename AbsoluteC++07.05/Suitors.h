/* 
Absolute C++ (5e); Ch. 7 "Constructors and Other Tools"; Project 5
*/

#include <iostream>
#include <vector>
using namespace std;

class Suitors {
public:
    // constructor requires the number of suitors and the number of letters in the bride's name
    Suitors( unsigned int, unsigned int ); 

    unsigned int getRemaining( ) const;
    unsigned int getSuitor( unsigned int ) const;
    unsigned int getCurrentSuitor( ) const;
    unsigned int getLetters( ) const;
    unsigned int eliminate( );
    friend std::ostream& operator <<( std::ostream&, const Suitors& );

private:
    unsigned int letters;
    unsigned int current;
    vector<unsigned int> suitorList;
};


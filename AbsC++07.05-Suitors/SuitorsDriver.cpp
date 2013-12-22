/* 
Absolute C++ (5e); Ch. 7 "Constructors and Other Tools"; Project 5

In an ancient land, the beautiful princess Eve had many suitors. She decided on 
the following procedure to determine which suitor she would marry. First, all of 
the suitors would be lined up one after the other and assigned numbers. The first 
suitor would be number 1, the second number 2, and so on up to the last suitor, 
numbern. Starting at the first suitor she would then count three suitors down 
the line (because of the three letters in her name) and the third suitor would be 
eliminated from winning her hand and removed from the line. Eve would then 
continue, counting three more suitors, and eliminating every third suitor. When 
she reached the end of the line she would continue counting from the beginning. 
  For example, if there were six suitors then the elimination process would proceed 
as follows: 
  123456  initial list of suitors, start counting from 1 
  12456  suitor 3 eliminated, continue counting from 4 
  1245  suitor 6 eliminated, continue counting from 1 
  125  suitor 4 eliminated, continue counting from 5 
  15   suitor 2 eliminated, continue counting from 5 
  1   suitor 5 eliminated, 1 is the lucky winner 
  Write a program that uses a vector to determine which position you should stand 
in to marry the princess if there are n suitors.
*/

#define EVE 3
#include "Suitors.h"
using namespace std;

int main( ) {
    cout << "~~~ Eve's suitors ~~~\n";

    unsigned int initial, elim;
    cout << "Enter a number of suitors: ";
    cin >> initial;

    // construct the Suitors object and output it
    Suitors s( initial, EVE );
    cout << s << " initial list of suitors, start counting from " << s.getSuitor(0) << endl;

    // eliminate down to two
    while (s.getRemaining( ) > 2) {
        elim = s.eliminate( );
        cout << s << " suitor " << elim << " eliminated, continue counting from " << s.getCurrentSuitor( ) << endl;
    }

    // final elimination gives a special message
    elim = s.eliminate( );
    cout << s << " suitor " << elim << " eliminated, " << s.getCurrentSuitor( ) << " is the lucky winner" << endl;

    return 0;
}

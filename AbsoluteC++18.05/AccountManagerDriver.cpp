/* 
Absolute C++ (5e); Ch. 18 "Exception Handling"; Project 5
*/

#include "AccountManager.h"
using namespace std;

int main( ) {
    cout << "~~~ Account class driver demonstrating exception handling ~~~" << endl;

    const double initial(100), positive(5.80), negative(-2.50), huge(9999.99);

    cout.setf( ios::fixed ); 
    cout.setf( ios::showpoint );
    cout.precision( 2 );

    cout << "\nCreating an account with initial deposit of " << initial << endl;
    Account acc(initial);
    cout << acc << endl;

    cout << "\nAttempting to deposit " << positive << endl;
    try {
        acc.deposit(positive);
    } catch(Account::AccountException e) {
        cout << e.getMessage() << endl;
    }
    cout << acc << endl;

    cout << "\nAttempting to deposit " << negative << endl;
    try {
        acc.deposit(negative);
    } catch(Account::AccountException e) {
        cout << e.getMessage() << endl;
    }
    cout << acc << endl;

    cout << "\nAttempting to withdraw " << positive << endl;
    try {
        acc.withdraw(positive);
    } catch(Account::AccountException e) {
        cout << e.getMessage() << endl;
    }
    cout << acc << endl;

    cout << "\nAttempting to withdraw " << negative << endl;
    try {
        acc.withdraw(negative);
    } catch(Account::AccountException e) {
        cout << e.getMessage() << endl;
    }
    cout << acc << endl;

    cout << "\nAttempting to withdraw " << huge << endl;
    try {
        acc.withdraw(huge);
    } catch(Account::AccountException e) {
        cout << e.getMessage() << endl;
    }
    cout << acc << endl;

    cout << endl;

    return 0;
}
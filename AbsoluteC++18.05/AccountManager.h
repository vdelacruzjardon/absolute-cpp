/* 
Absolute C++ (5e); Ch. 18 "Exception Handling"; Project 5

A function that returns a special error code is usually better accomplished throwing 
an exception instead. The following class maintains an account balance.

Rewrite the class so that it throws appropriate exceptions instead of returning -1
as an error code. Write test code that attempts to withdraw and deposit invalid 
amounts and catches the exceptions that are thrown. 

*/

#include <string> // for exception messages
#include <iostream> // for <<
using namespace std; // for cout

class Account 
{
private:
    double balance; 
public:
    class AccountException {
    private:
        std::string message;
    public:
        AccountException() {};
        AccountException(std::string m) : message(m) {};

        const std::string getMessage() {return message;};
    };

    Account() 
    { 
    balance = 0; 
    } 
    Account(double initialDeposit)
    { 
        balance = initialDeposit; 
    } 
    double getBalance() 
    { 
        return balance; 
    } 
    // returns new balance or -1 if error 
    double deposit(double amount) 
    { 
        if(amount <= 0) 
            throw(AccountException("Exception: Deposit amount must be positive."));
        balance += amount; 
        /*
        if(amount > 0) 
            balance += amount; 
        else
            return -1; // Code indicating error 
        */
        return balance; 
    } 
    //returns new balance or -1 if invalid amount 
    double withdraw(double amount) 
    { 
        if (amount <= 0)
            throw(AccountException("Exception: Withdrawal amount must be positive."));
        if(amount > balance) 
            throw(AccountException("Exception: Withdrawal amount exceeds balance."));
        balance -= amount; 
        /*
        if((amount > balance) || (amount < 0)) 
            return-1; 
        else
            balance -= amount; 
        */
        return balance; 
    } 

    // overload << operator 
    friend ostream& operator <<(ostream& outputStream, const Account account);
};

ostream& operator <<(ostream& outputStream, const Account account) {
    cout.setf( ios::fixed ); 
    cout.setf( ios::showpoint );
    cout.precision( 2 ); // two decimal places

    return outputStream << "Balance: $" << account.balance;
}

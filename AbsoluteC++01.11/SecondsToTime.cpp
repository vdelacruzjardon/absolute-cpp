/* 
Absolute C++ (5e); Ch. 1 "C++ Basics"; Project 11

Write a program that inputs an integer that represents a length of time in seconds. 
The program should then output the number of hours, minutes, and seconds that 
corresponds to that number of seconds. For example, if the user inputs 50391 total 
seconds then the program should output 13 hours, 59 minutes, and 51 seconds.
*/

#include <iostream>
using namespace std;

int main( ) {
    const unsigned int SECONDS_MINUTE = 60, MINUTE_HOUR = 60, HOUR_DAY = 24, DAY_WEEK = 7;
    unsigned long input, weeks, days, hours, minutes, seconds;

    cout << "Enter a number of seconds to convert: ";
    cin >> input;

    seconds = input;
    minutes = seconds / SECONDS_MINUTE;
    seconds %= SECONDS_MINUTE;
    hours = minutes / MINUTE_HOUR;
    minutes %= MINUTE_HOUR;
    days = hours / HOUR_DAY;
    hours %= HOUR_DAY;
    weeks = days / DAY_WEEK;
    days %= DAY_WEEK;

    cout << input << " seconds is ";
    if (weeks > 0) cout << weeks << " weeks ";
    if (days > 0) cout << days << " days ";
    if (hours > 0) cout << hours << " hours ";
    if (minutes > 0) cout << minutes << " minutes ";
    if (seconds > 0) cout << seconds << " seconds ";
    cout << endl;

    return 0;
}
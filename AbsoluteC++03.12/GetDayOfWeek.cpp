/* 
Absolute C++ (5e); Ch. 3 "Function Basics"; Project 12

Write a program that inputs a date (e.g., July 4, 2008) and outputs the day of 
the week that corresponds to that date. 
...
Your program should allow the user to enter any date and output the corresponding 
day of the week in English. 
*/

//#define DEBUG
#include <iostream>
using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);

int main( ) {
    int year, month, day, dayOfWeek;
    // used to validate given day of the month
    const int MONTH_DAYS[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // get date and perform simple validation
    cout << "Enter a date in the form MM DD YYYY: ";
    cin >> month >> day >> year;
    if (year < 1 || month < 1 || day < 1) {
        cerr << "Positive numbers only.\n";
        exit( 1 );
    }
    if (month > 12) {
        cerr << "Month must be from 1 - 12.\n";
        exit( 1 );
    }
    if (day > MONTH_DAYS[month-1]) {
        cerr << "Day of month " << month << " must be from 1 - " << MONTH_DAYS[month-1] << ".\n";
        exit( 1 );
    }

    dayOfWeek = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;

    cout << "The day of the week for " << month << "/" << day << ", " << year << " is ";
    switch (dayOfWeek) {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
    }
    cout << "." << endl;

    return 0;
}

bool isLeapYear(int year) {
    bool leapYear = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
#ifdef DEBUG
    cout << "leap year: " << leapYear << endl;
#endif
    return leapYear;
}

int getCenturyValue(int year) {
    year /= 100;
    int centuryValue = 2 * (3 - (year % 4));
#ifdef DEBUG
    cout << "century value: " << centuryValue << endl;
#endif
    return centuryValue;
}

int getYearValue(int year) {
    year %= 100;
    int leap = year / 4;
    int yearValue = year + leap;
#ifdef DEBUG
    cout << "year value: " << yearValue << endl;
#endif
    return yearValue;
}

int getMonthValue(int month, int year) {
    const int MONTH_VALUE[2][12] = {
        {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}, // leap year == 0
        {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}  // leap year == 1
    };

    // subtract 1 from month to get 0-index
    int monthValue = MONTH_VALUE[isLeapYear(year)][month-1];
#ifdef DEBUG
    cout << "month value: " << monthValue << endl;
#endif
    return monthValue;
}

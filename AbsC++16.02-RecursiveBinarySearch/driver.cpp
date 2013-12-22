/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 2
*/

#include <iostream> // cin cout endl
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <stdlib.h> //exit
#include "recursiveBinarySearchT.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::stringstream;
using ncoop::search;
const int ARRAY_SIZE = 10;
const int MAX_CHARS = 100;
const char YES = 'Y';
const char NO = 'N';

bool getResponse( );

template<class T>
void readArray( char* typeName, T a[ ], ifstream &inStream );

template<class T>
bool promptSearch( const T a[ ], int finalIndex );

int main( )
{
    ifstream inStream("infile.txt");
    if( inStream.fail( ) )
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    int intArray[ARRAY_SIZE];
    double doubleArray[ARRAY_SIZE];
    readArray( (char*)"int", intArray, inStream );
    readArray( (char*)"double", doubleArray, inStream );

    inStream.close( );

    return 0;
} // main

bool getResponse( )
{
    char first;
    do {
        cin >> first;
        first = toupper(first);
        char junk;
        do
        {
            cin.get(junk);
        } while(junk != '\n');
    } while (first != YES && first != NO);
    return first == YES;
} // getResponse

template<class T>
void readArray( char* typeName, T a[ ], ifstream &inStream ) {
    char fileLine[MAX_CHARS];
    stringstream ss;
    inStream.getline(fileLine, MAX_CHARS);
    ss << fileLine;
    int elem = 0;
    while (elem < ARRAY_SIZE && ss >> a[elem]) {
        elem++;
    }

    cout << endl << "Array of " << typeName << "s, should already be sorted:" << endl;
    cout << "index\tvalue" << endl;
    for (int i = 0; i < elem; i++)
        cout << i << "\t" << a[i] << endl;
    cout << endl;
    do {} while (promptSearch( a, elem - 1 ));

    return;
} // readArray

template<class T>
bool promptSearch( const T a[ ], int finalIndex ) {
    T key;
    int location;
    bool found;
    cout << "Enter item to be located: ";
    cin >> key;
    search(a, 0, finalIndex, key, found, location);
    if (found)
        cout << key << " is in index location " << location << endl;
    else
        cout << key << " is not in the array." << endl;

    cout << endl << "Search this array again? " << YES << " or " << NO << ": ";
    return getResponse( );
} // promptSearch


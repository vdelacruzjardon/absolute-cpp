/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 2

Write a template version of the recursive binary search function from Display 13.6. 
Specify requirements on the template parameter type. Discuss the requirements on 
the template parameter type.

*/

#include <iostream> // cin cout endl
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <stdlib.h> //exit
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
const int ARRAY_SIZE = 10;
const int MAX_CHARS = 100;
const char YES = 'Y';
const char NO = 'N';

template<class T>
void readArray( char* typeName, T a[ ], ifstream &inStream );

template<class T>
bool promptSearch( const T a[ ], int finalIndex );

template<class T>
void search( const T a[ ], int first, int last, T key, bool & found, int & location);
//Precondition: a[first] through a[last] are sorted in increasing order.
//Postcondition: if key is not one of the values a[first] through a[last], 
//then found == false; otherwise, a[location] == key and found == true. 

//Additional precondition for template version: the > operator must work with the declared type

bool getResponse( );

int main( )
{
    ifstream inStream("infile.txt");
    if( inStream.fail( ) )
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    int intArray[ARRAY_SIZE];
    double doubleArray[ARRAY_SIZE];
    readArray( (char*)"int", intArray, inStream );
    readArray( (char*)"double", doubleArray, inStream );

    inStream.close( );

    return 0;
}

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
}

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
}

template<class T>
void search( const T a[ ], int first, int last, T key, bool& found, int& location)
{
    int mid;
    if (first > last)
    {
        found = false ;
    }
    else
    {
        mid = (first + last)/2;
        // required procedure to test for equivalence of floating point numbers
        if (key == a[mid]) 
        {
            found = true ;
            location = mid;
        }
        else if (key < a[mid])
        {
            search(a, first, mid - 1, key, found, location);
        }
        else if (key > a[mid])
        {
            search(a, mid + 1, last, key, found, location);
        }
    }
}

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
}

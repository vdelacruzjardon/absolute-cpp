/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 3
*/

#include <iostream> // cin cout endl
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <stdlib.h> //exit
#include "insertionSortT.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;

const int MAX_CHARS = 200; // max length of each line to read from the input file

template<class T>
void readSortOutput( char* typeName, vector<T> v, ifstream &inStream );

int main( )
{
	cout << "Insertion sort algorithm driver program" << endl;
	
    ifstream inStream("infile.txt");
    if( inStream.fail( ) )
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    vector<int> intVector;
    readSortOutput( (char*)"int", intVector, inStream );
    
    vector<double> dblVector;
    readSortOutput( (char*)"double", dblVector, inStream );
    
    vector<char> chrVector;
    readSortOutput( (char*)"char", chrVector, inStream );

    inStream.close( );

    return 0;
}

template<class T>
void readSortOutput( char* typeName, vector<T> v, ifstream &inStream )
{
	// read a line from the input stream into a stringstream
    char fileLine[MAX_CHARS];
    std::stringstream ss;
    inStream.getline(fileLine, MAX_CHARS);
    ss << fileLine;

	// extract elements of the specified type from the stringstream
	T elem;
    while (ss >> elem) {
		v.push_back( elem );
	}

    cout << endl << typeName << " vector before insertion sort: " << endl;
    for (int i = 0; i < v.size( ); i++)
		cout << v[i] << " ";
	cout << endl;

	insertionSort( v ); // the sort itself
	
    cout << typeName << " vector after insertion sort: " << endl;
    for (int i = 0; i < v.size( ); i++)
		cout << v[i] << " ";
	cout << endl;
	
	return;
} // readSortOutput

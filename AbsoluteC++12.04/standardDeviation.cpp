/*
Absolute C++ (5e); Ch. 12 "Streams and File I/O"; Project 4

Write a program that takes its input from a file of numbers of type double. The 
program outputs to the screen the mean and standard deviation of the numbers 
in the file. The file contains nothing but numbers of type double separated by 
blanks and/or line breaks. The standard deviation of a list of numbers n1, n2, n3,
and so forth, is defined as the square root of the mean of the following numbers: 
  (n1-a)^2,  (n2-a)^2,  (n3-a)^2, and so forth 
The number a is the mean of the numbers n1, n2, n3, and so forth. 
Hint: Write your program so that it first reads the entire file and computes the 
mean of all the numbers, then closes the file, then reopens the file and computes 
the standard deviation. You will find it helpful to first do Programming 
Project 12.2 and then modify that program to obtain the program for this project. 

*/

#include <fstream> // ifstream
#include <iostream> // cout
#include <iomanip> // setw
#include "Stats.h" // Dataset

#define INFILE "InputDoubles.txt"
#define WIDTH 8

int main( ) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::setw;

    cout << "~~~ Standard deviation calculator ~~~\n";
    cout << "\nReading input from " << INFILE << "...\n";

    std::ifstream fin(INFILE);

    if (fin.fail( )) {
        cout << "Failed to open input file. Exiting.\n";
        exit( 1 );
    }

    ncoop::Dataset data;
    double next;

    while ( fin >> next ) { // "the macho way to test for end of file"
        data.addData( next );
    }

    cout << endl <<
        "  Number of values:" << setw(WIDTH) << data.N( ) << endl <<
        "               Sum:" << setw(WIDTH) << data.Sum( ) << endl << 
        "              Mean:" << setw(WIDTH) << data.Mean( ) << endl <<
        "          Variance:" << setw(WIDTH) << data.Variance( ) << endl <<
        "Standard deviation:" << setw(WIDTH) << data.StdDev( ) << endl << endl;

    return 0;
}

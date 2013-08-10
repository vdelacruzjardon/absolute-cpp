/*
Absolute C++ (5e); Ch. 12 "Streams and File I/O"; Project 4
*/

#include "Stats.h"
using ncoop::Dataset;

Dataset& Dataset::addData( double d ) {
    data.push_back( d );
    updated = false;
    return *this;
}

bool Dataset::removeData( size_t i ) {
    if (data.size( ) < i)
        return false;
    // stub
    return true;
}

Dataset& Dataset::clearData( ) {
    data.clear( );
    return *this;
}

Dataset& Dataset::update( ) {
    if (data.size( ) < 1)
        return *this;

    sum = 0;
    for (size_t i = 0; i < data.size( ); i++)
        sum += data[i];

    mean = sum / data.size( );

    double sumOfSquares(0.0);
    for (size_t i = 0; i < data.size( ); i++) {
        sumOfSquares += sq(data[i] - mean);
    }
    variance = sumOfSquares / data.size( );

    stdDev = sqrt(variance);

    updated = true;
    return *this;
}

size_t Dataset::N( ) {
    return data.size( );
}

double Dataset::Sum( ) {
    if (!updated) update( );
    return sum;
}

double Dataset::Mean( ) {
    if (!updated) update( );
    return mean;
}

double Dataset::Variance( ) {
    if (!updated) update( );
    return variance;
}

double Dataset::StdDev( ) {
    if (!updated) update( );
    return stdDev;
}

double Dataset::sq( double x ) {return x*x;}

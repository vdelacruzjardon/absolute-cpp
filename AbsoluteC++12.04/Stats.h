/*
Absolute C++ (5e); Ch. 12 "Streams and File I/O"; Project 4
*/

#ifndef STATS_H
#define STATS_H

#include <vector> // to store data

namespace ncoop {
    class Dataset {
    public:
        Dataset( ) : updated(false) {};

        Dataset& addData( double );
        bool removeData( size_t );
        Dataset& clearData( );
        Dataset& update( );
        size_t N( );
        double Sum( );
        double Mean( );
        double Variance( );
        double StdDev( );

    private:
        std::vector<double> data;
        double sum;
        double mean;
        double variance;
        double stdDev;
        bool updated;

        static double sq( double );

    };
} // namespace ncoop

#endif // STATS_H
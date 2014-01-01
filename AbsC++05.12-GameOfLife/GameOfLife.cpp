/*
Absolute C++ (5e); Ch. 5 "Arrays"; Project 12

  The mathematician John Horton Conway invented the "Game of Life." Though
not a "game" in any traditional sense, it provides interesting behavior that is
specified with only a few rules. This project asks you to write a program that
allows you to specify an initial configuration. The program follows the rules of
Life (listed shortly) to show the continuing behavior of the configuration.
  LIFE is an organism that lives in a discrete, two-dimensional world. While this
world is actually unlimited, we do not have that luxury, so we restrict the array to
80 characters wide by 22 character positions high. If you have access to a larger
screen, by all means use it.
  This world is an array with each cell capable of holding one LIFE cell. Generations
mark the passing of time. Each advance_generation brings births and deaths to the LIFE
community. The births and deaths follow this set of rules:
  1.  We define each cell to have eight neighbor cells. The neighbors of a cell are the
cells directly above, below, to the right, to the left, diagonally above to the right
and left, and diagonally below, to the right and left.
  2.  If an occupied cell has zero or one neighbor, it dies of loneliness. If an occupied
cell has more than three neighbors, it dies of overcrowding.
  3.  If an empty cell has exactly three occupied neighbor cells, there is a birth of a
new cell to replace the empty cell.
4.  Births and deaths are instantaneous and occur at the changes of advance_generation.
A cell dying for whatever reason may help cause birth, but a newborn cell cannot
resurrect a cell that is dying, nor will a cell's death prevent the death of another,
say, by reducing the local population.
*/

#define WIDTH 10
#define HEIGHT 4
#define QUIT 'q'
#include <iostream> //std::cout cerr cin
#include <fstream> //std::ifstream
#include <sstream> //std::ostringstream
#include <stdexcept> //std::logic_error
#include <stdlib.h> //exit
#include "World.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::logic_error;

enum DrawSymbols { ALIVE = '*', DEAD = '.' };

void display_generation( char world[WIDTH][HEIGHT], size_t &gen );
void advance_generation( char world[WIDTH][HEIGHT] );
bool confirm_continue( );

int main ( int argc, char *argv[] ) {
    cout << "~~~ The Game of Life ~~~" << endl;

    try {
        std::ostringstream errmsg;
        // check for argument
        if ( argc <= 1 ) {
            errmsg << "Error: No input file argument provided.";
            throw logic_error( errmsg.str() );
        } else {
            std::ifstream infile;
            infile.open(argv[1]);
        // try opening file
            if ( infile.fail( ) ) {
                errmsg << "Error: Could not open input file '" << errmsg << "'";
                throw logic_error( errmsg.str() );
            }
            cout << "opened input file '" << argv[1] << "'." << endl;
            std::string nextline;
            size_t width(0), height(0);

        // parse contents
            while ( getline(infile, nextline) ) {
                height++;
                if (height > 1 && width != nextline.length()) {
                    errmsg << "Parse error: line " << height-1 << " is " << width <<
                        " cols wide, but line " << height << " is " << nextline.length() << " cols wide.";
                    throw logic_error( errmsg.str() );
                }
                width = nextline.length();
                for (size_t i = 0; i < width; i++)
                switch( nextline[i] ) {
                case ALIVE:
                    //width++;
                    break;
                case DEAD:
                    //width++;
                    break;
                default:
                    errmsg << "Parse error, line " << height << ", col: " << i+1 <<
                        " invalid char '" << nextline[i] << "'";
                    throw logic_error( errmsg.str() );
                }
            }
            cerr << "height " << height << ", width " << width << endl;
            infile.close( );
        }
    } catch (logic_error e) {
        cerr << e.what( ) << endl;
        exit(1);
    }

    char world[WIDTH][HEIGHT];
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            world[x][y] = DEAD;

    world[1][1] = ALIVE;
    world[1][2] = ALIVE;
    world[1][3] = ALIVE;

    cout << "Press enter to pass a generation. '" << QUIT << "' key quits." << endl;

    size_t gen = 0;
    do {
        display_generation( world, gen );
        advance_generation( world );
    } while ( confirm_continue( ) );

    cout << "Stopped after generation " << gen-1 << endl;

    return 0;
}

bool confirm_continue( ) {
    bool retval(true);
    char symbol;
    do {
        cin.get( symbol );
        if ( tolower(symbol) == QUIT ) {
            retval = false;
            break;
        }
    } while ( symbol != '\n' );
    return retval;
}

void display_generation( char world[WIDTH][HEIGHT], size_t &gen ) {
    cout << "Generation " << gen << endl;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            cout << world[x][y];
        cout << endl;
    }
    gen++;
}

void advance_generation( char world[WIDTH][HEIGHT] ) {
    char next[WIDTH][HEIGHT];
    cout << endl;
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) {
            int l = (x-1 <= 0) ? x-1 : WIDTH-1;
            int r = (x+1 < WIDTH) ? x+1 : 0;
            int d = (y-1 <= 0) ? y-1 : HEIGHT-1;
            int u = (y+1 < HEIGHT) ? y+1 : 0;

            int neighbors = 0; // the number of the cell's living neighbors
            if (world[l][u] == ALIVE) neighbors++; // above left
            if (world[x][u] == ALIVE) neighbors++; // above
            if (world[r][u] == ALIVE) neighbors++; // above right
            if (world[l][y] == ALIVE) neighbors++; // left
            //if (world[x][y] == ALIVE) neighbors++; // don't count self as a neighbor
            if (world[r][y] == ALIVE) neighbors++; // right
            if (world[l][d] == ALIVE) neighbors++; // below left
            if (world[x][d] == ALIVE) neighbors++; // below
            if (world[r][d] == ALIVE) neighbors++; // below right

            cout << neighbors;
            if (x == WIDTH-1) cout << endl;

            next[x][y] = world[x][y]; // next state defaults to current state
            if (next[x][y] == ALIVE) {
                if (neighbors < 2 || neighbors > 3) next[x][y] = DEAD;
            } else {
                if (neighbors == 3) next[x][y] = ALIVE;
            }
        }
        cout << endl;

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            world[x][y] = next[x][y]; // update state

    return;
}

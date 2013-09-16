#include <iostream> // cin cout endl
#include <stdlib.h> //exit
#include <vector> // vector

int main( )
{
	std::vector<int> testvec;
	testvec.push_back(4);
	testvec.push_back(-8);
	testvec.push_back(548);

	std::cout << testvec[1] << std::endl;
	return 0;
}

/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 2

Write a template version of the recursive binary search function from Display 13.6. 
Specify requirements on the template parameter type. Discuss the requirements on 
the template parameter type.

*/

namespace ncoop {
	template<class T>
	void search( const T a[ ], int first, int last, T key, bool & found, int & location);
	//Precondition: a[first] through a[last] are sorted in increasing order.
	//Postcondition: if key is not one of the values a[first] through a[last], 
	//then found == false; otherwise, a[location] == key and found == true. 

	//Additional precondition for template version: the > operator must work with the declared type
} // namespace ncoop

#include "recursiveBinarySearchT.cpp"

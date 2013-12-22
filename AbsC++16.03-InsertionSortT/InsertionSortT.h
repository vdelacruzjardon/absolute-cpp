/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 3

The template sort routine in Display 16.3 is based on an algorithm called the
selection sort. Another related sorting algorithm is called insertion sort. The
insertion sort algorithm is the sort method often used to sort a Bridge hand. Con-
sider each element in turn, inserting it into its proper place among the elements
at the start of the array that are already sorted. The element being considered is
inserted by moving the larger elements “to the right” to make space and inserting
the vacated place. For example, the following shows the steps in a selection sort of
an array of ints a. The values of a[0] through a[4] are given on each line. The
asterisk marks the boundary between the sorted and unsorted portions of the array.
2 * 5 3 4
2 5 * 3 4
2 3 5 * 4
2 3 4 5 *
First, write an insertion sort function that works for ints. Next, write the template
version of this sort function. Finally, test thoroughly using several primitive types,
using a type you create with the minimal machinery necessary to use the sort routine.

*/

#include <vector> // vector
using std::vector;

template<class T>
void insertionSort(vector<T>& data); // function replaces the given argument

#include "insertionSortT.cpp"

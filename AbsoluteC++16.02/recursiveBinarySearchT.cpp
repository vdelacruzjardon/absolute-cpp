/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 2
*/

namespace ncoop {
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
	} // search
} // namespace ncoop


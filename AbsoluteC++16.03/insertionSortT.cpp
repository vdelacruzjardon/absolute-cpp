/* 
Absolute C++ (5e); Ch. 16 "Templates"; Project 3
*/

template<class T>
void insertionSort(vector<T>& data)
{
	for (size_t i = 0; i < data.size( ); i++)
		for (size_t j = i; j < data.size( ); j++)
			if (data[ j ] < data[ i ])
			{ // swap values
				T temp = data[ j ];
				data[ j ] = data[ i ];
				data[ i ] = temp;
			}
	
	return;
}

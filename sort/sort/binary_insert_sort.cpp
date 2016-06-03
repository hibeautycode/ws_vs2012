#include "sort_algorithm.h"

/***************************************************  
 BinaryInsertSort
 ---------------------------------------------------
      Stability    |   stable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst  
 ---------------------------------------------------
  Time  complexity | O(nlogn) |          | O(n^2)  
 ---------------------------------------------------
  Space complexity |   O(1)   |   O(1)   |  O(1)    
 ---------------------------------------------------
***************************************************/

void BinaryInsertSort( ElementType A[], int n )
{
	int low, mid, high;

	for( int i = 1; i < n; i++ )
	{
		low = 0, high = i - 1 ;

		while( low <= high )	// find the appropriate position of A[i]
		{
			mid = ( low + high ) / 2;
			if( A[ i ] < A[ mid ] )
				high = mid - 1;
			else
				low = mid + 1;
		}

		for( high = i; high > low; high-- )		// insert A[i] to the sorted sequence which is A[0]...A[i-1]
		{
			Swap( &A[ high - 1 ], &A[ high ] );		// take high as temp variable
		}
	}
}
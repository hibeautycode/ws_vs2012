#include "sort_algorithm.h"

/***************************************************
 HeapSort
 ---------------------------------------------------
      Stability    |   unstable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst  
 ---------------------------------------------------
  Time  complexity | O(nlogn) | O(nlogn) | O(nlogn)  
 ---------------------------------------------------
  Space complexity |   O(1)   |   O(1)   |  O(1)    
 ---------------------------------------------------
***************************************************/

#define LeftChild( i )  ( 2 * ( i ) + 1 )

void AdjustDown( ElementType A[], int i, int n )  // adjust A[i] downward
{
	int child;
	ElementType tmp;

	for( tmp = A[ i ]; LeftChild( i ) < n; i = child )
	{
		child = LeftChild( i );
		if( child != n - 1 && A[ child + 1 ] > A[ child ] )
			child++;	// take the big child position
		if( tmp < A[ child ] )
			A[ i ] = A[ child ];
		else
			break;
	}
	A[ i ] = tmp;
}

void HeapSort( ElementType A[], int n )
{
	int i;

	for( i = ( n - 1 ) / 2; i >= 0; i-- )  // Build Max Heap
		AdjustDown( A, i, n );

	for( i = n - 1; i > 0; i-- )
	{
		Swap( &A[ 0 ], &A[ i ] );  // Delete Root Max 
		AdjustDown( A, 0, i );
	}
}
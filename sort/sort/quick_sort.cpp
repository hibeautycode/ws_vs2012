#include "sort_algorithm.h"

/*************************************************** 
 QuickSort
 ---------------------------------------------------
      Stability    |   unstable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst   
 ---------------------------------------------------
  Time  complexity | O(nlogn) | O(nlogn) |  O(n^2)  
 ---------------------------------------------------
  Space complexity | O(logn)  | O(logn)  |  O(n)    
 ---------------------------------------------------
***************************************************/

ElementType Median3( ElementType A[], int Left, int Right )
{
	int Center = ( Left + Right ) / 2;

	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right ] )
		Swap( &A[ Left ], &A[ Right ] );
	if( A[ Center ] > A[ Right ] )
		Swap( &A[ Center ], &A[ Right ] );

	/* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

	Swap( &A[ Center ], &A[ Left ] );  // put median value in the left

	return A[ Left ];                // Return pivot 
}

int Partition( ElementType A[], int Left, int Right )
{
	ElementType pivot = Median3( A, Left, Right );  // find an appropriate value as pivot

	while( Left < Right )
	{
		while( Left < Right && A[ Right] >= pivot )
			Right--;
		if( Left < Right )
			A[ Left ] = A[ Right ];  // put the value smaller than pivot on the left of pivot positon
		while( Left < Right && A[ Left ] <= pivot )
			Left++;
		if( Left < Right )
			A[ Right ] = A[ Left ];  // put the value greater than pivot on the right of pivot position
	}

	A[ Left ] = pivot;  // check it! Left is the position of pivot

	return Left;  // return pivot position
}

void Qsort( ElementType A[], int Left, int Right )
{
	if( Left < Right )
	{
		int pivotPos = Partition( A, Left, Right );
		Qsort( A, Left, pivotPos - 1 );
		Qsort( A, pivotPos + 1, Right );
	}
}

void QuickSort( ElementType A[], int n )
{
	Qsort( A, 0, n-1 );
}
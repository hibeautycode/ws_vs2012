#include "sort_algorithm.h"

/***************************************************
 MergeSort
 ---------------------------------------------------
      Stability    |   stable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst  
 ---------------------------------------------------
  Time  complexity | O(nlogn) | O(nlogn) | O(nlogn)  
 ---------------------------------------------------
  Space complexity |   O(n)   |   O(n)   |  O(n)    
 ---------------------------------------------------
***************************************************/

void Merge( ElementType A[], ElementType TmpArray[], int low, int mid, int high )
{
	int k = 0, i = low, j = mid + 1;

	while( i <= mid && j <= high )  // sort A by comparing A[low...mid] with A[mid+1...high]
	{
		if( A[j] < A[i] )
			TmpArray[ k++ ] = A[ j++ ];
		else
			TmpArray[ k++ ] = A[ i++ ];
	}
	while( i <= mid )
		TmpArray[ k++ ] = A[ i++ ];
	while( j <= high )
		TmpArray[ k++ ] = A[ j++ ];

	for( k = 0; k < high - low + 1; k++ )  // copy sorted B to A
		A[ low + k ] = TmpArray[ k ];
}

void Msort( ElementType A[], ElementType TmpArray[], int low, int high )
{
	if( low < high )
	{
		int mid = ( low + high ) / 2;
		Msort( A, TmpArray, low, mid );
		Msort( A, TmpArray, mid + 1, high );
		Merge( A, TmpArray, low, mid, high );
	}
}

void MergeSort( ElementType A[], int n )
{
	ElementType *TmpArray = ( ElementType* )malloc( n * sizeof( ElementType ) );

	if( TmpArray != NULL )
	{
		Msort( A, TmpArray, 0, n - 1 );
		free( TmpArray );
	}
	else
		FatalError( "No space for tmp array!!!" );
}
#include <stdio.h>
#include "sort_algorithm.h"
#define MaxSize 20

int main( )
{
	int i, Arr1[ MaxSize ], Arr2[ MaxSize ];

	for( i = 0; i < 1; i++ )
	{
		int RadixArray[ 10 ] = { 25, 3, 10, 255, 367, 555, 14, 5, 2856, 78 };
		HeapSort( RadixArray, 10 );
		for( int j = 0; j < 10; j++ )
			printf( "%d ", RadixArray[ j ] );
		printf( "\n\n" );
		/*
		printf( "permute the unsorted sequence: \n" );
		for( int j = 0; j < 10; j++ )
			printf( "%d ", RadixArray[ j ] );
		printf( "\n\n" );
		RadixSort( RadixArray, 10 );
		printf( "Sort the sequence by RadixSort:\n" );
		for( int j = 0; j < 10; j++ )
			printf( "%d ", RadixArray[ j ] );
		printf( "\n\n" );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		InsertSort( Arr1, MaxSize );
		printf( "Sort the sequence by InsetionSort:\n" );
		Checksort( Arr1, MaxSize );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		BinaryInsertSort( Arr1, MaxSize );
		printf( "Sort the sequence by BinaryInsetSort:\n" );
		Checksort( Arr1, MaxSize );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		ShellSort( Arr1, MaxSize );
		printf( "Sort the sequence by ShellSort:\n" );
		Checksort( Arr1, MaxSize );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		HeapSort( Arr1, MaxSize );
		printf( "Sort the sequence by HeapSort:\n" );
		Checksort( Arr1, MaxSize );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		MergeSort( Arr1, MaxSize );
		printf( "Sort the sequence by MergeSort:\n" );
		Checksort( Arr1, MaxSize );

		Permute( Arr2, MaxSize );
		Copy( Arr1, Arr2, MaxSize );
		QuickSort( Arr1, MaxSize );
		printf( "Sort the sequence by QuickSort:\n" );
		Checksort( Arr1, MaxSize );
		*/
	}
	getchar();
	return 0;
}
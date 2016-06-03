#include "sort_algorithm.h"

void Swap( ElementType *Lhs, ElementType *Rhs )
{
	ElementType Tmp = *Lhs;
	*Lhs = *Rhs;
	*Rhs = Tmp;
}

void Copy( ElementType Lhs[], const ElementType Rhs[], int n )
{
	int i;
	for( i = 0; i < n; i++ )
		Lhs[ i ] = Rhs[ i ];
}

void Permute( ElementType A[], int n )
{
	int i;
	printf( "permute the unsorted sequence: \n" );

	for( i = 0; i < n; i++ )
		A[ i ] = i;
	for( i = 1; i < n; i++ )
		Swap( &A[ i ], &A[ rand( ) % ( i + 1 ) ] );
	for( i = 0; i < n; i++ )
		printf( "%d ", A[ i ] );
	printf( "\n\n" );
}

void Checksort( ElementType A[], int n )
{
	int i;
	for( i = 0; i < n; i++ )
	{
		if( A[ i ] != i )
			printf( "Sort fails: %d %d\n", i, A[ i ] );
		printf( "%d ", i, A[ i ] );
	}

	printf( "\n\n" );
	//printf( "\nCheck completed\n" );
}
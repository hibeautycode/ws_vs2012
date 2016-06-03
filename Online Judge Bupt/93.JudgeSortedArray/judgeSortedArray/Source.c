#include<stdio.h>
#include<malloc.h>

int judgeSortedArray( int array[], int len )
{
	int i;
	for( i = 1; i < len; i++ )
	{
		if( array[ i - 1 ] > array[i] )
			return 0;
	}
	return 1;
}
int main()
{
	int T, N, *elem, i;

	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &N );
		elem = ( int* )malloc( sizeof( int ) * N );

		for( i = 0; i < N; i++ )
		{
			scanf( "%d", &elem[i] );
		}
		if( judgeSortedArray( elem, N ) )
			puts( "Yes" );
		else
			puts( "No" );
		free( elem );
	}

	return 0;
}
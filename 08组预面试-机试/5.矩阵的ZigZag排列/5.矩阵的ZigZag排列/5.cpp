#include<stdio.h>
int array[ 500 ][ 500 ];

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int n;
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				scanf( "%d", &array[ i ][ j ] );
			}
		}
		for( int i = 0; i < 2 * n - 1; i++ )
		{
			if( i % 2 == 0 )
			{
				if( i < n )
				{
					for( int k = 0; k <= i; k++ )
					{
						printf( "%d ", array[i-k][k] );
					}
				}
				else
				{
					int tmp = 2 * n - i - 1;
					for( int k = 0; k < tmp; k++ )
					{
						printf( "%d ", array[tmp-k-1][k+1] );
					}
				}
			}
			else
			{
				if( i < n )
				{
					for( int k = 0; k <= i; k++ )
					{
						printf( "%d ", array[k][i-k] );
					}
				}
				else
				{
					int tmp = 2 * n - i - 1;
					for( int k = 0; k < tmp; k++ )
					{
						printf( "%d ", array[tmp+k][n-k-1] );
					}
				}
			}
		}
		printf( "\n" );
	}
	
	return 0;
}
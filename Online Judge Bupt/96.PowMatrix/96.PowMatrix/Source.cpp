#include<stdio.h>
#include<malloc.h>

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int n, pow;   // nŒ¨æÿ’Û
		scanf( "%d %d", &n, &pow );

		long long **m, **media, **result;
		m = ( long long** )malloc( sizeof( long long* ) * n );
		media = ( long long** )malloc( sizeof( long long* ) * n );
		result = ( long long** )malloc( sizeof( long long* ) * n );

		for( int i = 0; i < n; i++ )
		{
			m[ i ] = ( long long* )malloc( sizeof( long long ) * n );
			media[ i ] = ( long long* )malloc( sizeof( long long ) * n );
			result[ i ] = ( long long* )malloc( sizeof( long long ) * n );
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				scanf( "%lld", &m[ i ][ j ] );
				media[ i ][ j ] = m[ i ][ j ];
				result[ i ][ j ] = m[ i ][ j ];
			}
		}

		pow--;
		while( pow-- )
		{
			for( int i = 0; i < n; i++ )
			{
				for( int j = 0; j < n; j++ )
				{
					result[ i ][ j ] = 0;
					for( int k = 0; k < n; k++ )
					{
						result[ i ][ j ] += media[ i ][ k ] * m[ k ][ j ];
					}
				}
			}
			for( int i = 0; i < n; i++ )
			{
				for( int j = 0; j < n; j++ )
				{
					media[ i ][ j ] = result[ i ][ j ];
				}
			}
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n - 1; j++ )
			{				
				printf( "%d ", result[ i ][ j ] );
			}
			printf( "%d\n", result[ i ][ n - 1 ] );
		}
		free( ( void* )m );
		free( ( void* )media );
		free( ( void* )result );
	}
}
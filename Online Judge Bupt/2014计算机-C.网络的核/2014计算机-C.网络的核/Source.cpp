#include<stdio.h>
#define MaxSize 51

int path[ MaxSize ][ MaxSize ];


int findKernelByFloyd( int N )
{
	for( int k = 1; k <= N ; k++ )
	{
		for( int i = 1; i <= N; i++ )
		{
			for( int j = 1; j <= N; j++ )
			{
				if( path[ i ][ j ] > path[ i ][ k ] + path[ k ][ j ] )
				{
					path[ i ][ j ] = path[ i ][ k ] + path[ k ][ j ];
				}
			}
			//printf( "%d ", path[i][j] );
		}
		//printf( "\n" );
	}
	int kernelNode = 1;
	int tmpDisCount = 0;
	int minDisNum = N * N;
	for( int i = 1; i <= N ; i++ )
	{		
		for( int j = 1; j <= N; j++ )
		{
			tmpDisCount += path[ i ][ j ];
		}
		if( tmpDisCount < minDisNum )
		{
			minDisNum = tmpDisCount;
			kernelNode = i;
		}
		tmpDisCount = 0;
	}
	return kernelNode;
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N, M;
		scanf( "%d %d", &N, &M );
		for( int i = 1; i <= N ; i++ )
		{
			for( int j = 1; j <= N; j++ )
			{
				if( i == j )
					path[ i ][ j ] = 0;
				else
					path[ i ][ j ] = N;
			}		
		}
		while( M-- )
		{
			int u, v;
			scanf( "%d %d", &u, &v );
			path[ u ][ v ] = 1;
			path[ v ][ u ] = 1;
		}
		printf( "%d\n", findKernelByFloyd( N ) );
	}
	
	return 0;
}
#include<stdio.h>

int input[ 50 ][ 50 ];

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N, M;
		scanf( "%d %d", &N, &M );
		for( int i = 0; i < N; i++ )
		{
			for( int j = 0; j < M; j++ )
			{
				scanf( "%1d", &input[ i ][ j ] );
			}
			getchar();
		}
		int angle;
		scanf( "%d", &angle );
		
		if( angle == 0 )
		{
			for( int i = 0; i < N; i++ )
			{
				for( int j = 0; j < M; j++ )
				{
					printf( "%1d", input[ i ][ j ] );
				}
				printf( "\n" );
			}
		}
		else if( angle == 90 )			
		{
			for( int j = 0; j < M; j++ )
			{
				for( int i = 0; i < N; i++ )
				{
					printf( "%d", input[ N - i - 1 ][ j ] );
				}
				printf( "\n" );
			}
		}
		else if( angle == 180 )
		{
			for( int i = 0; i < N; i++ )
			{
				for( int j = 0; j < M; j++ )
				{
					printf( "%1d", input[ N - i - 1 ][ M - j - 1 ] );
				}
				printf( "\n" );
			}
		}
		else if( angle == 270 )
		{
			for( int j = 0; j < M; j++ )
			{
				for( int i = 0; i < N; i++ )
				{
					printf( "%d", input[ i ][ M - j - 1 ] );
				}
				printf( "\n" );
			}
		}
	}
	return 0;
}
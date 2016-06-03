#include<stdio.h>
#include<string.h>

int main()
{
	int N;
	scanf( "%d", &N );
	while( N-- )
	{
		char input[ 100 ];
		scanf( "%s", input );
		int len = strlen( input );
		for( int i = 0; i < len; i++ )
		{
			if( input[ i ] >= 'A' && input[ i ] <= 'Z' )
			{
				input[ i ] = input [ i ] - ( 'A' - 'a' );
				if( input[ i ] == 'z' )
				{
					input[ i ] = 'a';
				}
				else
				{
					input[ i ] += 1;
				}
			}
			else if( input[ i ] >= 'a' && input[ i ] <= 'c' )
			{
					input[ i ] = '2';
			}	
			else if( input[ i ] >= 'd' && input[ i ] <= 'f' )
			{
					input[ i ] = '3';
			}
			else if( input[ i ] >= 'g' && input[ i ] <= 'i' )
			{
					input[ i ] = '4';
			}
			else if( input[ i ] >= 'j' && input[ i ] <= 'l' )
			{
					input[ i ] = '5';			
			}
			else if( input[ i ] >= 'm' && input[ i ] <= 'o' )
			{
					input[ i ] = '6';
			}
			else if( input[ i ] >= 'p' && input[ i ] <= 's' )
			{
					input[ i ] = '7';
			}
			else if( input[ i ] >= 't' && input[ i ] <= 'v' )
			{
					input[ i ] = '8';
			}
			else if( input[ i ] >= 'w' && input[ i ] <= 'z' )
			{
					input[ i ] = '9';
			}
		}
		for( int i = 0; i < len; i++ )
		{
			printf( "%c", input[ i ] );
		}
		printf( "\n" );
	}
	getchar();
	getchar();

	return 0;
}
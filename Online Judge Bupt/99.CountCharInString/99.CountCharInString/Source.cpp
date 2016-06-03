#include<stdio.h>
#include<string.h>

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		getchar();
		char ch;
		scanf( "%c", &ch );

		char s[ 1000 ];
		memset( s, 0, sizeof( s ) );
		scanf( "%s", s );

		int count = 0, len = strlen( s );
		for( int i = 0; i < len; i++ )
		{
			if( s[ i ] == ch )
				count++;
		}
		printf( "%d\n", count );
	}
	return 0;
}
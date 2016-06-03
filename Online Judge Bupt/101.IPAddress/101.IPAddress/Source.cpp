#include<stdio.h>
#include<string.h>

int judgeIPAddress( char *s )
{
	int dotNum = 0, preData = -1;
	int len = strlen( s );
	for( int i = 0; i < len; i++ )
	{
		if( s[ i ] == '.' )
		{
			if( preData < 0 || preData > 255 )
				return 0;
			dotNum++;
			preData = -1;
		}
		else if( s[ i ] >= '0' && s[ i ] <='9' )
		{
			if( preData == -1 )
				preData = 0;
			preData *= 10;
			preData += s[ i ] - '0';
		}
		else
			return 0;
	}
	if( dotNum == 3 && preData >= 0 && preData <= 255 )
		return 1;
	return 0;
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		char s[ 16 ];
		scanf( "%s", s );
		if( judgeIPAddress( s ) == 1 )
			printf( "Yes\n" );
		else if( judgeIPAddress( s ) == 0 )
			printf( "No\n" );
	}
	return 0;
}
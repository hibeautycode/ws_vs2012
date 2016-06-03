#include<stdio.h>
#include<string.h>
#include<math.h>
#define min( a , b ) ( a < b ) ? a : b

int countCost( char ch1, char ch2 )
{
	return min( abs( ch1-ch2 ), 26 - abs( ch1-ch2 ) );
}
int main()
{
	int T = 0, minCost = 26000, cost = 0, i = 0;
	char c;
	char str[1000];

	scanf( "%d", &T );
	while( T-- )
	{
		minCost = 26000;
		scanf( "%s", str );
		for( c = 'a'; c <= 'z'; c++ )
		{
			cost = 0;
			for( i = 0; i < strlen(str); i++ )
			{
				cost += countCost( str[i], c );
			}
			if( cost < minCost )
				minCost = cost;
		}
		printf( "%d\n", minCost );
	}
	return 0;
}
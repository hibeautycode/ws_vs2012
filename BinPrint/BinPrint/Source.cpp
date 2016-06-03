#include<stdio.h>

void toBin( unsigned int input )
{
	if( input != 0 )
	{
		int tmpBin = input % 2;
		input /= 2;
		toBin( input );
		printf( "%d", tmpBin );
	}
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		unsigned int n;
		scanf( "%d", &n );
		toBin( n );
		printf( "\n" );
	}
	return 0;
}
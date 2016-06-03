#include<stdio.h>

void toBin( long long n )
{	
	if( n != 0 )
	{
		int bin = n % 2;
		n /= 2;
		toBin( n );
		printf( "%d", bin );
	}
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		long long n;
		scanf( "%lld", &n );
		toBin( n );
		printf( "\n" );
	}
	return 0;
}
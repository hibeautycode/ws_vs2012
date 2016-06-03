#include<stdio.h>
#include<math.h>

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int a, b;
		scanf( "%d %d", &a, &b );
		long long a1, b1, c1, m, n;

		a1 = ( long long )pow( ( float )2, a );
		b1 = ( long long )pow( ( float )2, b );

		if( a1 == b1 )
			printf( "1\/%lld\n", ( long long )( a1 / 2 ) );
		else
		{
			m = a1;
			n = b1;
			while( b1 != 0 )
			{
				c1 = a1 % b1;
				a1 = b1;
				b1 = c1;
			}
			//a1则为最大公约数
			printf( "%lld\/%lld\n", ( long long )( ( m + n ) / a1 ), ( long long )( m * n / a1 ) );
		}
	}
	return 0;
}
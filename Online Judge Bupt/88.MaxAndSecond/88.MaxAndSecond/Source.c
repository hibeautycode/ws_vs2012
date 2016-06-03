#include<stdio.h>

int main()
{
	unsigned int T = 0, N = 0, elem = 0, max1 = 0, max2 = 0;

	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &N );
		while( N-- )
		{
			scanf( "%d", &elem );
			if( elem > max1)
			{
				max2 = max1;
				max1 = elem;
			}
			else if( elem < max1 && elem > max2 )
			{
				max2 = elem;
			}			
		}
		printf( "%d %d\n", max1, max2 );
		max1 = max2 = 0;
	}

	return 0;
}
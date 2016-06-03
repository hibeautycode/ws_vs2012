#include<stdio.h>

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N, sumOfOdd, sumOfEven;
		scanf( "%d", &N );
		sumOfOdd = sumOfEven = 0;

		while( N-- )
		{
			int tmp;
			scanf( "%d", &tmp );
			if( tmp % 2 == 0 )
				sumOfEven += tmp;
			else
				sumOfOdd += tmp;
		}
		printf( "%d %d\n", sumOfOdd, sumOfEven );
	}
}
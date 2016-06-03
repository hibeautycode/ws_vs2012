#include<stdio.h>
#include<math.h>
#include<limits.h>
#define INF 2147483647

int A[ 46340 ];

int findBestValue( int a, int maxMinus )
{
	int ret;
	for( int i = 1; i < 46340; i++ )
	{
		if( A[ i ] > a || maxMinus < i )
		{
			ret = i - 1;
			return ret;
		}
		else if( A[ i ] == a )
		{
			ret = i;
			return ret;
		}
	}
}
int main()
{
	int T;
	for( int i = 0; i < 46340; i++ )
	{
		A[ i ] = i * i;
	}
	scanf( "%d", &T );
	while( T-- )
	{
		int count = 0, minLong = INF, maxMinus = 46339;
		int input, tmpValue;
		scanf( "%d", &input );
		maxMinus = findBestValue( input, maxMinus );
		while( maxMinus != 0 )
		{
			count = 0;
			tmpValue = input;
			while( tmpValue )
			{
				tmpValue -= A[ findBestValue( tmpValue, maxMinus ) ];
				count++;
			}
			maxMinus--;
			if( count < minLong )
				minLong = count;
		}
		printf( "%d\n", minLong );
	}
	return 0;
}
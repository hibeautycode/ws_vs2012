#include<stdio.h>
#define INF -10000

int main()
{
	int N;
	scanf( "%d", &N );
	while( N-- )
	{
		int a[ 100 ];
		int M;
		scanf( "%d", &M );
		for( int k = 0; k < 100; k++ )
		{
			a[ k ] = 0;
		}
		int tmpl,l,r,max = INF,count = 0; 
		tmpl = l = r = 0;
		for( int i = 0; i < M; i++ )
		{
			scanf( "%d", &a[ i ] );
			if( count + a[ i ] > max )
			{
				count = count + a[ i ];
				max = count;
				l = tmpl;
				r = i;
			}
			else
			{
				if( count + a[ i ] <= 0 )
				{
					count = 0;
					tmpl = i + 1;
				}
				else
				{
					count += a[ i ];
				}
			}
		}
		printf( "%d %d %d\n", max, l, r );
	}
	return 0;
}
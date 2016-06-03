#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N, max;
		vector< int > V;
		scanf( "%d", &N );
		int n = N;
		while( n-- )
		{
			int tmp;
			scanf( "%d", &tmp);
			V.push_back( tmp );
		}
		int d, tmpMax, tmpPos;
		d = 0;
		max = tmpMax = 1;
		//sort( V.begin(), V.end() );
		for( int i = 0; i < N; i++ )
		{
			for( int j = i + 1; j < N; j++ )
			{
				tmpMax = 1;
				d = V[ j ] - V[ i ];
				tmpMax++;
				tmpPos = j;
				for( int k = j + 1; k < N; k++ )
				{
					if( V[ k ] - V[ tmpPos ] == d )
					{
						tmpMax++;
						tmpPos = k;
					}
				}
				if( tmpMax > max )
					max = tmpMax;
			}
		}
		printf( "%d\n", max );
	}
}
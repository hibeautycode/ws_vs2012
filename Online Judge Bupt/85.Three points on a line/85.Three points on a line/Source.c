#include<stdio.h>

struct Point 
{
	float x;
	float y;
};

void checkThreePointsOnALine( struct Point points[], int n)
{
	float k1 = 0, k2 = 0;
	int i = 0, j = 0, k = 0;
	for( i = 0; i < n - 2; i++ )
	{
		for( j = i + 1; j < n - 1; j++ )
		{
			for( k = j + 1; k < n; k++ )
			{
				k1 = ( points[k].y - points[j].y) / ( points[k].x - points[j].x);
				k2 = ( points[j].y - points[i].y) / ( points[j].x - points[i].x);

				if( k1 == k2 )
				{
					puts( "Yes" );
					return;
				}
			}
		}
	}
	puts( "No" );
}

int main()
{
	int T = 0, N = 0, i = 0;
	struct Point points[100];	

	scanf( "%d", &T );

	while( T-- ) 
	{
		scanf( "%d", &N );
		for( i = 0; i < N; i++ )
		{
			scanf( "%f %f", &points[i].x, &points[i].y );
		}
		checkThreePointsOnALine( points, N );
	}

	return 0;
}
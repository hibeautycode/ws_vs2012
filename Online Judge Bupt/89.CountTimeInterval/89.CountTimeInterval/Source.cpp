#include<stdio.h>

int main()
{
	int T = 0,  i = 0, interval = 0;

	struct time
	{
		int x;
		int y;
	};
	struct time start, end;

	scanf( "%d", &T );
	for( i = 0; i < T; i++ )
	{
		scanf( "%d:%d", &start.x, &start.y );
		scanf( "%d:%d", &end.x, &end.y );
		interval = ( end.x-start.x ) * 60 + ( end.y - start.y );
		printf( "%d\n", interval + 1440 * (interval < 0 ) ) ;
	}

	return 0;
}
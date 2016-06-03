#include<stdio.h>
#include<string.h>
#include<math.h>
#define PI acos( -1.0 )
#define MAX( a, b ) a > b ? a : b

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N;
		double forwardValue, backwardValue, bestAngle;
		int angleAvailable[ 360 ], lastAngleAvailable[ 360 ];
		char command[ 10 ];
		scanf( "%d", &N );
		forwardValue = backwardValue = bestAngle = 0;
		memset( angleAvailable, 0, sizeof( angleAvailable ) );
		memset( lastAngleAvailable, 0, sizeof( lastAngleAvailable ) );
		angleAvailable[ 0 ] = lastAngleAvailable[ 0 ] = 1;
		while( N-- )
		{
			scanf( "%s", command );
			int X;
			scanf( "%d", &X );
			if( strcmp( command, "forward" ) == 0 )
			{				
				forwardValue += X;
			}
			else if( strcmp( command, "backward" ) == 0 )
			{
				backwardValue += X;
			}
			else if( strcmp( command, "left" ) == 0 || strcmp( command, "right" ) == 0 )
			{
				X = strcmp( command, "left" ) ? ( 360 - X ) : X;
				
				for( int i = 0; i < 360; i++ )
				{
					int temp = ( X + i ) % 360;
					if( lastAngleAvailable[ i ] && !angleAvailable[ temp ] )
					{
						angleAvailable[ temp ] = 1;
					}
				}

				for( int i = 0; i < 360; i++ )
				{
					lastAngleAvailable[ i ] = angleAvailable[ i ];
				}
			}			
		}
		for( int i = 0; i < 360; i++ )
		{
			if( angleAvailable[ i ] == 1 )
			{
				bestAngle = MAX( ( i > 180 ? 360 - i : i ), bestAngle );
			}
		}
		double maxDis;
		maxDis = forwardValue * forwardValue + backwardValue * backwardValue - 2 * forwardValue * backwardValue * cos( bestAngle /180.0 * PI );
		printf( "%.3lf\n", sqrt( maxDis ) );
	}
	return 0;
}
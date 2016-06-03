#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
#define MAX_SIZE 100000

void queryMinDis( vector<int> array[], char ch[], int index )
{
	int i = 0, minDis = 100000;
	
	if( array[ ch[ index ] - 'a' ].size() == 1 || index >= strlen( ch ) )
	{
		printf( "-1\n" );
		return;
	}
	
	int len = array[ ch[ index ] - 'a' ].size();
	for( i = 0; i < len; i++ )
	{
		if( abs( array[ ch[ index ] - 'a' ][i] - index ) < minDis && abs( array[ ch[ index ] - 'a' ][i] - index ) != 0 )
			minDis = abs( array[ ch[ index ] - 'a' ][i] - index );
	}
	printf( "%d\n", minDis );
	return;
}

int main()
{
	int T, index, i;
	char command[10], ch[2];
	
	scanf( "%d", &T );
	while( T-- )
	{
		vector<int> *p;
		p = new vector<int> [26];
		char S[ MAX_SIZE ];
		memset( S, 0, sizeof( S ) );
		scanf( "%s", S );		
		
		int len = strlen( S );
		for( i = 0; i < len; i++ )
		{
			p[ S[i] - 'a' ].push_back( i );
		}

		int m;
		scanf( "%d", &m );
		while( m-- )
		{
			scanf( "%s", command );

			if( strcmp( command, "INSERT" ) == 0 )
			{
				scanf( "%s", &ch );
				strcat( S, ch );
				p[ ch[0] - 'a' ].push_back( strlen( S ) - 1 );
			}
			else if( strcmp( command, "QUERY" ) == 0 )
			{
				scanf( "%d", &index );
				queryMinDis( p, S, index );
			}
		}
		delete []p;
	}
	return 0;
}
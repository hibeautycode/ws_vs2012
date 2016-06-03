#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct pythonList
{
	char name[ 15 ];
	vector<int> array;
};
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N;
		scanf( "%d", &N );
		pythonList list[ 100 ];
		int listNum = 0, curId = 0;
		while( N-- )
		{
			char s[ 100 ];
			char tmpS[ 15 ];
			memset( tmpS, 0, sizeof( tmpS ) );
			int tmpSPos = 0;
			getchar();
			scanf( "%[^\n]", s );
			int len = strlen( s );
			for( int i = 0; i < len; i++ )
			{
				if( s[ i ] == '=' )
				{
					curId = -1;
					tmpS[ tmpSPos ] = '\0';
					for( int pos = 0; pos < listNum; pos++ )
					{
						if( !strcmp( list[ pos ].name, tmpS ) )
						{
							curId = pos;
							break;
						}
					}
					if( curId == -1 )
					{
						curId = listNum;
						strcpy( list[ listNum++ ].name, tmpS );
					}
					else
					{
						if( ! list[ curId ].array.empty() )
							list[ curId ].array.clear();
					}
					break;
				}
				else if( s[ i ] == '.' && s[ i + 1 ] == 'a' )
				{
					tmpS[ tmpSPos ] = '\0';
					for( int pos = 0; pos < listNum; pos++ )
					{
						if( !strcmp( list[ pos ].name, tmpS ) )
						{
							curId = pos;
							break;
						}
					}
					int sum = 0;
					int k = i + 8;
					while( s[ k ] != ')' )
					{
						sum = sum * 10 + ( s[ k ] - '0' );
						k++;
					}
					list[ curId ].array.push_back( sum );
					break;
				}
				else if( s[ i ] == '.' && s[ i + 1 ] == 's' )
				{
					tmpS[ tmpSPos ] = '\0';
					for( int pos = 0; pos < listNum; pos++ )
					{
						if( !strcmp( list[ pos ].name, tmpS ) )
						{
							curId = pos;
							break;
						}
					}
					sort( list[ curId ].array.begin(), list[ curId ].array.end() );
					break;
				}
				else if( s[ i ] == '[' )
				{
					tmpS[ tmpSPos ] = '\0';
					for( int pos = 0; pos < listNum; pos++ )
					{
						if( ! strcmp( list[ pos ].name, tmpS ) )
						{
							curId = pos;
							break;
						}
					}
					int num = 0, k = i + 1;
					while( s[ k ] != ']' )
					{
						num = num * 10 + ( s[ k ] - '0' );
						k++;
					}
					if( num >= list[ curId ].array.size() )
						printf( "ERROE\n" );
					else
						printf( "%d\n", list[ curId ].array[ num ] );
					break;
				}
				tmpS[ tmpSPos++ ] = s[ i ];
			}
		}
	}
	return 0;
}
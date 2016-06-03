#include"stdio.h"
#include"string.h"
#include<vector>
using namespace std;

struct student
{
	int id;
	int score;
};
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		vector< student > V;
		int N, id, sco;
		student stu;
		char command[ 10 ];
		scanf( "%d", &N );
		while( N-- )
		{
			scanf( "%s", command );
			if( strcmp( command, "Insert" ) == 0 )
			{
				scanf( "%d %d", &id, &sco );
				stu.id = id;
				stu.score = sco;
				V.push_back(stu);
			}
			else if( strcmp( command, "Find" ) == 0 )
			{
				scanf( "%d", &id );
				bool flag = false;
				for( int i = 0; i < V.size(); i++ )
				{
					if( V[ i ].id == id )
					{
						printf( "name:%d score:%d\n", V[ i ].id, V[ i ].score );
						flag = true;
						break;
					}
				}
				if( flag == false )
					printf( "No result!\n" );
			}
		}
	}
	return 0;
}
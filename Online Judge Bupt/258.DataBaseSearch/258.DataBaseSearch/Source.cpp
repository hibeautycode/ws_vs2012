#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

struct Birthday
{
	string year;
	string month;
	string day;
};
struct student
{
	string Name;
	string Sex;
	struct Birthday Birth;
};
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N, M;
		scanf( "%d %d", &N, &M );
		vector< student > StudentVector;
		student tmpStudent;
		int n = N;
		while( n-- )
		{			
			char tmpName[ 35 ];
			char tmpSex[ 10 ];
			char birth[ 20 ];
			scanf( "%s %s %s", tmpName, tmpSex, birth );
			tmpStudent.Name = tmpName;
			tmpStudent.Sex = tmpSex;

			string tmpString = birth;
			tmpStudent.Birth.year = tmpString.substr( 0, 4 );
			tmpStudent.Birth.month = tmpString.substr( 5, 2 );
			tmpStudent.Birth.day = tmpString.substr( 8, 2 );

			StudentVector.push_back( tmpStudent );
		}
		
		while( M-- )
		{
			char s;
			string nameLimit, sexLimit, birthLimit, tmpString;
			bool isName = false, isSex = false, isBirth = false;
			fflush( stdin );
			while( ( s = getchar() ) != '\n' )
			{
				if( s == ' ' )
				{
					if( isName )
						nameLimit = tmpString;
					else if( isSex )
						sexLimit = tmpString;
					else if( isBirth )
						birthLimit = tmpString;
					isName = isSex = isBirth = false;
					tmpString = "";
					continue;
				}
				else if( s == '=' )
				{
					if( tmpString.compare( "Name" ) == 0 )
					{
						isName = true;
					}
					else if( tmpString.compare( "Sex" ) == 0 )
					{
						isSex = true;
					}
					else if( tmpString.compare( "Birthday" ) == 0 )
					{
						isBirth = true;
					}
					tmpString = "";
					continue;
				}
				else if( s == '\'' )
				{
					continue;
				}
				tmpString += s;		
			}
			if( isName )
				nameLimit = tmpString;
			else if( isSex )
				sexLimit = tmpString;
			else if( isBirth )
				birthLimit = tmpString;

			string yearLimit, monthLimit, dayLimit;
			int birthLen = birthLimit.length();
			tmpString = "";
			int birthPos = 0;
			if( birthLen > 0 )
			{
				for( int i = 0; i < birthLen; i++ )
				{
					if( birthLimit[ i ] == '\/' )
					{
						birthPos++;
						if( birthPos == 1 && tmpString.compare( "*" ) )
						{
							yearLimit = tmpString;
						}
						else if( birthPos == 2 && tmpString.compare( "*" ) )
						{
							monthLimit = tmpString;
						}
						tmpString = "";
						continue;
					}
					tmpString += birthLimit[ i ];
				}
				if( tmpString.compare( "*" ) )
				{
					dayLimit = tmpString;
				}
			}
			bool existElem = false;
			for( int i = 0; i < N; i++ )
			{
				if( ( ! StudentVector[ i ].Name.compare( nameLimit ) || nameLimit.empty() ) &&
					( ! StudentVector[ i ].Sex.compare( sexLimit ) || sexLimit.empty() ) &&
					( ! StudentVector[ i ].Birth.year.compare( yearLimit ) || yearLimit.empty() ) &&
					( ! StudentVector[ i ].Birth.month.compare( monthLimit ) || monthLimit.empty() ) &&
					( ! StudentVector[ i ].Birth.day.compare( dayLimit ) || dayLimit.empty() ) )
				{
					for( int j = 0; j < StudentVector[ i ].Name.length(); j++ )
					{
						printf( "%c", StudentVector[ i ].Name[ j ] );
					}
					existElem = true;					
					printf( "\n" );
				}
			}
			if( ! existElem )
				printf( "NULL\n" );
		}
	}
	return 0;
}
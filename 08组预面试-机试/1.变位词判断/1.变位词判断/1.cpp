#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	scanf( "%d", &N );
	while( N-- )
	{
		char ch1[100],ch2[100];
		int count1[ 26 ], count2[ 26 ];
		int isFlag = true;
		scanf( "%s %s", ch1,ch2 );
		for( int i = 0; i < 26; i++ )
		{
			count1[ i ] = count2[ i ] = 0;
		}
		if( strlen( ch1 ) == strlen( ch2 ) )
		{
			int len = strlen( ch1 );
			for( int i = 0; i < len; i++ )
			{
				count1[ ch1[ i ] - 'a' ]++;
				count2[ ch2[ i ] - 'a' ]++;
			}
			for( int i = 0; i < 26; i++ )
			{
				if( count1[ i ] != count2[ i ] )
				{
					printf( "No\n" );
					isFlag = false;
					break;
				}
			}
			if( isFlag )
				printf( "Yes\n" );
		}
		else
		{
			printf( "No\n" );
		}
	}
	getchar();
	getchar();
	return 0;
}
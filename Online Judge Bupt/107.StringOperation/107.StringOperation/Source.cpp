#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	char ss[205];  
    while( scanf("%s",ss) != EOF )
	{
		string s = ss;
		int t;
		scanf( "%d", &t );
		while( t-- )
		{
			int op, pos, len;
			string subStr;
			scanf( "%d", &op );
			scanf( "%d %d", &pos, &len );
			if( op == 0 )
			{
				subStr = s.substr( pos, pos + len );
				for( int i = 0; i < len; i++ )
				{
					s[ pos++ ] = subStr[ len - i - 1 ];
				}
				//reverse( s.begin() + pos, s.begin() + pos + len );	
			}
			else if( op == 1 )
			{
				cin >> subStr;
				s.replace( pos, len, subStr );
			}
			cout << s << endl;
		}
	}
	return 0;
}
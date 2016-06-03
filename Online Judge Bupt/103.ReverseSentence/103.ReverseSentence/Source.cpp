#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
#define MAX_SIZE 1000
using namespace std;


int main()
{
	string s;
	
	while( getline( cin, s ) )
	{
		stack< string > wordStack;
		int front = 0, rear = 0;
		int len = s.length();

		for( int i = 0; i < len; i++ )
		{
			if( s[ i ] == ' ' )
			{
				string tmp = s.substr( front, rear - front );
				wordStack.push( tmp );
				rear++;
				front = rear;
			}
			else if( i == len - 1 )
			{
				string tmp = s.substr( front, len - front );
				wordStack.push( tmp );
			}
			else
			{
				rear++;
			}
		}		
		while( ! wordStack.empty() )
		{
			cout << wordStack.top();
			wordStack.pop();
			if( ! wordStack.empty() )
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
#include<stdio.h>

int main()
{
	int T = 0, X = 0, Y = 0, Z = 0, day = 0;
	int LeapYear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int CommonYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d:%d:%d", &X, &Y, &Z );
		if( ( X % 400 == 0 ) || ( X % 100 != 0 && X % 4 == 0 ) )
		{
			while( --Y )
			{
				day += LeapYear[ Y - 1 ]; 
			}
			day += Z;
			printf( "%d\n", day );
		}
		else
		{
			while( --Y )
			{
				day += CommonYear[ Y - 1 ]; 
			}
			day += Z;
			printf( "%d\n", day );
		}
		day = 0;
	}
	return 0;
}
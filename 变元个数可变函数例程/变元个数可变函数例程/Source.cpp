#include<stdio.h>
#include<stdarg.h>

double average( double v1, double v2,... )
{
	va_list parg;	// Pointer for variable argument list
	double sum = v1 + v2;
	double value = 0;

	int count = 2;	// Count of number of arguments
	va_start( parg, v2 );	//Initialize argument pointer

	while( ( value = va_arg( parg, double ) ) != 0.0 )
	{
		sum += value;
		count++;
	}
	va_end( parg );	// End variable argument process
	return sum / count;
}
int main()
{
	printf( "\n Average = %lf", average( 1.0, 2.0, 3.0 ) );
	printf( "\n Average = %lf", average( 1.0, 2.0, 3.0, 4.0, 5.0 ) );
	printf( "\n Average = %lf\n", average( 1.0, 2.0 ) );
	while( 1 );
	return 0;
}
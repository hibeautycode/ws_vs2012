#include "sort_algorithm.h"

/*************************************************** 
 RadixSort
 ---------------------------------------------------
      Stability    |   stable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst   
 ---------------------------------------------------
  Time  complexity |          |  O(d*n)  |           note: d is the max digit of allowed integer
 ---------------------------------------------------
  Space complexity |          |  O(10n)  |      
 ---------------------------------------------------
***************************************************/

#define RADIX_10 10     
#define KEYNUM_31 31     // max digit of an integer

int GetNumInPos( ElementType a, int pos )		
{  
	int tmp = 1;  
	for ( int i = 0; i < pos - 1; i++ )  
		tmp *= 10;  

	return ( a / tmp ) % 10;  
}  
  
void RadixSort( ElementType A[] , int n )  
{  
	ElementType *radixArrays[RADIX_10];    // 0~9 sequence space

	for ( int i = 0; i < 10; i++ )  
	{  
		radixArrays[ i ] = ( ElementType* )malloc( sizeof( ElementType ) * ( n + 1 ) );  
		radixArrays[ i ][ 0 ] = 0;    // radixArrays[i][0] records the number of this line's figure  
	}  

	for ( int pos = 1; pos <= KEYNUM_31; pos++ )   
	{  
		for ( int i = 0; i < n; i++ )    // distribute process 
		{  
			int num = GetNumInPos( A[ i ], pos );  
			int index = ++radixArrays[ num ][ 0 ];  
			radixArrays[ num ][ index ] = A[ i ];  
		}  

		for ( int i = 0, j = 0; i < RADIX_10; i++ )    // collect process 
		{  
			for ( int k = 1; k <= radixArrays[ i ][ 0 ]; k++ )  
				A[ j++ ] = radixArrays[ i ][ k ];  
			radixArrays[ i ][ 0 ] = 0;    // reset
		}  
	}  
} 

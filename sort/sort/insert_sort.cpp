#include "sort_algorithm.h"

/***************************************************
 InsertSort
 ---------------------------------------------------
      Stability    |   stable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst  
 ---------------------------------------------------
  Time  complexity |   O(n)   |   O(n^2) |  O(n^2)  
 ---------------------------------------------------
  Space complexity |   O(1)   |   O(1)   |  O(1)    
 ---------------------------------------------------
***************************************************/

void InsertSort( ElementType A[ ], int n )
{
	int j, i;
	ElementType tmp;  //guard variable

	for( i = 1; i < n; i++ )
	{
		tmp = A[ i ];
		for( j = i; j > 0 && A[ j - 1 ] > tmp; j-- )  //insert A[i] to the sorted sequence which is A[0]...A[P-1]
			A[ j ] = A[ j - 1 ];
		A[ j ] = tmp;
	}
}
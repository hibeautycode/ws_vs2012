#include "sort_algorithm.h"

/***************************************************  
 QuickSort
 ---------------------------------------------------
      Stability    |   unstable                     
 ---------------------------------------------------
 ---------------------------------------------------
                   |   best   |   mean   |   worst   
 ---------------------------------------------------
  Time  complexity |		  |			 |  O(n^2)  
 ---------------------------------------------------
  Space complexity |   O(1)   |   O(1)   |  O(1)    
 ---------------------------------------------------
***************************************************/

void ShellSort( ElementType A[], int n )
{
	int i, j, Increment;
	ElementType Tmp;

	for( Increment = n / 2; Increment > 0; Increment /= 2 )  //shrink the interval of the values from the same subsequence
		for( i = Increment; i < n; i++ )  //sort the split subsequence
		{
			Tmp = A[ i ];
			for( j = i; j >= Increment; j -= Increment )  //insert a[i] to the split sorted subsequence which is ...a[i-2*Increment],a[i-Increment]
				if( Tmp < A[ j - Increment ] )
					A[ j ] = A[ j - Increment ];
				else
					break;
			A[ j ] = Tmp;
		}
}
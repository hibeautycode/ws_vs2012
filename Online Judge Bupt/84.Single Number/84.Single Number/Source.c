#include<stdio.h>

/*--------------------------------------------------------------------------------------------------
题目：
Given an array with N integers where all elements appear three times except for one. 
Find out the one which appears only once.
----------------------------------------------------------------------------------------------------
题目分析：
对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，将所有这些1清零，剩下的就是最终的数。

用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的 1）的数位。
用twos记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的数位。
当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。
即用二进制模拟三进制计算。最终ones记录的是最终结果。
----------------------------------------------------------------------------------------------------*/

int main()
{
	int N = 0;
	long long one = 0, two = 0, three = 0, elem = 0;  

	while( scanf( "%d", &N ) != EOF )
	{
		while( N-- )
		{
			scanf( "%lld", &elem );

			two |= one & elem;	// two累计本轮与上一轮one中都出现二进制1的数位，并包括了出现3次二进制1的数位
			one ^= elem;	// one清零本轮与上一轮都为1的数位（即出现2次二进制1的数位），并包括了出现3次二进制1的数位
			three = one & two;
			one &= ~three; 
			two &= ~three;
		}

		printf("%lld\n", one );

		one = two = three = elem = 0;
	}
	return 0;
}
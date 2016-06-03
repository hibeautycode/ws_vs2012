#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
		int tmp;
		if(x>0)
			tmp=x;
		else
			tmp=-x;
        int ret=0;
        while(tmp)
        {
            if (ret > INT_MAX/10)
            {
             return 0;
            }
            ret=ret*10+tmp%10;
            tmp/=10;
        }
        ret=(x>0)?ret:(-ret);
        return ret;
    }
};
int main()
{
	Solution sol;
	int x=-34;
	x%=10;
	cout<<x;
	return 0;
}
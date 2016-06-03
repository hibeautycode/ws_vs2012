#include <stdio.h>  
#include <math.h>  
#define MIN(x,y) (x)<(y)?(x):(y)  
#define INF 1000000003  
    
long long s(long long x)  
{  
    long long sum=0;  
    while(x){  
        sum+=x%10;  
        x/=10;  
    }  
    return sum;  
}  
    
int main()  
{  
    long long x, n, min=INF;  
    int i, k;  
    scanf("%lld",&n);  
    for(i=(int)sqrt((float)n),k=1; k<=9*9 && i>0; k++, i--)  
        if(((long long)(i)*(long long)(i)+(long long)(s(i)*i))==n) min=MIN(min,i);  
    printf("%lld\n",min==INF?-1:min);  
    return 0;  
} 
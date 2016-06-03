#include<iostream>  
#include<vector>  
#include<cstdio>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
typedef struct node  
{  
    int x,y;  
}Node;  
bool cmp(Node a,Node b)  
{  
    double m=sqrt(a.x*a.x+a.y*a.y);  
    double n=sqrt(b.x*b.x+b.y*b.y);  
    return m>n;  
}  
int main()  
{  
    int t;  
    while(~scanf("%d",&t))  
    {  
        while(t--)  
        {  
            int n,i;  
            scanf("%d",&n);  
            vector<Node> vec;  
            char op[10];  
            while(n--)  
            {  
                int x,y;  
                scanf("%s",op);  
                if(op[0]=='P')  
                {  
                    if(vec.size()==0)  
                        printf("Empty!\n");  
                    else  
                    {  
                        sort(vec.begin(),vec.end(),cmp);  
                        printf("%d+i%d\n",vec[0].x,vec[0].y);  
                        vec.erase(vec.begin());  
                        if(vec.size()>0)  
                        printf("Size: %d\n",vec.size());  
                        else  
                        printf("Empty!\n");  
                    }  
                }  
                else  
                {  
                    Node node;  
                    scanf("%d+i%d",&node.x,&node.y);  
                    vec.push_back(node);  
                    printf("Size: %d\n",vec.size());  
                }  
  
  
            }  
        }  
    }  
}
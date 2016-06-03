//******************************************************************************************************************************
//             KMP算法的C语言代码实现
//
//核心思想：匹配过程中匹配不等时，不需回溯i指针，而是利用已经得到的“部分匹配”结果将模式向右“滑动”尽可能远的一段距离继续比较。 
//******************************************************************************************************************************

#include <stdio.h>
#include <string.h> 

#define TLen 5  //定义模式串长度

//利用模式串的T的NEXT函数求t在主串s中的第pos个位置之后的位置的KMP算法，（t非空，1<=pos<=Strlength(s)）.
int index_KMP(char *s,char *t,int *next,int pos) 	
{ 
	int i=pos,j=1; 
	while (i<=(int)strlen(s) && j<=(int)strlen(t)) 
	{ 
		if (j==0  ||  s[i]==t[j-1]) //继续进行后续字符串的比较
		{      
			i++; 
			j++; 
		} 
		else j=next[j]; //模式串向右移动
	} 

	if (j>(int)strlen(t)) //匹配成功
		return i-strlen(t)+1; 
	else //匹配不成功 
		return 0; 
} 
//求模式串t的next函数的并存入数组next[]中。
void get_next(char *t,int *next) 	
{ 
	int i=1,j=0; 
	next[0]=next[1]=0; 

	while (i<(int)strlen(t)) 
	{ 
		if (j==0 || t[i]==t[j]) 
		{ 
			i++; 
			j++; 
			next[i]=j; 
		} 
		else j=next[j]; 
	} 
}

void main() 

{ 
	char s[20]="adjfskjfskdjsfkglsi"; 
	//char t[TLen]="skdj"; 
	char t[TLen]="aaaa"; 
	int next[TLen]; 
	int pos=0; 
	int n; 

	get_next(t,next); 

	printf( "The next array of string %s is : ", t );
	for(int i=0; i<TLen; i++)
		printf( "%d ", next[i] );
	printf( "\n" );
	n=index_KMP(s,t,next,pos); 

	if(n!=0)
		printf("\n模式串 t 在主串 s 中第 %d 个位置之后。\n\n",n); 

	else
		printf("\n主串中不存在与模式串相匹配的子串!\n\n");
	getchar();
} 


//******************************************************************************************************************************
//             KMP�㷨��C���Դ���ʵ��
//
//����˼�룺ƥ�������ƥ�䲻��ʱ���������iָ�룬���������Ѿ��õ��ġ�����ƥ�䡱�����ģʽ���ҡ�������������Զ��һ�ξ�������Ƚϡ� 
//******************************************************************************************************************************

#include <stdio.h>
#include <string.h> 

#define TLen 5  //����ģʽ������

//����ģʽ����T��NEXT������t������s�еĵ�pos��λ��֮���λ�õ�KMP�㷨����t�ǿգ�1<=pos<=Strlength(s)��.
int index_KMP(char *s,char *t,int *next,int pos) 	
{ 
	int i=pos,j=1; 
	while (i<=(int)strlen(s) && j<=(int)strlen(t)) 
	{ 
		if (j==0  ||  s[i]==t[j-1]) //�������к����ַ����ıȽ�
		{      
			i++; 
			j++; 
		} 
		else j=next[j]; //ģʽ�������ƶ�
	} 

	if (j>(int)strlen(t)) //ƥ��ɹ�
		return i-strlen(t)+1; 
	else //ƥ�䲻�ɹ� 
		return 0; 
} 
//��ģʽ��t��next�����Ĳ���������next[]�С�
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
		printf("\nģʽ�� t ������ s �е� %d ��λ��֮��\n\n",n); 

	else
		printf("\n�����в�������ģʽ����ƥ����Ӵ�!\n\n");
	getchar();
} 


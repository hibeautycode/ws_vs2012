#include<stdio.h>
int num(char *c){               // �ַ�ת��Ϊ���� 
    if(*c>='0'&&*c<='9') return *c-'0';
    else return *c-'a'+10;    
}
int sum1(char *p){              // ���ַ 
    return 16*num(p)+num(p+1);  
}  
int sum2(char *p){             // ��˿� 
    return 256*16*num(p)+256*num(p+1)+16*num(p+3)+num(p+4);  
}  
int main(){  
    int n, c = 1;  
    while(scanf("%d", &n)!=EOF){ 
        char str[1000]; 
        gets(str);                            
        while(n--){  
            gets(str);                    //�ӻ�������ȡ�ַ���  
            int IHL = num(str+1)*4*3;      //����ipͷ������.  
            printf("Case #%d\nTotal length = %d bytes\n", c++, sum2(str+6));  
            printf("Source = %d.%d.%d.%d\n", sum1(str+36),sum1(str+39),sum1(str+42),sum1(str+45));  
            printf("Destination = %d.%d.%d.%d\n",sum1(str+48),sum1(str+51),sum1(str+54),sum1(str+57));  
            printf("Source Port = %d\n",sum2(str+IHL));  
            printf("Destination Port = %d\n\n",sum2(str+IHL+6));  
        }
    }  
    return 0;  
} 
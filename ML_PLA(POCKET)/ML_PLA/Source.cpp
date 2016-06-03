#include<fstream>
#include<iostream>  
#include<vector>  
#include<ctime>
using namespace std;  

#define PLA
//#define POCKET
  
//�Զ�ά�ռ�Ϊ����x1 x2Ϊ����  
struct Item{  
    int x0;  
    double x1,x2;  
    int label;  
};  
//Ȩ�ؽṹ�壬w1 w2Ϊ����x1 x2��Ȩ�أ���ʼֵȫ��Ϊ0  
struct Weight{  
    double w0,w1,w2;//  
}Wit0={0,0,0};  
  
//���ź��������������ڻ��͵��ص��ж��Ƿ�Ӧ�÷������ÿ�  
int sign(double x){  
    if(x>0)  
        return 1;  
    else if(x<0)  
        return -1;  
    else
		return 0;  
}  
//�����������ڻ�  
double DotPro(Item item,Weight weight){  
    return item.x0*weight.w0+item.x1*weight.w1+item.x2*weight.w2;  
}  
//����Ȩ��  
Weight UpdateWeight(Item item,Weight weight){  
    Weight newWeight;  
    newWeight.w0=weight.w0+item.x0*item.label;  
    newWeight.w1=weight.w1+item.x1*item.label;  
    newWeight.w2=weight.w2+item.x2*item.label;  
    return newWeight;  
}  
#ifdef PLA
int main(){  
      
    vector<Item> ivec;  
    Item temp;  
	ifstream input("data0.txt");	//���Կɷֵ����뼯
	ofstream output("data1.txt");

	while(input>>temp.x1>>temp.x2>>temp.label){  
        temp.x0=1;  
        ivec.push_back(temp);  
    } 
    Weight wit=Wit0;  
    for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  
        if((*iter).label!=sign(DotPro(*iter,wit))){  
            wit=UpdateWeight(*iter,wit);  
            iter=ivec.begin();//�ڴ�ͷ��ʼ�жϣ���Ϊ����Ȩ�غ���ܻᵼ��ǰ��ĵ�����ϣ���Ҫ��ͷ���ж�  
			output<<wit.w0<<" "<<wit.w1<<" "<<wit.w2<<endl;
        }  
    }  
    //��ӡ���  
    cout<<wit.w0<<" "<<wit.w1<<" "<<wit.w2<<" "<<endl; 
	while(1);
}
#endif
#ifdef POCKET
int countErr(vector<Item> ivec, Weight wit)	//ͳ�Ƹ�Ȩ��������Ӧ�������
{
	int count=0;
	for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  
		if((*iter).label!=sign(DotPro(*iter,wit))){  
			count++;
		}  
	}  
	return count;
}
int main(){  
      
    vector<Item> ivec;  
    Item temp;  
	ifstream input("data0.txt");	//���Կɷֵ����뼯
	ofstream output("data1.txt");

	while(input>>temp.x1>>temp.x2>>temp.label){  
        temp.x0=1;  
        ivec.push_back(temp);  
    } 
    Weight wit=Wit0;  
	Weight pwt=wit;	//��¼���������ٵ�Ȩ������
	int iterTimes=ivec.size()*100;
    for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  //��ȡһ�����ŵ�pwt����
        if((*iter).label!=sign(DotPro(*iter,wit))){  
            wit=UpdateWeight(*iter,wit);  
			if(countErr(ivec,pwt)>countErr(ivec,wit))
			{
				pwt=wit;
				output<<pwt.w0<<" "<<pwt.w1<<" "<<pwt.w2<<" "<<endl;
			}
			iter=ivec.begin();//�ڴ�ͷ��ʼ�жϣ���Ϊ����Ȩ�غ���ܻᵼ��ǰ��ĵ�����ϣ���Ҫ��ͷ���ж�
			if(!(iterTimes--))
				break;
        }  
    }  
	srand((unsigned)time(NULL));
	vector<Item> errVec;
	int T=100;
	while(T--)	//��һ���Ż�pwt����
	{
		for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  
			if((*iter).label!=sign(DotPro(*iter,pwt))){  
				errVec.push_back(*iter);
			}  
		}
		if(errVec.size()>0)
		{
			wit=UpdateWeight(errVec[rand()%errVec.size()],pwt);  
			if(countErr(ivec,pwt)>countErr(ivec,wit))
			{
				pwt=wit;
				output<<pwt.w0<<" "<<pwt.w1<<" "<<pwt.w2<<" "<<endl;
			}
		}
		else
		{
			break;
		}
	}
    //��ӡ���  
    cout<<pwt.w0<<" "<<pwt.w1<<" "<<pwt.w2<<" "<<countErr(ivec,pwt)<<endl; 
	while(1);
}
#endif
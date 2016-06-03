#include<fstream>
#include<iostream>  
#include<vector>  
#include<ctime>
using namespace std;  

#define PLA
//#define POCKET
  
//以二维空间为例，x1 x2为属性  
struct Item{  
    int x0;  
    double x1,x2;  
    int label;  
};  
//权重结构体，w1 w2为属性x1 x2的权重，初始值全设为0  
struct Weight{  
    double w0,w1,w2;//  
}Wit0={0,0,0};  
  
//符号函数，根据向量内积和的特点判断是否应该发放信用卡  
int sign(double x){  
    if(x>0)  
        return 1;  
    else if(x<0)  
        return -1;  
    else
		return 0;  
}  
//两个向量的内积  
double DotPro(Item item,Weight weight){  
    return item.x0*weight.w0+item.x1*weight.w1+item.x2*weight.w2;  
}  
//更新权重  
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
	ifstream input("data0.txt");	//线性可分的输入集
	ofstream output("data1.txt");

	while(input>>temp.x1>>temp.x2>>temp.label){  
        temp.x0=1;  
        ivec.push_back(temp);  
    } 
    Weight wit=Wit0;  
    for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  
        if((*iter).label!=sign(DotPro(*iter,wit))){  
            wit=UpdateWeight(*iter,wit);  
            iter=ivec.begin();//在从头开始判断，因为更新权重后可能会导致前面的点出故障，需要从头再判断  
			output<<wit.w0<<" "<<wit.w1<<" "<<wit.w2<<endl;
        }  
    }  
    //打印结果  
    cout<<wit.w0<<" "<<wit.w1<<" "<<wit.w2<<" "<<endl; 
	while(1);
}
#endif
#ifdef POCKET
int countErr(vector<Item> ivec, Weight wit)	//统计该权重向量对应错误个数
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
	ifstream input("data0.txt");	//线性可分的输入集
	ofstream output("data1.txt");

	while(input>>temp.x1>>temp.x2>>temp.label){  
        temp.x0=1;  
        ivec.push_back(temp);  
    } 
    Weight wit=Wit0;  
	Weight pwt=wit;	//记录错误数最少的权重向量
	int iterTimes=ivec.size()*100;
    for(vector<Item>::iterator iter=ivec.begin();iter!=ivec.end();++iter){  //获取一个较优的pwt向量
        if((*iter).label!=sign(DotPro(*iter,wit))){  
            wit=UpdateWeight(*iter,wit);  
			if(countErr(ivec,pwt)>countErr(ivec,wit))
			{
				pwt=wit;
				output<<pwt.w0<<" "<<pwt.w1<<" "<<pwt.w2<<" "<<endl;
			}
			iter=ivec.begin();//在从头开始判断，因为更新权重后可能会导致前面的点出故障，需要从头再判断
			if(!(iterTimes--))
				break;
        }  
    }  
	srand((unsigned)time(NULL));
	vector<Item> errVec;
	int T=100;
	while(T--)	//进一步优化pwt向量
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
    //打印结果  
    cout<<pwt.w0<<" "<<pwt.w1<<" "<<pwt.w2<<" "<<countErr(ivec,pwt)<<endl; 
	while(1);
}
#endif
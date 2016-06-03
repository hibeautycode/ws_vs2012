#define MAXV 100  //��󶥵���� 
 
//�ڽӾ������Ͷ���
typedef struct 
{ 
	int no;    //������ 
	int info;  //����Ȩֵ 
}VertexType;   //�������� 

typedef struct   //ͼ�Ķ��� 
{ 
	int edges[MAXV][MAXV]; //�ڽӾ��� 
	int vexnum,edgnum;    //���������� 
	VertexType vexs[MAXV];  //��Ŷ�����Ϣ 
}MGraph;     //ͼ���ڽӾ������� 

//�ڽӱ����Ͷ���
typedef int Vertex;   //�ڽӱ������Ͷ���

typedef struct ArcNode  //���Ľ��ṹ���� 
{ 
	int adjvex;    //�û����յ�λ�� 
	int info;   //����Ȩֵ 
	ArcNode *nextarc; //ָ����һ����ָ�� 
}ArcNode;      

typedef struct   //�ڽӱ�ͷ�������� 
{ 
	Vertex data;   //������Ϣ 
	ArcNode *firstarc;  //ָ���һ���� 
}AdjList[MAXV]; //AdjList���ڽӱ����� 

typedef struct
{ 
	AdjList adjlist;  //�ڽӱ� 
	int vexnum,arcnum;    //ͼ�ж��������� 
}ALGraph;     //ͼ���ڽӱ����� 

void MatTOList(MGraph g,ALGraph *&G);  //ͼG���ڽӾ���ת�����ڽӱ�
void ListToMat(ALGraph *G,MGraph &g);  //ͼG���ڽӱ�ת�����ڽӾ���
void DispMat(MGraph g);   //����ڽӾ���g
void DispAdj(ALGraph *G);  //����ڽӱ�G 
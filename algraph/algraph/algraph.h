#define MAXV 100  //最大顶点个数 
 
//邻接矩阵类型定义
typedef struct 
{ 
	int no;    //顶点编号 
	int info;  //顶点权值 
}VertexType;   //顶点类型 

typedef struct   //图的定义 
{ 
	int edges[MAXV][MAXV]; //邻接矩阵 
	int vexnum,edgnum;    //顶点数边数 
	VertexType vexs[MAXV];  //存放顶点信息 
}MGraph;     //图的邻接矩阵类型 

//邻接表类型定义
typedef int Vertex;   //邻接表结点类型定义

typedef struct ArcNode  //弧的结点结构类型 
{ 
	int adjvex;    //该弧的终点位置 
	int info;   //弧的权值 
	ArcNode *nextarc; //指向下一弧的指针 
}ArcNode;      

typedef struct   //邻接表头结点的类型 
{ 
	Vertex data;   //顶点信息 
	ArcNode *firstarc;  //指向第一条弧 
}AdjList[MAXV]; //AdjList是邻接表类型 

typedef struct
{ 
	AdjList adjlist;  //邻接表 
	int vexnum,arcnum;    //图中顶点数边数 
}ALGraph;     //图的邻接表类型 

void MatTOList(MGraph g,ALGraph *&G);  //图G的邻接矩阵转换成邻接表
void ListToMat(ALGraph *G,MGraph &g);  //图G的邻接表转换成邻接矩阵
void DispMat(MGraph g);   //输出邻接矩阵g
void DispAdj(ALGraph *G);  //输出邻接表G 
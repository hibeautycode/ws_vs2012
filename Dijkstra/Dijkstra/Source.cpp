#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 6  

//存放顶点的邻接表元素  
//存放最短路径的边元素  
typedef struct edge{  
	int vertex;  
	int value;  
	struct edge* next;  
}st_edge;  

void createGraph(st_edge** edge, int start, int end, int value);  
void displayGraph(st_edge** edge);  
void delGraph(st_edge** edge);  
void dijkstra(st_edge** edge, st_edge*** path, int** shortestPath, int startVertex, int* vertexStatusArr);  
void displayPath(st_edge** path, int startVertex,int* shortestPath);  
int getDistance(int value, int startVertex, int start, int* shortestPath);  
void createPath(st_edge **path, int startVertex, int start, int end, int edgeValue);  

int main(void){  
	//动态创建存放边的指针数组    
	st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
	int i;  
	for(i=0;i<VERTEXNUM;i++){  
		edge[i] = NULL;  
	}  
	//存放顶点的遍历状态，0：未遍历，1：已遍历  
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
	for(i=0;i<VERTEXNUM;i++){  
		vertexStatusArr[i] = 0;  
	}  

	printf("after init:\n");  
	displayGraph(edge);  
	//创建图  
	createGraph(edge,0,1,6);  
	createGraph(edge,0,3,5);  
	createGraph(edge,0,2,1);  
	createGraph(edge,1,2,5);  
	createGraph(edge,1,4,3);  
	createGraph(edge,2,4,6);  
	createGraph(edge,2,3,5);  
	createGraph(edge,2,5,4);  
	createGraph(edge,3,5,2);  
	createGraph(edge,4,5,6);  

	printf("after create:\n");  
	displayGraph(edge);  

	//最短路径  
	/*存储的结构如下： 
	path[0]:edge0->NULL 
	path[1]:edge1->NULL 
	path[2]:edge1->edge2->NULL 
	path[3]:edge1->edge2->edge3->NULL 
	path[4]:edge4->NULL 
	从顶点0到0的最短路径：从0出发直接到0 
	从顶点0到1的最短路径：从0出发直接到1 
	从顶点0到2的最短路径：从0出发到1，从1出发到2 
	...... 
	*/  
	st_edge** path = NULL;  
	//存储最短路径的权值  
	/* 
	shortestPath[0] = 0; 
	shortestPath[1] = 8; 
	shortestPath[2] = 12; 
	从顶点0到0的路径是0 
	从顶点0到1的路径是8 
	从顶点0到2的路径是12 
	*/  
	int* shortestPath = NULL;  
	int startVertex = 0;  
	//最短路径  
	dijkstra(edge, &path, &shortestPath, startVertex, vertexStatusArr);  
	printf("the path is:\n");  
	displayPath(path,startVertex,shortestPath);  

	delGraph(edge);  
	edge = NULL;  

	delGraph(path);   
	path = NULL;  

	if(vertexStatusArr != NULL){  
		free(vertexStatusArr);  
		vertexStatusArr = NULL;  
	}  

	if(shortestPath != NULL){  
		free(shortestPath);  
		shortestPath = NULL;  
	}  
	return 0;  
}  
//创建图  
void createGraph(st_edge** edge, int start, int end, int value){  
	st_edge* newedge1 = (st_edge*)malloc(sizeof(st_edge));  
	newedge1->vertex = end;  
	newedge1->value = value;  
	newedge1->next = NULL;  
	st_edge** edge1 = edge + start;  
	while(*edge1 != NULL){  
		edge1 = &((*edge1)->next);  
	}  
	*edge1 = newedge1;  

	st_edge* newedge2 = (st_edge*)malloc(sizeof(st_edge));  
	newedge2->vertex = start;  
	newedge2->value = value;  
	newedge2->next = NULL;  
	st_edge** edge2 = edge + end;  
	while(*edge2 != NULL){  
		edge2 = &((*edge2)->next);  
	}  
	*edge2 = newedge2;  
}  
//打印存储的图    
void displayGraph(st_edge** edge){  
	int i;  
	st_edge* p;  
	for(i=0;i<VERTEXNUM;i++){  
		printf("%d:",i);  
		p = *(edge+i);  
		while(p != NULL){  
			printf("%d(%d) ",p->vertex,p->value);  
			p = p->next;  
		}  
		printf("\n");  
	}  
}  
//打印最短路径  
void displayPath(st_edge** path, int startVertex,int* shortestPath){  
	int i;  
	st_edge* p;  
	for(i=0;i<VERTEXNUM;i++){  
		printf("Path from %d to %d:",startVertex,i);  
		p = *(path+i);  
		while(p != NULL){  
			printf("%d(%d) ",p->vertex,p->value);  
			p = p->next;  
		}  
		printf("\n");  
		printf("the count is:%d\n",shortestPath[i]);  
	}  
}  
//释放邻接表占用的内存  
void delGraph(st_edge** edge){  
	int i;  
	st_edge* p;  
	st_edge* del;  
	for(i=0;i<VERTEXNUM;i++){  
		p = *(edge+i);  
		while(p != NULL){  
			del = p;  
			p = p->next;  
			free(del);  
		}  
		edge[i] = NULL;  
	}  
	free(edge);  
}  
//dijkstra求最短路径  
void dijkstra(st_edge** edge, st_edge*** path, int** shortestPath, int startVertex, int* vertexStatusArr){  
	//初始化最短路径  
	*path = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
	int i,j;  
	for(i=0;i<VERTEXNUM;i++){  
		if(i == startVertex){  
			st_edge* e = (st_edge*)malloc(sizeof(st_edge));  
			e->vertex = startVertex;  
			e->value = 0;  
			e->next = NULL;  
			(*path)[i] = e;  
		}else{  
			(*path)[i] = NULL;  
		}  
	}  
	//初始化最短路径的权值  
	*shortestPath = (int *)malloc(sizeof(int)*VERTEXNUM);  
	for(i=0;i<VERTEXNUM;i++){  
		if(i == startVertex){  
			(*shortestPath)[i] = 0;  
		}else{  
			(*shortestPath)[i] = -1;  
		}  
	}  

	vertexStatusArr[startVertex] = 1;  

	st_edge* p;  
	int shortest, distance, edgeValue, start, end, vNum = 1;  
	//如果还顶点还没有访问完  
	while(vNum < VERTEXNUM){  
		shortest = 9999;  
		for(i=0;i<VERTEXNUM;i++){  
			//选择已经访问过的点  
			if(vertexStatusArr[i] == 1){  
				for(j=0;j<VERTEXNUM;j++){  
					//选择一个没有访问过的点   
					if(vertexStatusArr[j] == 0){  
						p = *(edge+i);  
						while(p != NULL){  
							//如果从startVertex到j的距离小于shortest  
							if((distance = getDistance(p->value, startVertex, i, *shortestPath)) < shortest && p->vertex == j){  
								shortest = distance;  
								edgeValue = p->value;  
								start = i;  
								end = j;  
							}  
							p = p->next;  
						}                         
					}  
				}  
			}  
		}  
		vNum++;  
		vertexStatusArr[end] = 1;  
		//保存最短路径的权值  
		(*shortestPath)[end] = shortest;  
		//保存最短路径  
		createPath(*path, startVertex, start, end, edgeValue);  
	}  
}  
//返回从startVertex到新的顶点的距离  
int getDistance(int value, int startVertex, int start, int* shortestPath){  
	if(start == startVertex){  
		return value;  
	}else{  
		return value + shortestPath[start];  
	}  
}  
//保存最短路径  
void createPath(st_edge **path, int startVertex, int start, int end, int edgeValue){  
	if(start == startVertex){  
		st_edge* newEdge = (st_edge*)malloc(sizeof(st_edge));  
		newEdge->vertex = end;  
		newEdge->value = edgeValue;  
		newEdge->next = NULL;  

		st_edge** p = path + end;  
		while((*p) != NULL){  
			p = &((*p)->next);  
		}  
		*p = newEdge;  
	}else{  
		st_edge** pCopySrc = path + start;  
		st_edge** pCopyDes = path + end;  
		st_edge* newEdge = NULL;  
		while((*pCopySrc) != NULL){  
			newEdge = (st_edge*)malloc(sizeof(st_edge));  
			*newEdge = **pCopySrc;  
			newEdge->next = NULL;  
			*pCopyDes = newEdge;  
			pCopySrc = &((*pCopySrc)->next);  
			pCopyDes = &((*pCopyDes)->next);  
		}  
		newEdge = (st_edge*)malloc(sizeof(st_edge));  
		newEdge->vertex = end;  
		newEdge->value = edgeValue;  
		newEdge->next = NULL;  
		*pCopyDes = newEdge;  
	}  
}  
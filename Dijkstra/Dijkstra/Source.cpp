#include <stdio.h>  
#include <malloc.h>  
#define VERTEXNUM 6  

//��Ŷ�����ڽӱ�Ԫ��  
//������·���ı�Ԫ��  
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
	//��̬������űߵ�ָ������    
	st_edge** edge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);  
	int i;  
	for(i=0;i<VERTEXNUM;i++){  
		edge[i] = NULL;  
	}  
	//��Ŷ���ı���״̬��0��δ������1���ѱ���  
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);  
	for(i=0;i<VERTEXNUM;i++){  
		vertexStatusArr[i] = 0;  
	}  

	printf("after init:\n");  
	displayGraph(edge);  
	//����ͼ  
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

	//���·��  
	/*�洢�Ľṹ���£� 
	path[0]:edge0->NULL 
	path[1]:edge1->NULL 
	path[2]:edge1->edge2->NULL 
	path[3]:edge1->edge2->edge3->NULL 
	path[4]:edge4->NULL 
	�Ӷ���0��0�����·������0����ֱ�ӵ�0 
	�Ӷ���0��1�����·������0����ֱ�ӵ�1 
	�Ӷ���0��2�����·������0������1����1������2 
	...... 
	*/  
	st_edge** path = NULL;  
	//�洢���·����Ȩֵ  
	/* 
	shortestPath[0] = 0; 
	shortestPath[1] = 8; 
	shortestPath[2] = 12; 
	�Ӷ���0��0��·����0 
	�Ӷ���0��1��·����8 
	�Ӷ���0��2��·����12 
	*/  
	int* shortestPath = NULL;  
	int startVertex = 0;  
	//���·��  
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
//����ͼ  
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
//��ӡ�洢��ͼ    
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
//��ӡ���·��  
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
//�ͷ��ڽӱ�ռ�õ��ڴ�  
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
//dijkstra�����·��  
void dijkstra(st_edge** edge, st_edge*** path, int** shortestPath, int startVertex, int* vertexStatusArr){  
	//��ʼ�����·��  
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
	//��ʼ�����·����Ȩֵ  
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
	//��������㻹û�з�����  
	while(vNum < VERTEXNUM){  
		shortest = 9999;  
		for(i=0;i<VERTEXNUM;i++){  
			//ѡ���Ѿ����ʹ��ĵ�  
			if(vertexStatusArr[i] == 1){  
				for(j=0;j<VERTEXNUM;j++){  
					//ѡ��һ��û�з��ʹ��ĵ�   
					if(vertexStatusArr[j] == 0){  
						p = *(edge+i);  
						while(p != NULL){  
							//�����startVertex��j�ľ���С��shortest  
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
		//�������·����Ȩֵ  
		(*shortestPath)[end] = shortest;  
		//�������·��  
		createPath(*path, startVertex, start, end, edgeValue);  
	}  
}  
//���ش�startVertex���µĶ���ľ���  
int getDistance(int value, int startVertex, int start, int* shortestPath){  
	if(start == startVertex){  
		return value;  
	}else{  
		return value + shortestPath[start];  
	}  
}  
//�������·��  
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
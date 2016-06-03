#include <stdlib.h>
#include <stdio.h>
#include "algraph.h"

void MatTOList(MGraph g,ALGraph *&G)//ͼG���ڽӾ���ת�����ڽӱ� 
{ 
	int i,j,n=g.vexnum;    //nΪ������ 
	ArcNode *p; 
	G=(ALGraph *)malloc(sizeof(ALGraph)); 
	for(i=0;i<n;i++)    //���ڽӱ�������ͷ����ָ���򸳳�ֵ 
		G->adjlist[i].firstarc=NULL; 
	for(i=0;i<n;i++)    //����ڽӾ�����ÿ��Ԫ�� 
		for(j=n-1;j>=0;j--) 
			if(g.edges[i][j]!=0) //�ڽӾ���ĵ�ǰԪ�ز�Ϊ0 
			{ 
				p=(ArcNode *)malloc(sizeof(ArcNode));//����һ�����p 
				p->adjvex=j; 
				p->info=g.edges[i][j];  //��űߵ�Ȩֵ 
				p->nextarc=G->adjlist[i].firstarc; //��*p���ӵ������ 
				G->adjlist[i].firstarc=p; 
			} 
			G->vexnum=n; 
			G->arcnum=g.arcnum; 
} 

void ListToMat(ALGraph *G,MGraph &g)  //ͼG���ڽӱ�ת�����ڽӾ��� 
{ 
	int i,j,n=G->vexnum; 
	ArcNode *p; 
	for(i=0;i<n;i++)    //g.edges[i][j]����ֵ0 
		for(j=0;j<n;j++) 
			g.edges[i][j]=0; 
	for(i=0;i<n;i++) 
	{ 
		p=G->adjlist[i].firstarc; 
		while(p!=NULL)   //���������ڶ�����д��� 
		{ 
			g.edges[i][p->adjvex]=p->info; 
			p=p->nextarc; 
		} 
	} 
	g.vexnum = n; 
	g.arcnum = G->arcnum; 
} 

void DispMat(MGraph g)   //����ڽӾ���g 
{ 
	int i,j; 
	for(i=0;i<g.vexnum;i++) 
	{ 
		for(j=0;j<g.vexnum;j++) 
			if(g.edges[i][j]==INF) 
				printf( "��" ); 
			else 
				printf( "%d ",g.edges[i][j] ); 
		printf( "\n" ); 
	} 
} 

void DispAdj(ALGraph *G)  //����ڽӱ�G 
{ 
	int i; 
	ArcNode *p; 
	for(i=0;i<G->vexnum;i++) 
	{ 
		p=G->adjlist[i].firstarc; 
		if(p!=NULL) 
			printf( "%d: ", i ); 
		while(p!=NULL)    //���������ڶ�����д��� 
		{ 
			printf( "%d ", p->adjvex ); 
			p=p->nextarc; 
		} 
		printf( "\n" ); 
	} 
}  
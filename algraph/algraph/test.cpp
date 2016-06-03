#include <stdlib.h>
#include <stdio.h>
#include "algraph.h"

void main() 
{ 
	int i,j; 
	MGraph g,g1; 
	ALGraph *G; 

	int A[MAXV][6]={ 
		{0,5,0,7,0,0}, 
		{0,0,4,0,0,0}, 
		{8,0,0,0,0,9}, 
		{0,0,5,0,0,6}, 
		{0,0,0,5,0,0}, 
		{3,0,0,0,1,0}}; 

	g.vexnum=6; 
	g.edgnum=10; 

	for( i = 0; i < g.vexnum; i++ ) 
		for( j = 0; j < g.vexnum; j++ ) 
			g.edges[i][j] = A[i][j]; 

	printf( "\n" ); 
	printf( "����ͼG���ڽӾ���\n" ); 
	DispMat(g); 

	//G=(ALGraph *)malloc(sizeof(ALGraph)); 

	printf( "ͼG���ڽӾ���ת�����ڽӱ�\n" ); 
	MatTOList(g,G); 
	DispAdj(G); 

	printf( "ͼG���ڽӱ�ת�����ڽӾ���\n" ); 
	ListToMat(G,g1); 
	DispMat(g1); 

	getchar();
}
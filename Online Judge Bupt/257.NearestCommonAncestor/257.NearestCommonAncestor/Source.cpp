#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int id;
	int layer;
	struct node * father;
	struct node * nextBrother;
	struct node * firstChild;
}node;

typedef node * pNode;

void insert( pNode pRoot, int u, int v )
{
	if( pRoot != NULL )
	{
		if( pRoot->id == u )
		{
			pNode pTmpNode = ( pNode )malloc( sizeof( struct node ) );
			pTmpNode->id = v;
			pTmpNode->father = pRoot;
			pTmpNode->layer = pRoot->layer + 1;
			pTmpNode->firstChild = pTmpNode->nextBrother = NULL;

			if( pRoot->firstChild == NULL )
			{
				pRoot->firstChild = pTmpNode;
				return;
			}
			else
			{
				pNode pTmpNode2 = pRoot->firstChild;
				while( pTmpNode2->nextBrother != NULL )
					pTmpNode2 = pTmpNode2->nextBrother;
				pTmpNode2->nextBrother = pTmpNode;
				return;
			}
		}
		insert( pRoot->nextBrother, u, v );
		insert( pRoot->firstChild, u, v );
		return;
	}
}
void searchNodeById( pNode pRoot, int id, pNode * result )
{
	if( pRoot != NULL )
	{
		if( pRoot->id == id )
		{
			*result = pRoot;
		}
		searchNodeById( pRoot->nextBrother, id, result );
		searchNodeById( pRoot->firstChild, id, result );
	}
}
int searchCommonAncestor2( pNode pNode1, pNode pNode2 )
{
	if( pNode1->layer ==pNode2->layer )
	{
		if( pNode1->id == pNode2->id )
			return pNode1->id;
		searchCommonAncestor2( pNode1->father, pNode2->father );
	}
	else if( pNode1->layer < pNode2->layer )
		searchCommonAncestor2( pNode1, pNode2->father );
	else
		searchCommonAncestor2( pNode1->father, pNode2 );
}
int searchCommonAncestor( pNode pRoot, int u, int v )
{
	pNode pNode1, pNode2;
	pNode1 = pNode2 = NULL;
	searchNodeById( pRoot, u, &pNode1 );
	searchNodeById( pRoot, v, &pNode2 );
	return searchCommonAncestor2( pNode1, pNode2 );
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		node root;
		root.id = 1;
		root.layer = 1;
		root.nextBrother = NULL;
		root.father = NULL;
		root.firstChild = NULL;
		int N, u, v;
		scanf( "%d", &N );
		int n = N - 1;
		for( int i = 0; i < n; i++ )
		{			
			scanf( "%d %d", &u, &v );
			insert( &root, u, v );
		}
		int M;
		scanf( "%d", &M );
		while( M-- )
		{
			scanf( "%d %d", &u, &v );
			printf( "%d\n", searchCommonAncestor( &root, u, v ) );
		}
	}
	return 0;
}
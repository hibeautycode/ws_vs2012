#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;

typedef struct Node
{
	int id;
	struct Node *leftChild;
	struct Node *rightChild;
}Node;

typedef struct Node *BiTree;

void printByLevel( BiTree root )
{
	queue< BiTree > q;
	q.push( root );
	BiTree pNode, newLevel = q.back();
	while( ! q.empty() )
	{
		pNode = q.front();
		printf( "%d", pNode->id );
		q.pop();	
		if( pNode->leftChild != NULL )
			q.push( pNode->leftChild );
		if( pNode->rightChild != NULL )
			q.push( pNode->rightChild );
		if( pNode == newLevel )
		{
			printf( "\n" );
			if( ! q.empty() )
				newLevel = q.back();
		}
		else
		{
			printf( " " );
		}
	}
}
BiTree searchByLevel( BiTree root, int id )
{
	queue< BiTree > q;
	q.push( root );
	BiTree pNode;
	while( ! q.empty() )
	{
		pNode = q.front();

		if( pNode->id == id )
			return pNode;

		q.pop();	
		if( pNode->leftChild != NULL )
			q.push( pNode->leftChild );
		if( pNode->rightChild != NULL )
			q.push( pNode->rightChild );
	}
}
void insert( BiTree *pRoot, int id1, int id2 )
{
	if( *pRoot == NULL )
	{
		*pRoot = ( BiTree )malloc( sizeof( struct Node ) );
		( *pRoot )->id = id2;
		( *pRoot )->leftChild = ( BiTree )malloc( sizeof( struct Node ) );
		( *pRoot )->leftChild->id = id1;
		( *pRoot )->rightChild = ( *pRoot )->leftChild->leftChild = ( *pRoot )->leftChild->rightChild = NULL;
		return;
	}
	BiTree pNode = searchByLevel( *pRoot, id2 );
	if( pNode->leftChild  == NULL )
	{
		pNode->leftChild = ( BiTree )malloc( sizeof( struct Node ) );
		pNode = pNode->leftChild;
		pNode->id = id1;
		pNode->leftChild = pNode->rightChild = NULL;
	}
	else if( pNode->rightChild  == NULL )
	{
		pNode->rightChild = ( BiTree )malloc( sizeof( struct Node ) );
		pNode = pNode->rightChild;
		pNode->id = id1;
		pNode->leftChild = pNode->rightChild = NULL;
	}
}
int main()
{
	int T;
	scanf( "%d", &T );
	for( int i = 0; i < T; i++ )
	{
		BiTree root = NULL;
		int N, M;
		scanf( "%d %d", &N, &M );
		while( N-- )
		{
			int id1, id2;
			scanf( "%d %d", &id1, &id2 );
			insert( &root, id1, id2 );
		}
		printf( "Q%d:\n", i + 1 );
		printByLevel( root );
	}
	return 0;
}
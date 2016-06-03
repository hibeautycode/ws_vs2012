#include<stdio.h>
#include<malloc.h>
typedef long long elemType;

typedef struct Node
{
	elemType id;
	struct Node * leftChild;
	struct Node * rightChild;
	struct Node * father;
}Node;

typedef Node* sBiTree;

void insert( sBiTree* pRoot, sBiTree* pFatherNode,elemType newId )
{
	if( *pRoot == NULL )
	{
		*pRoot = ( sBiTree )malloc( sizeof( struct Node ) );
		( *pRoot )->id = newId;
		( *pRoot )->leftChild = ( *pRoot )->rightChild = NULL;
		( *pRoot )->father = *pFatherNode;
		if( ( *pRoot )->father )
			printf( "%lld\n", ( *pRoot )->father->id );
		else
			printf( "-1\n" );
		return;
	}
	if( ( *pRoot )->id > newId )
		insert( &( *pRoot )->leftChild, pRoot, newId );
	else if( ( *pRoot )->id < newId )
		insert( &( *pRoot )->rightChild, pRoot, newId );
}
int main()
{
	int N;
	scanf( "%d", &N );
	sBiTree root = NULL, fatherNode = NULL;
	while( N-- )
	{
		elemType input;
		scanf( "%lld", &input );
		insert( &root, &fatherNode, input );
	}
	return 0;
}
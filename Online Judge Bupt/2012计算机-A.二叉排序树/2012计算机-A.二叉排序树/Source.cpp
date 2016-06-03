#include<stdio.h>
#include<malloc.h>
typedef int elemtype;

struct Node
{
	elemtype key;
	Node * left;
	Node * right;
};
typedef Node * pNode;
void insert( pNode * ppRoot, elemtype key )
{
	if( *ppRoot == NULL )
	{
		*ppRoot = ( Node * )malloc( sizeof( Node ) );
		( *ppRoot )->key = key;
		( *ppRoot )->left = ( *ppRoot )->right = NULL;
		return;
	}
	else
	{
		if( ( *ppRoot )->key > key )
		{
			if( ( *ppRoot )->left == NULL )
			{
				Node * pTmpNode = ( Node * )malloc( sizeof( Node ) );
				pTmpNode->key = key;
				pTmpNode->left = pTmpNode->right = NULL;
				( *ppRoot )->left = pTmpNode;
				return;
			}
			insert( &( *ppRoot )->left , key );
		}
		else if( ( *ppRoot )->key < key )
		{
			if( ( *ppRoot )->right == NULL )
			{
				Node * pTmpNode = ( Node * )malloc( sizeof( Node ) );
				pTmpNode->key = key;
				pTmpNode->left = pTmpNode->right = NULL;
				( *ppRoot )->right = pTmpNode;
				return;
			}
			insert( &( *ppRoot )->right , key );
		}
	}
}
elemtype searchFather( Node * pRoot, elemtype key )
{
	if( pRoot->key > key )
	{
		if( pRoot->left->key == key )
			return pRoot->key;
		else
			return searchFather( pRoot->left, key );
	}
	else if( pRoot->key < key )
	{
		if( pRoot->right->key == key )
			return pRoot->key;
		else
			return searchFather( pRoot->right, key );
	}
}
int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- )
	{
		int N;
		scanf( "%d", &N );
		pNode pRoot = NULL;
		while( N-- )
		{
			int input;
			scanf( "%d", &input );
			insert( &pRoot, input );
			if( pRoot->key == input )
			{
				printf( "-1\n" );
			}
			else
			{
				printf( "%d\n", searchFather( pRoot, input ) );
			}
		}
	}
	return 0;
}
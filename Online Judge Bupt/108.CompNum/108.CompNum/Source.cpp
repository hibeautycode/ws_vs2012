#include<stdio.h>
#include<string.h> 
#include<malloc.h>

typedef struct CompNum
{
	int real;
	int image;
	int length;
	struct CompNum * next;
}CompNum;
typedef struct CompNum * pCompNum;
typedef struct Set
{
	int size;
	pCompNum head;
}Set;
void insert( Set * pSet, struct CompNum compNum )
{
	if( pSet->size == 0 )	//set为空 创建链头
	{
		pSet->head = ( pCompNum )malloc( sizeof( struct CompNum ) );
		pSet->head->real = compNum.real;
		pSet->head->image = compNum.image;
		pSet->head->length = compNum.length;
		pSet->head->next = NULL;
		pSet->size++;
		printf( "Size:%d\n", pSet->size );
		return;
	}
	pCompNum pTmpCompNum, pMemCompNum; 
	pTmpCompNum = pSet->head;
	while( pTmpCompNum != NULL )
	{
		if( pTmpCompNum->length < compNum.length )
		{
			pMemCompNum = ( pCompNum )malloc( sizeof( struct CompNum ) );
			pMemCompNum->real = pTmpCompNum->real;
			pMemCompNum->image = pTmpCompNum->image;
			pMemCompNum->length = pTmpCompNum->length;
			pMemCompNum->next = pTmpCompNum->next;
			pTmpCompNum->real = compNum.real;
			pTmpCompNum->image = compNum.image;
			pTmpCompNum->length = compNum.length;
			pTmpCompNum->next = pMemCompNum;
			pSet->size++;
			printf( "Size:%d\n", pSet->size );
			return;
		}
		pTmpCompNum = pTmpCompNum->next;
	}
	pTmpCompNum = ( pCompNum )malloc( sizeof( struct CompNum ) ); //插在链尾
	pTmpCompNum->real = compNum.real;
	pTmpCompNum->image = compNum.image;
	pTmpCompNum->length = compNum.length;
	pTmpCompNum->next = NULL;
	printf( "Size:%d\n", pSet->size );
	return;
}
void pop( Set * pSet )
{
	if( pSet->size == 0 )
	{
		printf( "Empty!\n" );
		return;
	}
	pCompNum pTmpCompNum = pSet->head;
	printf( "%d+i%d\n", pTmpCompNum->real, pTmpCompNum->image );
	pSet->head = pTmpCompNum->next;
	pSet->size--;
	free( pTmpCompNum );
	if( pSet->size == 0 )
		printf( "Empty!\n" );
	else
		printf( "Size:%d\n", pSet->size );
	return;
}
int main()
{
	int T;
	scanf( "%T", &T );
	while( T-- )
	{
		int N, real, image;
		char command[ 10 ];
		struct CompNum compNum;
		Set numSet;
		numSet.head = NULL;
		numSet.size = 0;
		scanf( "%d", &N );
		while( N-- )
		{
			scanf( "%s", command );
			if( strcmp( command, "Insert" ) == 0 )
			{
				scanf( "%d+i%d", &real, &image );
				compNum.real = real;
				compNum.image = image;
				compNum.length = real * real + image * image;
				compNum.next = NULL;
				insert( &numSet, compNum );
			}
			else if( strcmp( command, "Pop" ) == 0 )
			{
				pop( &numSet );
			}
		}
	}
	return 0;
}
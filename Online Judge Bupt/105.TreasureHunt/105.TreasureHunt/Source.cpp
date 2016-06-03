#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int fatherId;
	int childNum;
}node;
int main()
{
	int N, M, L;
	scanf( "%d %d %d", &N, &M, &L );
	node *pTree;
	pTree = ( struct node * )malloc( sizeof( struct node ) * N );
	for( int i = 0; i < N; i++ )
	{
		pTree[ i ].childNum = 0;
		pTree[ i ].fatherId = -1;
	}
	while( M-- )
	{
		int id1, id2;
		scanf( "%d %d", &id1, &id2 );
		pTree[ id1 ].childNum ++;
		pTree[ id2 ].fatherId = id1;
	}
	int base = 1, tmp = L;
	while( tmp != 0 )
	{
		base *= pTree[ pTree[ tmp ].fatherId ].childNum;
		tmp = pTree[ tmp ].fatherId;
	}
	printf( "%.6lf", (double)1 / base );
	return 0;
}
/*#include <stdio.h>  
#include <string.h>  
#include <iostream>  
using namespace std;  

int t[1000][1000];  
int du[1000];  

int main() {  
int n, m, f, c, i, j, count;  
cin >> n;  
while (n--) {  
cin >> m;  
memset(t, 0, sizeof(t));  
memset(du, 0, sizeof(du));  

for (i = 0; i < m - 1; i++) {  
cin >> f >> c;  
t[f][c] = 1;  
t[c][f] = 1;  
du[f]++;  
du[c]++;  
}  

count = m;  
for (i = 0; i < m; i++) {  
int d = du[i];  
if (d == 0) {  
count--;  
continue;  
}  
for (j = 0; j < m; j++) {  
if (t[i][j]) {  
if(du[j] > d) {  
count--;  
break;  
}  
}  
}  
}  
cout << count << endl;  
}  

return 0;  
}  */

#include<stdio.h>
#include<malloc.h>

typedef struct treeNode
{
	int degree;
	struct treeNode *fatherNode;
	struct treeNode *firstChild;
	struct treeNode *brotherNode;
}treeNode;

void judgePNode2( struct treeNode * pTreeNode, int degree, int * pFlag )
{
	if( pTreeNode != NULL )
	{
		if( pTreeNode->degree > degree )
		{
			*pFlag = 0;
			return;
		}
		judgePNode2( pTreeNode->firstChild, degree, pFlag );
		judgePNode2( pTreeNode->brotherNode, degree, pFlag );
	}
}
void judgePNode( struct treeNode TreeNode, int * pFlag )
{
	if( TreeNode.fatherNode != NULL && ( TreeNode.fatherNode->degree > TreeNode.degree ) )
	{
		*pFlag = 0;
		return;
	}
	judgePNode2( TreeNode.firstChild, TreeNode.degree, pFlag );
}

int main()
{
	int T, N, nodeId1, nodeId2, i, nodePNum = 0;
	struct treeNode *pTempNode;

	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &N );
		int n = N - 1;

		struct treeNode * pNodeArray = ( struct treeNode* )malloc( sizeof( struct treeNode ) * N );

		for( i = 0; i < N; i++ )
		{
			pNodeArray[i].degree = 0;
			pNodeArray[i].fatherNode = NULL;
			pNodeArray[i].firstChild = NULL;
			pNodeArray[i].brotherNode = NULL;
		}
		while( n-- )
		{
			scanf( "%d %d", &nodeId1, &nodeId2 );
			pNodeArray[ nodeId1 ].degree++;
			if( pNodeArray[ nodeId1 ].firstChild == NULL )
			{
				pNodeArray[ nodeId1 ].firstChild = &pNodeArray[ nodeId2 ];
			}
			else
			{
				pTempNode = pNodeArray[ nodeId1 ].firstChild;
				while( pTempNode->brotherNode != NULL)
				{
					pTempNode = pTempNode->brotherNode;
				}
				pTempNode->brotherNode = &pNodeArray[ nodeId2 ];
			}
			pNodeArray[ nodeId2 ].degree++;
			pNodeArray[ nodeId2 ].fatherNode = &pNodeArray[ nodeId1 ];
		}
		
		for( i = 0; i < N; i++ )
		{
			int flag = 1;
			judgePNode( pNodeArray[i], &flag );
			if( flag )
				nodePNum++;
		}

		printf( "%d\n", nodePNum );
		nodePNum = 0;
		free( pNodeArray );
	}

	return 0;
}

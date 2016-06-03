#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX_SIZE 100

typedef struct fileNode
{
	char fileName[MAX_SIZE];
	struct fileNode* nextFile;
}fileNode;

typedef struct dirNode
{
	char dirName[MAX_SIZE];
	struct dirNode* childDir;
	struct dirNode* brotherDir;
	struct fileNode* firstFile;
}dirNode;

typedef struct dirNode* pDirNode;

void searchDir( struct dirNode* pRoot, char dirName[] , pDirNode * ppDirNode)
{
	if( strcmp( pRoot->dirName, dirName ) == 0 )
	{
		*ppDirNode = pRoot;
		return;
	}
	if( pRoot->brotherDir )
		searchDir( pRoot->brotherDir, dirName, ppDirNode );
	if( pRoot->childDir )
		searchDir( pRoot->childDir, dirName, ppDirNode );
}

void createFile( dirNode *pRoot, char dirName[], char fileName[] )
{
	struct dirNode *pTempDir;
	struct fileNode *pTempFile;

	searchDir( pRoot, dirName, &pTempDir );

	if( ! pTempDir->firstFile )
	{
		pTempFile = ( fileNode* )malloc( sizeof(fileNode) );
		strcpy( pTempFile->fileName, fileName );
		pTempFile->nextFile = NULL;
		pTempDir->firstFile = pTempFile;
	}
	else
	{
		pTempFile = pTempDir->firstFile;
		while( pTempFile->nextFile )
			pTempFile = pTempFile->nextFile;
		pTempFile->nextFile = ( fileNode* )malloc( sizeof( fileNode ) );
		pTempFile = pTempFile->nextFile;
		strcpy( pTempFile->fileName, fileName );
		pTempFile->nextFile = NULL;
	}
}

void createDir( dirNode *pRoot, char dirName1[], char dirName2[] )
{
	struct dirNode *pTempDir;

	searchDir( pRoot, dirName2, &pTempDir );

	if( pTempDir->childDir == NULL )
	{
		pTempDir->childDir = ( dirNode* )malloc( sizeof( dirNode ) );
		pTempDir = pTempDir->childDir;
		strcpy( pTempDir->dirName, dirName1 );
		pTempDir->brotherDir = NULL;
		pTempDir->childDir = NULL;
		pTempDir->firstFile = NULL;
	}
	else
	{
		pTempDir = pTempDir->childDir;
		while( pTempDir->brotherDir )
			pTempDir = pTempDir->brotherDir;
		pTempDir->brotherDir = ( dirNode* )malloc( sizeof( dirNode ) );
		pTempDir = pTempDir->brotherDir;
		strcpy( pTempDir->dirName, dirName1 );
		pTempDir->brotherDir = NULL;
		pTempDir->childDir = NULL;
		pTempDir->firstFile = NULL;
	}
}

void listFile( dirNode *pRoot, char dirName[] )
{
	struct dirNode *pTempDir;
	struct fileNode *pTempFile;

	searchDir( pRoot, dirName, &pTempDir );
	
	pTempFile = pTempDir->firstFile;
	while( pTempFile )
	{
		printf( "%s\n", pTempFile->fileName );
		pTempFile = pTempFile->nextFile;
	}
}
void listDir( dirNode *pRoot, char dirName[] )
{
	struct dirNode *pTempDir;

	searchDir( pRoot, dirName, &pTempDir );
	
	pTempDir = pTempDir->childDir;
	while( pTempDir )
	{
		printf( "%s\n", pTempDir->dirName );
		pTempDir = pTempDir->brotherDir;
	}
}

int main()
{
	int T = 0, N = 0;
	char command[MAX_SIZE], dirName1[MAX_SIZE], dirName2[MAX_SIZE], fileName[MAX_SIZE];
	struct dirNode root;
	strcpy( root.dirName, "root" );	

	scanf( "%d", &T );
	while( T-- )
	{
		root.firstFile = NULL;
		root.childDir = NULL;
		root.brotherDir = NULL;
		scanf( "%d", &N );
		while( N-- )
		{
			scanf( "%s", command );
			if( 0 == strcmp( command, "CREATEFILE" ) )
			{
				scanf( "%s", fileName );
				scanf( "%s", dirName1 );
				createFile( &root, dirName1, fileName );
			}
			else if( 0 == strcmp( command, "CREATEDIR" ) )
			{
				scanf( "%s", dirName1 );
				scanf( "%s", dirName2 );
				createDir( &root, dirName1, dirName2 );
			}
			else if( 0 == strcmp( command, "LISTFILE" ) )
			{
				scanf( "%s", dirName1 );
				listFile( &root, dirName1 );

			}
			else if( 0 == strcmp( command, "LISTDIR" ) )			
			{
				scanf( "%s", dirName1 );
				listDir( &root, dirName1 );
			}
		}
	}

	return 0;
}
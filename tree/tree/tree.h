        
		typedef int ElementType;

/* START: fig4_16.txt */
        #ifndef _Tree_H
        #define _Tree_H

        struct TreeNode;
        typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;

        SearchTree MakeEmpty( SearchTree T );
        Position Find( ElementType X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( ElementType X, SearchTree T );
        SearchTree Delete( ElementType X, SearchTree T );
        ElementType Retrieve( Position P );
		void InOrder( SearchTree T );
		void LevelOrder( SearchTree T );

        #endif  /* _Tree_H */

/* END */

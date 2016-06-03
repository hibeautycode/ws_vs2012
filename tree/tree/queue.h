#include "tree.h"
typedef SearchTree QElementType;
/* START: fig3_57.txt */
        #ifndef _Queue_h
        #define _Queue_h

        struct QueueRecord;
        typedef struct QueueRecord *Queue;

        int IsEmpty( Queue Q );
        int IsFull( Queue Q );
		int QRear( Queue Q );
		int QFront( Queue Q );
        Queue CreateQueue( int MaxElements );
        void DisposeQueue( Queue Q );
        void MakeEmpty( Queue Q );
        void Enqueue( QElementType X, Queue Q );
        QElementType Front( Queue Q );
        void Dequeue( Queue Q );
        QElementType FrontAndDequeue( Queue Q );

        #endif  /* _Queue_h */
/* END */

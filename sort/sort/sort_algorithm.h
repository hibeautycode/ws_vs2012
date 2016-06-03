#include <stdlib.h>
#include "fatal.h"

typedef int ElementType;

void Swap( ElementType *Lhs, ElementType *Rhs );

// for check sort algorithm
void Copy( ElementType Lhs[], const ElementType Rhs[], int n );
void Permute( ElementType A[], int n );
void Checksort( ElementType A[], int n );

// collection of sort algorithm
void RadixSort( ElementType A[] , int n );
void InsertSort( ElementType A[], int n );
void BinaryInsertSort( ElementType A[], int n );
void ShellSort( ElementType A[], int n );
void HeapSort( ElementType A[], int n );
void MergeSort( ElementType A[], int n );
void QuickSort( ElementType A[], int n );
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType data;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapInit(HP* php);
void HeapInit(HP* php);

void AdjustDown(HPDataType* a, int n, int parent);
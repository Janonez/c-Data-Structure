#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;// ����
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);


void AdjustDown(HPDataType* a, int n, int parent);
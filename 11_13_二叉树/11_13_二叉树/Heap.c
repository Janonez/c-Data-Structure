#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->data = NULL;
	php->capacity = php->size = 0;
}
void HeapDestroy(HP* php)
{
}

void AdjustDown(HPDataType* a, int n, int parent)
{

	int child = parent * 2 + 1;
	while ()
	{
		if (a[child + 1] > a[child])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			Swap();

		}
	}
}
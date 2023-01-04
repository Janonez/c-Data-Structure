#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->capacity = php->size = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0 )
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
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
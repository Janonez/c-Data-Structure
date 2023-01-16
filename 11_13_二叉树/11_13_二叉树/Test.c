#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void TestHeap1()
{
	HP hp;
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

void TestHeap2()
{
	HP hp;
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		HeapPush(&hp, array[i]);
	}


	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

void TestHeap3()
{
	HP hp;
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapCreate(&hp, array, sizeof(array) / sizeof(int));
	
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

int main()
{
	//TestHeap1();
	//TestHeap2();
	TestHeap3();
	return 0;
}
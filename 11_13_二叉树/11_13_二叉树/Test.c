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

void HeapSort(int* a,int n)
{
	// 向上调整建堆，必须保证上面是堆，从上往下开始调整
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/

	// 向下调整建堆，必须保证下面是堆，从下往上开始调整
	for (int i = (n-1-1)/2; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestHeap4()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(array, sizeof(array) / sizeof(int));
}

void TestHeap5()
{
	int k = 5;
	int minHeap[5];

	FILE* fout = fopen("Data1.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	// 先建一个前k个数的堆
	// 读取数据到数组中
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	// 调整为小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}

	// 遍历数据与堆顶比较
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}
	int end = k - 1;
	while (end > 0)
	{
		Swap(&minHeap[0], &minHeap[end]);
		AdjustDown(minHeap, end, 0);
		end--;
	}
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
	fclose(fout);
}

void TestHeap6()
{
	int n, k;
	printf("请输入n和k：");
	scanf("%d %d", &n, &k);
	// 造数据

	srand((unsigned int)time(NULL));
	FILE* fin = fopen("Data2.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int val = rand() % 100000;
		fprintf(fin, "%d\n", val);
		/*while(val % 23 == 0 && k>0)
		{
			fprintf(fin, "%d\n", n+i);
			k--;
		}*/
	}
	fclose(fin);

	FILE* fout = fopen("Data2.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	int* minHeap = (int*)malloc(sizeof(int) * n);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}

	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	int end = k - 1;
	while (end > 0)
	{
		Swap(&minHeap[0], &minHeap[end]);
		AdjustDown(minHeap, end, 0);
		end--;
	}
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", minHeap[i]);
	}

	
	printf("\n");

	fclose(fout);
}

int main()
{
	//TestHeap1();
	//TestHeap2();
	//TestHeap3();
	//TestHeap4();
	TestHeap5();
	//TestHeap6();
	return 0;
}
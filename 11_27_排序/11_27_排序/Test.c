#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void TestInsertSort()
{
	int a[] = {9,1,2,5,7,4,8,6,3};
	InsertSort(a, sizeof(a) / sizeof(int));
	for (size_t i = 0;i < (sizeof(a) / sizeof(int));i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
}
int main()
{
	TestInsertSort();
	return 0;
}
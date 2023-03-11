#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//---------------------------------------插入排序--------------------------------------------------------
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
//---------------------------------------希尔排序--------------------------------------------------------
void ShellSort(int* a, int n)
{
	// gap > 1  预排序
	// gap == 1 插入排序
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);

	}
	/*int gap = 3;
	for (int j = 0; j < gap; j++)
	{
		for (int i = j; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}*/
}
//---------------------------------------堆排序--------------------------------------------------------
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 确认child指向大的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// 1、孩子大于父亲，交换，继续向下调整
		// 2、孩子小于父亲，则调整结束
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// O(N*logN)
void HeapSort(int* a, int n)
{
	// 向下调整建堆 -- O(N)
	// 升序：建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// O（N*logN）
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//---------------------------------------选择排序--------------------------------------------------------
// O(N^2)
// 跟插入排序相比，插入排序更好
// 插入排序适应性很强，对于有序，部分有序，都能提升效率
// 但是选择排序在任何情况下都是O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}

//---------------------------------冒泡排序---------------------------------------------------
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}	
}

//--------------------------------快速排序----------------------------------------------------
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		// 右边先走，找比keyi小的（如果大于就继续向前寻找）
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边再走，找比keyi大的（如果小于就继续向后寻找）
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[right]);
	keyi = left;// 左右节点都可以，因为左右相遇都相等

	// 递归，将数组分为三部分 ==> [begin, keyi-1]  keyi [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
#include "Stack.h"

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
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] > a[mid])
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
}

// Hoare
int PartSort1(int* a,int begin,int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

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

	return keyi;
}

// 挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// 右边先走，找比key小的（如果大于就继续向前寻找）
		while (left < right && a[right] >= key)
		{
			--right;
		}
		// 如果找到了，就把right的数放在hole里面,right成为新的hole
		a[hole] = a[right];
		hole = right;
		// 左边再走，找比key大的（如果小于就继续向后寻找）
		while (left < right && a[left] <= key)
		{
			++left;
		}
		// 如果找到了，就把left的数放在hole里面,left成为新的hole
		a[hole] = a[left];
		hole = left;
		
	}	
	// 如果相遇，把key的数放到hole里面
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int begin, int end)
{
	int prev = begin, cur = begin + 1;
	int key = begin;
	
	while (cur <= end)
	{

		if(a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}

	Swap(&a[key], &a[prev]);
	key = prev;
	return key;
	//while (cur < end)
	//{
	//	
	//	while(cur < end && a[cur] >= a[key])
	//	{
	//		cur++;
	//	}
	//	Swap(&a[cur++], &a[++prev]);
	//}
	//Swap(&a[key], &a[prev]);


}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	// 小区间优化
	// 小区间用直接插入替代，减少递归调用次数
	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		//int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		int keyi = PartSort3(a, begin, end);

		// 递归，将数组分为三部分 ==> [begin, keyi-1]  keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	
}

// 非递归快排
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1, right]
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi+1);
			StackPush(&st, right);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

	}
	StackDestroy(&st);
}

// -------------------------------------归并排序-----------------------------------------
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	// [begin, mid] [mid+1, end] 递归让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	int i = begin;
	// 两个有序数组归并，有一个结束，就都结束了
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//上面的条件不满足时，说明有一个数组已经排列结束，要将剩余一个中的数据排序放到tmp
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	// 拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}
// 非递归归并
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	// 归并每组数据个数，从1开始，因为1个认为是有序的，可以直接归并
//	int rangeN = 1;
//	while (rangeN < n)
//	{
//		for (int i = 0; i < n; i += 2 * rangeN)
//		{
//			// [begin1,end1][begin2,end2] 归并
//			int begin1 = i, end1 = i + rangeN - 1;
//			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
//			int j = i;
//
//			// 判断越界情况
//			if (end1 >= n)//end1 越界
//			{
//				break;
//			}
//			else if (begin2 >= n)//begin2 越界
//			{
//				break;
//			}
//			else if (end2 >= n)//end2 越界
//			{
//				end2 = n - 1;
//			}
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//			// 归并一部分，拷贝一部分
//			memcpy(a, tmp, sizeof(int) * (end2 - i + 1));
//		}
//		rangeN *= 2;
//	}
//	
//
//	free(tmp);
//	tmp = NULL;
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	// 归并每组数据个数，从1开始，因为1个认为是有序的，可以直接归并
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			// [begin1,end1][begin2,end2] 归并
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			int j = i;

			// 判断越界情况
			if (end1 >= n)//end1 越界
			{
				end1 = n - 1;
				// 把后一段创建为一个不存在的序列
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)//begin2 越界
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)//end2 越界
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			
		}
		// 整体归并
		memcpy(a, tmp, sizeof(int) * n);
		rangeN *= 2;
	}


	free(tmp);
	tmp = NULL;
}
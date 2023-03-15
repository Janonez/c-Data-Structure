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
//---------------------------------------��������--------------------------------------------------------
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
//---------------------------------------ϣ������--------------------------------------------------------
void ShellSort(int* a, int n)
{
	// gap > 1  Ԥ����
	// gap == 1 ��������
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
//---------------------------------------������--------------------------------------------------------
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
		// ȷ��childָ�����Ǹ�����
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// 1�����Ӵ��ڸ��ף��������������µ���
		// 2������С�ڸ��ף����������
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
	// ���µ������� -- O(N)
	// ���򣺽����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// O��N*logN��
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//---------------------------------------ѡ������--------------------------------------------------------
// O(N^2)
// ������������ȣ������������
// ����������Ӧ�Ժ�ǿ���������򣬲������򣬶�������Ч��
// ����ѡ���������κ�����¶���O(N^2)
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

//---------------------------------ð������---------------------------------------------------
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

//--------------------------------��������----------------------------------------------------
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
		// �ұ����ߣ��ұ�keyiС�ģ�������ھͼ�����ǰѰ�ң�
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// ������ߣ��ұ�keyi��ģ����С�ھͼ������Ѱ�ң�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[right]);
	keyi = left;// ���ҽڵ㶼���ԣ���Ϊ�������������

	return keyi;
}

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// �ұ����ߣ��ұ�keyС�ģ�������ھͼ�����ǰѰ�ң�
		while (left < right && a[right] >= key)
		{
			--right;
		}
		// ����ҵ��ˣ��Ͱ�right��������hole����,right��Ϊ�µ�hole
		a[hole] = a[right];
		hole = right;
		// ������ߣ��ұ�key��ģ����С�ھͼ������Ѱ�ң�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		// ����ҵ��ˣ��Ͱ�left��������hole����,left��Ϊ�µ�hole
		a[hole] = a[left];
		hole = left;
		
	}	
	// �����������key�����ŵ�hole����
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

	// С�����Ż�
	// С������ֱ�Ӳ�����������ٵݹ���ô���
	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		//int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		int keyi = PartSort3(a, begin, end);

		// �ݹ飬�������Ϊ������ ==> [begin, keyi-1]  keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	
}

// �ǵݹ����
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

// -------------------------------------�鲢����-----------------------------------------
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	// [begin, mid] [mid+1, end] �ݹ�������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	int i = begin;
	// ������������鲢����һ���������Ͷ�������
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
	//���������������ʱ��˵����һ�������Ѿ����н�����Ҫ��ʣ��һ���е���������ŵ�tmp
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	// ������ԭ����
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
// �ǵݹ�鲢
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	// �鲢ÿ�����ݸ�������1��ʼ����Ϊ1����Ϊ������ģ�����ֱ�ӹ鲢
//	int rangeN = 1;
//	while (rangeN < n)
//	{
//		for (int i = 0; i < n; i += 2 * rangeN)
//		{
//			// [begin1,end1][begin2,end2] �鲢
//			int begin1 = i, end1 = i + rangeN - 1;
//			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
//			int j = i;
//
//			// �ж�Խ�����
//			if (end1 >= n)//end1 Խ��
//			{
//				break;
//			}
//			else if (begin2 >= n)//begin2 Խ��
//			{
//				break;
//			}
//			else if (end2 >= n)//end2 Խ��
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
//			// �鲢һ���֣�����һ����
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

	// �鲢ÿ�����ݸ�������1��ʼ����Ϊ1����Ϊ������ģ�����ֱ�ӹ鲢
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			// [begin1,end1][begin2,end2] �鲢
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			int j = i;

			// �ж�Խ�����
			if (end1 >= n)//end1 Խ��
			{
				end1 = n - 1;
				// �Ѻ�һ�δ���Ϊһ�������ڵ�����
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)//begin2 Խ��
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)//end2 Խ��
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
		// ����鲢
		memcpy(a, tmp, sizeof(int) * n);
		rangeN *= 2;
	}


	free(tmp);
	tmp = NULL;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// 打印内容
void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 初始化
void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// 释放
void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
}

// 检查空间并扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	// 判断空间是否满，进行扩容
	if (ps->size == ps->capacity)
	{
		// 判断是否开辟空间，如果没开辟就给4个空间，如果开辟且满了，扩容为2倍
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		// 判断是否为空指针，如果是则说明开辟空间失败，并报错，退出程序
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		// 如果不是空指针，将其赋值给ps->a
		ps->a = tmp;
		// 最大容量更新
		ps->capacity = newCapacity;
	}
}
// 在pos位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
// 删除pos位置数据
void SLErase(SL* ps, int pos);

// 尾插
void SLPushBack(SL* ps, SLDataType x)
{
	//assert(ps);

	//SLCheckCapacity(ps);

	//// 将要插入的值放入内存
	//ps->a[ps->size] = x;
	//// 更新现有的数据量
	//ps->size++;

	SLInsert(ps, ps->size, x);
}

// 尾删
void SLPopBack(SL* ps)
{
	//assert(ps);
	//// 暴力检查数据量是否为0
	//assert(ps->size > 0);
	//ps->size--;
	
	SLErase(ps, ps->size - 1);
}

// 头插
void SLPushFront(SL* ps, SLDataType x)
{
	//assert(ps);
	//// 判断容量是否存满
	//SLCheckCapacity(ps);
	//// 挪动数据
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}

	//ps->a[0] = x;
	//ps->size++;

	SLInsert(ps, 0, x);
}

// 头删
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//// 挪动数据
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;

	SLErase(ps, 0);

}

// 在pos位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);
	// 判断容量是否存满
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (pos<=end)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

// 删除pos位置数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);

	int begin = pos+1;
	while (begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}

// begin查找x的起始位置(删除多个x)
int SLFind(SL* ps, SLDataType x, int begin)
{
	assert(ps);
	for (int i = begin; i < ps->size; i++)
	{
		if (x == ps->a[i])
			return i;
	}
	return -1;
}
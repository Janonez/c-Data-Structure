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

// 尾插
void SLPushBack(SL* ps, SLDataType x)
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

	// 将要插入的值放入内存
	ps->a[ps->size] = x;
	// 更新现有的数据量
	ps->size++;
}

// 尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	// 暴力检查数据量是否为0
	assert(ps->size > 0);
	ps->size--;
}
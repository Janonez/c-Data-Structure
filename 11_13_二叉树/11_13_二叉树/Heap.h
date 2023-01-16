#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;// 数组
	int size;
	int capacity;
}HP;

// 堆的构建
void HeapCreate(HP* php, HPDataType* a, int n);
// 堆的打印
void HeapPrint(HP* php);
// 堆的初始化
void HeapInit(HP* php);
// 堆的销毁
void HeapDestroy(HP* php);
// 堆的插入
void HeapPush(HP* php, HPDataType x);
// 堆的向上调整
void AdjustUp(HPDataType* a, int child);
// 堆的删除
void HeapPop(HP* php);
// 堆的向下调整
void AdjustDown(HPDataType* a, int n, int parent);
// 取堆顶的数据
HPDataType HeapTop(HP* php);
// 堆的数据个数
int HeapSize(HP* php);
// 堆的判空
bool HeapEmpty(HP* php);
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 静态顺序表 - 不太实用
// N小了不够用，大了浪费空间
//#define N 100
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int sz;
//}SL;

// 动态顺序表 - 按需扩空间
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size; // 记录储存了多少个数据
	int capacity; // 总的容量大小
}SL;

// 打印内容
void SLPrint(SL* ps);

// 初始化
void SLInit(SL* ps);

// 释放
void SLDestroy(SL* ps);

// 尾插
void SLPushBack(SL* ps, SLDataType x);

// 尾删
void SLPopBack(SL* ps);
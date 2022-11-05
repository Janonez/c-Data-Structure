#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 动态申请一个节点
SLTNode* BuySLTNode(SLTDataType x);
SLTNode* CreateSLTNode(int n);

// 单链表打印
void SLTPrint(SLTNode* phead);

// 单链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

// 单链表的尾删
void SLTPopBack(SLTNode** pphead);

// 单链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

// 单链表头删
void SLTPopFront(SLTNode** pphead);

// 单链表查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SLTEraseAfter(SLTNode* pos);

// 单链表的销毁
void SLTDestroy(SLTNode* plist);

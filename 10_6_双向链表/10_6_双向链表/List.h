#pragma once

#include <stdio.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

// 创建一个新结点
LTNode* BuyListNode(LTDataType x);

// 初始化链表
LTNode* ListInit();

// 尾插
void LTPushBack(LTNode* phead,LTDataType x);

// 尾删
void LTPopBack(LTNode* phead);

// 头插
void LTPushfront(LTNode* phead, LTDataType x);

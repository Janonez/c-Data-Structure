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

// ����һ���½��
LTNode* BuyListNode(LTDataType x);

// ��ʼ������
LTNode* ListInit();

// β��
void LTPushBack(LTNode* phead,LTDataType x);

// βɾ
void LTPopBack(LTNode* phead);

// ͷ��
void LTPushfront(LTNode* phead, LTDataType x);

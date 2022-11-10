#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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

// ��ӡ����
void LTPrint(LTNode* phead);

// β��
void LTPushBack(LTNode* phead, LTDataType x);

// βɾ
void LTPopBack(LTNode* phead);

// ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

// ͷɾ
void LTPopFront(LTNode* phead);

// ����
LTNode* LTFind(LTNode* phead, LTDataType x);

// ��POS֮ǰ��������
void LTInsert(LTNode* pos, LTDataType x);
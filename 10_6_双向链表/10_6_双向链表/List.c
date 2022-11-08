#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

// ����һ���½��
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

// ��ʼ������
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	// �����ڵ�
	LTNode* newnode = BuyListNode(x);
	// Ѱ��β�ڵ�
	LTNode* tail = phead->prev;
	// ��������
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

// βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	// �ж��Ƿ�ֻ��һ��ͷ���
	assert(phead->next != phead);

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);
}

// ͷ��
void LTPushfront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}
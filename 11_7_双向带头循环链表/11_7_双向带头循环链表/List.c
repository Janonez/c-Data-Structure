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

// ��ӡ����
void LTPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// ��POS֮ǰ��������
void LTInsert(LTNode* pos, LTDataType x);
// ɾ��posλ�õ�����
void LTErase(LTNode* pos);

// β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//// �����ڵ�
	//LTNode* newnode = BuyListNode(x);
	//// Ѱ��β�ڵ�
	//LTNode* tail = phead->prev;
	//// ��������
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
	LTInsert(phead,x);
}

// βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	// �ж��Ƿ�ֻ��һ��ͷ���
	assert(phead->next != phead);

	/*LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);*/

	LTErase(phead->prev);
}

// ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	/*LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/

	LTInsert(phead->next, x);
}

// ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*LTNode* cur = phead->next;
	LTNode* next = cur->next;
	free(cur);
	phead->next = next;
	next->prev = phead;*/
	LTErase(phead->next);
}

// ����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

// ��POS֮ǰ��������
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// ɾ��posλ�õ�����
void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

// �����п�
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	
	/*if (phead->next == phead)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return phead->next == phead;
}

// �����С
size_t LTSize(LTNode* phead)
{
	assert(phead);

	size_t size = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

// ��������
void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
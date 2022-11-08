#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

// 创建一个新结点
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

// 初始化链表
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// 尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	// 创建节点
	LTNode* newnode = BuyListNode(x);
	// 寻找尾节点
	LTNode* tail = phead->prev;
	// 插入数据
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

// 尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	// 判断是否只有一个头结点
	assert(phead->next != phead);

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	phead->prev = tailPrev;
	tailPrev->next = phead;
	free(tail);
}

// 头插
void LTPushfront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}
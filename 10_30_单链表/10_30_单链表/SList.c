#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// 动态申请一个节点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}
// 循环申请结点
SLTNode* CreateSLTNode(int n)
{
	SLTNode* phead = NULL, * ptail = NULL;
	for (int i = 0; i < n; i++)
	{
		SLTNode* NewNode = BuySLTNode(i);
		if (phead == NULL)
		{
			phead = ptail = NewNode;
		}
		else
		{
			ptail->next = NewNode;
			ptail = NewNode;
		}
	}
	return phead;
}

// 单链表打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


// 单链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}

// 单链表的尾删
void SLTPopBack(SLTNode** pphead)
{
	// 没有数据
	assert(*pphead);
	// 有一个数据
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	// 一个以上数据
	else
	{
		/*SLTNode* cur = *pphead;
		SLTNode* pre = NULL;
		while (cur->next)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;*/

		SLTNode* cur = *pphead;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}


// 单链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = BuySLTNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;
}

// 单链表头删
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);

	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}

// 单链表查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}
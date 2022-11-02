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
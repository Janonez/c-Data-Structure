#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// ��̬����һ���ڵ�
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
// ѭ��������
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

// �������ӡ
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


// ������β��
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

// �������βɾ
void SLTPopBack(SLTNode** pphead)
{
	// û������
	assert(*pphead);
	// ��һ������
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	// һ����������
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


// �������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = BuySLTNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;
}

// ������ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);

	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}

// ���������
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
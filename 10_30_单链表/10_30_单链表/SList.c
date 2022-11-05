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

// ��������posλ��֮�����x
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* NewNode = BuySLTNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

// ��������posλ��֮ǰ����x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);

	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	SLTNode* NewNode = BuySLTNode(x);
	prev->next = NewNode;
	NewNode->next = pos;
}

// ������ɾ��posλ��֮���ֵ
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
		return;

	SLTNode* NextNode = pos->next;
	pos->next = NextNode->next;
	free(NextNode);
}

// ������ɾ��posλ�õ�ֵ
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);

	if (*pphead == pos)
	{
		SLTPopFront(*pphead);
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
}

// �����������
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
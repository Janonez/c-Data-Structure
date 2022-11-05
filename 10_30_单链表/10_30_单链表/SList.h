#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// ��̬����һ���ڵ�
SLTNode* BuySLTNode(SLTDataType x);
SLTNode* CreateSLTNode(int n);

// �������ӡ
void SLTPrint(SLTNode* phead);

// ������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);

// �������βɾ
void SLTPopBack(SLTNode** pphead);

// �������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);

// ������ͷɾ
void SLTPopFront(SLTNode** pphead);

// ���������
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SLTEraseAfter(SLTNode* pos);

// �����������
void SLTDestroy(SLTNode* plist);

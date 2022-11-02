#pragma once
#include <stdio.h>
#include <stdlib.h>


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
void SLTPushBack(SLTNode** pplist, SLTDataType x);

// �������ͷ��
void SLTPushFront(SLTNode** pplist, SLTDataType x);

// �������βɾ
void SLTPopBack(SLTNode** pplist);

// ������ͷɾ
void SLTPopFront(SLTNode** pplist);

// ���������
SLTNode* SLTFind(SLTNode* plist, SLTDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SLTNode* pos);

// �����������
void SListDestroy(SLTNode* plist);

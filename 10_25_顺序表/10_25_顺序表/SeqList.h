#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ��̬˳��� - ��̫ʵ��
// NС�˲����ã������˷ѿռ�
//#define N 100
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int sz;
//}SL;

// ��̬˳��� - �������ռ�
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size; // ��¼�����˶��ٸ�����
	int capacity; // �ܵ�������С
}SL;

// ��ӡ����
void SLPrint(SL* ps);
// ��ʼ��
void SLInit(SL* ps);
// �ͷ�
void SLDestroy(SL* ps);
// ���ռ䲢����
void SLCheckCapacity(SL* ps);

// β��
void SLPushBack(SL* ps, SLDataType x);

// βɾ
void SLPopBack(SL* ps);

// ͷ��
void SLPushFront(SL* ps, SLDataType x);

// ͷɾ
void SLPopFront(SL* ps);

// �м����ɾ��
// ��posλ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x);

// ɾ��posλ������
void SLErase(SL* ps, int pos);

// begin����x����ʼλ��
int SLFind(SL* ps, SLDataType x, int begin);
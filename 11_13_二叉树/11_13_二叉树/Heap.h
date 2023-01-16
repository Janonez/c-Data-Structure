#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;// ����
	int size;
	int capacity;
}HP;

// �ѵĹ���
void HeapCreate(HP* php, HPDataType* a, int n);
// �ѵĴ�ӡ
void HeapPrint(HP* php);
// �ѵĳ�ʼ��
void HeapInit(HP* php);
// �ѵ�����
void HeapDestroy(HP* php);
// �ѵĲ���
void HeapPush(HP* php, HPDataType x);
// �ѵ����ϵ���
void AdjustUp(HPDataType* a, int child);
// �ѵ�ɾ��
void HeapPop(HP* php);
// �ѵ����µ���
void AdjustDown(HPDataType* a, int n, int parent);
// ȡ�Ѷ�������
HPDataType HeapTop(HP* php);
// �ѵ����ݸ���
int HeapSize(HP* php);
// �ѵ��п�
bool HeapEmpty(HP* php);
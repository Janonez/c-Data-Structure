#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// ��ӡ����
void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// ��ʼ��
void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// �ͷ�
void SLDestroy(SL* ps)
{
	assert(ps);

	
}
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

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
}

// ���ռ䲢����
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	// �жϿռ��Ƿ�������������
	if (ps->size == ps->capacity)
	{
		// �ж��Ƿ񿪱ٿռ䣬���û���پ͸�4���ռ䣬������������ˣ�����Ϊ2��
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		// �ж��Ƿ�Ϊ��ָ�룬�������˵�����ٿռ�ʧ�ܣ��������˳�����
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		// ������ǿ�ָ�룬���丳ֵ��ps->a
		ps->a = tmp;
		// �����������
		ps->capacity = newCapacity;
	}
}
// ��posλ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x);
// ɾ��posλ������
void SLErase(SL* ps, int pos);

// β��
void SLPushBack(SL* ps, SLDataType x)
{
	//assert(ps);

	//SLCheckCapacity(ps);

	//// ��Ҫ�����ֵ�����ڴ�
	//ps->a[ps->size] = x;
	//// �������е�������
	//ps->size++;

	SLInsert(ps, ps->size, x);
}

// βɾ
void SLPopBack(SL* ps)
{
	//assert(ps);
	//// ��������������Ƿ�Ϊ0
	//assert(ps->size > 0);
	//ps->size--;
	
	SLErase(ps, ps->size - 1);
}

// ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	//assert(ps);
	//// �ж������Ƿ����
	//SLCheckCapacity(ps);
	//// Ų������
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}

	//ps->a[0] = x;
	//ps->size++;

	SLInsert(ps, 0, x);
}

// ͷɾ
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//// Ų������
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;

	SLErase(ps, 0);

}

// ��posλ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);
	// �ж������Ƿ����
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (pos<=end)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

// ɾ��posλ������
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);

	int begin = pos+1;
	while (begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}

// begin����x����ʼλ��(ɾ�����x)
int SLFind(SL* ps, SLDataType x, int begin)
{
	assert(ps);
	for (int i = begin; i < ps->size; i++)
	{
		if (x == ps->a[i])
			return i;
	}
	return -1;
}
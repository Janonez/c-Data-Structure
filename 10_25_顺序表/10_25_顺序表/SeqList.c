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

// β��
void SLPushBack(SL* ps, SLDataType x)
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

	// ��Ҫ�����ֵ�����ڴ�
	ps->a[ps->size] = x;
	// �������е�������
	ps->size++;
}

// βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	// ��������������Ƿ�Ϊ0
	assert(ps->size > 0);
	ps->size--;
}
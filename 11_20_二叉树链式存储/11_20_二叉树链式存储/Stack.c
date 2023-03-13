#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(ST* ps,STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;

}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return (ps->top == 0);
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackDestroy(&st);
}

int main()
{
	TestStack();
	
	return 0;
}
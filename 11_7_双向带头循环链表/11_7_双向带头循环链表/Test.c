#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	LTNode* phead = ListInit();
	// β��
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	
	// βɾ
	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPrint(phead);

	// ͷ��
	LTPushFront(phead, 1);
	LTPushFront(phead, 2);
	LTPushFront(phead, 3);
	LTPushFront(phead, 4);
	LTPushFront(phead, 5);
	LTPrint(phead);

	// ͷɾ
	LTPopFront(phead);
	LTPopFront(phead);
	LTPrint(phead);
}
int main()
{
	TestList1();

	return 0;
}
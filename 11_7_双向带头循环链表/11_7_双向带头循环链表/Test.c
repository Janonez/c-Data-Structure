#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	LTNode* phead = ListInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);

}
int main()
{
	TestList1();

	return 0;
}
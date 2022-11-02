#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void TestSList1()
{
	/*SLTNode* n1 = malloc(1);
	SLTNode* n2 = malloc(2);
	SLTNode* n3 = malloc(3);
	SLTNode* n4 = malloc(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;*/

	SLTNode* plist = CreateSLTNode(10);
	SLTPrint(plist);
}

void TestSList2()
{
	//SLTNode* plist = CreateSLTNode(5);
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPrint(plist);
}

int main()
{
	TestSList1();
	TestSList2();

	return 0;
}
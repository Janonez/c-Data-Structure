#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}
//void Func1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//void Func2()
//{
//	int a = 1;
//	int b = 0;
//	printf("%p\n", &b);
//}
//int main()
//{
//	// printf("%lld\n", Fib(40));
//	Func1();
//	Func2();
//	return 0;
//}


#include "SeqList.h"

//void TestSeqList1()
//{
//	SL s1;
//	SLInit(&s1);
//	SLPushBack(&s1, 1);
//	SLPushBack(&s1, 2);
//	SLPushBack(&s1, 3);
//	SLPushBack(&s1, 4);
//	SLPushBack(&s1, 5);
//	SLPushBack(&s1, 6);
//	SLPushBack(&s1, 7);
//	SLPushBack(&s1, 8);
//	SLPushBack(&s1, 9);
//	SLPrint(&s1);
//	SLDestroy(&s1);
//}


//void TestSeqList2()
//{
//	SL s1;
//	SLInit(&s1);
//	SLPushFront(&s1, 1);
//	SLPushFront(&s1, 2);
//	SLPushFront(&s1, 3);
//	SLPushFront(&s1, 4);
//	SLPushFront(&s1, 5);
//	SLPrint(&s1);
//
//	SLPopFront(&s1);
//	SLPopFront(&s1);
//	SLPopFront(&s1);
//	SLPopFront(&s1);
//	SLPopFront(&s1);
//	//SLPopFront(&s1);
//	//SLPopFront(&s1);
//	SLPrint(&s1);
//
//	SLPushBack(&s1, 9);
//	SLPushBack(&s1, 9);
//	SLPushBack(&s1, 9);
//	SLPrint(&s1);
//
//	SLDestroy(&s1);
//}

//void TestSeqList2()
//{
//	SL s1;
//	SLInit(&s1);
//	SLPushBack(&s1, 1);
//	SLPushBack(&s1, 2);
//	SLPushBack(&s1, 3);
//	SLPushBack(&s1, 4);
//	SLPushBack(&s1, 4);
//	SLPushBack(&s1, 4);
//	SLPushBack(&s1, 4);
//	SLPrint(&s1);
//
//	SLPopFront(&s1);
//	SLPrint(&s1);
//	SLPushFront(&s1, 1);
//	SLPushFront(&s1, 2);
//	SLPrint(&s1);
//
//	/*int pos = SLFind(&s1, 2, 0);
//	if (pos != -1)
//	{
//		SLErase(&s1, pos);
//	}
//	SLPrint(&s1);*/
//
//	//// 删除所有x
//	//int pos = SLFind(&s1, 4, 0);
//	//while (pos != -1)
//	//{
//	//	SLErase(&s1, pos);
//	//	pos = SLFind(&s1, 4, pos);
//	//}
//	//SLPrint(&s1);
//	SLDestroy(&s1);
//}


void menu()
{
	printf("***********************************\n");
	printf("1.尾插 2.尾删 3.头插 4.头删 5.打印\n");
	printf("-1.退出\n");
	printf("***********************************\n");

}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	SL s1;
	SLInit(&s1);
	int option = 0;
	int val = 0;
	do
	{
		menu();
		printf("请输入你的操作:>");
		scanf("%d", &option);
		
		switch (option)
		{
		case 1:
			printf("请输入尾插的数据，以-1结束\n");
			scanf("%d", &val);
			while (val != -1)
			{
				SLPushBack(&s1, val);
				scanf("%d", &val);
			}
			break;
		case 2:
			SLPopBack(&s1);
			break;
		case 3:
			printf("请输入头插的数据，以-1结束\n");
			scanf("%d", &val);
			while (val != -1)
			{
				SLPushFront(&s1, val);
				scanf("%d", &val);
			}
			break;
		case 4:
			SLPopFront(&s1);
			break;
		case 5:
			SLPrint(&s1);
			break;
		default:
			break;
		}
			

	} while (option != -1);
	SLDestroy(&s1);
	return 0;
}

//int main()
//{
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//			count++;
//		else
//			nums[i - count] = nums[i];
//	}
//	return numsSize - count;
//}
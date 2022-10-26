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

void TestSeqList1()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 6);
	SLPushBack(&s1, 7);
	SLPushBack(&s1, 8);
	SLPushBack(&s1, 9);
	SLPrint(&s1);
	SLDestroy(&s1);
}

//int main()
//{
//	TestSeqList1();
//	return 0;
//}

int main()
{
	int nums[] = { 0,1,2,2,3,0,4,2};
	int numsSize = 8;
	int val = 2;
	int count = 0;
    for (int i = 0; i < numsSize - count; i++)
    {

        if (nums[i] == val)
        {
            for (int j = i; j < numsSize - 1 - count; j++)
            {
                nums[j] = nums[j + 1];
            }
            count++;
        }
    }
	for (int i = 0; i < numsSize - count; i++) 
		printf("%d ",nums[i]);
    return 0;
}
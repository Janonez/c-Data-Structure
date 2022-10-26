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
}

int main()
{
	TestSeqList1();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//#include "Queue.h"
//
//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//	printf("%d\n", QueueSize(&q));
//	printf("%d\n", QueueEmpty(&q));
//	printf("%d\n", QueueFront(&q));
//	printf("%d\n", QueueBack(&q));
//
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ", QueueFront(&q));
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//}
//int main()
//{
//	TestQueue();
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#pragma pack(8)
struct student
{
	char c1;
	int i;
	char c2;
};

int main() {
	struct student s1;
	printf("%zd\n", sizeof(struct student));
	return 0;
}
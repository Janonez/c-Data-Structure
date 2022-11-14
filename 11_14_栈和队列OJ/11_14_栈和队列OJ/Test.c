#define _CRT_SECURE_NO_WARNINGS 1
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	QDataType data;
//	struct Queue* next;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
//void QueueInit(Queue* pq);
//void QueueDestroy(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//bool QueueEmpty(Queue* pq);
//int QueueSize(Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->head = NULL;
//	pq->tail = NULL;
//	pq->size = 0;
//
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QNode* del = cur;
//		cur = cur->next;
//		free(del);
//	}
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//	pq->size++;
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* del = pq->head;
//		pq->head = pq->head->next;
//		free(del);
//	}
//	pq->size--;
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL && pq->tail == NULL;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	/*QNode* cur = pq->head;
//	int size = 0;
//	while (cur)
//	{
//		cur = cur->next;
//		size++;
//	}
//	return size;*/
//	return pq->size;
//}
//
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&(obj->q1));
//	QueueInit(&(obj->q2));
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		QueuePush(&(obj->q1), x);
//	}
//	else {
//		QueuePush(&(obj->q2), x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	MyStack* emptyQ = &(obj->q1);
//	MyStack* nonemptyQ = &(obj->q2);
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		emptyQ = &(obj->q2);
//		nonemptyQ = &(obj->q1);
//	}
//	while (QueueSize(nonemptyQ) > 1)
//	{
//		QueuePush(emptyQ, QueueFront(nonemptyQ));
//		QueuePop(nonemptyQ);
//	}
//	int top = QueueFront(nonemptyQ);
//	QueuePop(nonemptyQ);
//	return top;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		return QueueBack(&(obj->q1));
//	}
//	else {
//		return QueueBack(&(obj->q2));
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&(obj->q1));
//	QueueDestroy(&(obj->q2));
//	free(obj);
//}

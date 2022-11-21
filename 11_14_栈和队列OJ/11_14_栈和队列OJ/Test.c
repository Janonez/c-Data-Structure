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






//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int capacity;
//	int top;
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//STDataType StackTop(ST* ps);
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
//	if (ps->a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	ps->capacity = 4;
//	ps->top = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->top = ps->capacity = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity *= 2;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	ps->top--;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return (ps->top == 0);
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//typedef struct {
//	ST pushst;
//	ST popst;
//} MyQueue;
//
//bool myQueueEmpty(MyQueue* obj);
//MyQueue* myQueueCreate() {
//	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&(pq->pushst));
//	StackInit(&(pq->popst));
//	return pq;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	assert(obj);
//	StackPush(&(obj->pushst), x);
//}
//int myQueuePeek(MyQueue* obj);
//int myQueuePop(MyQueue* obj) {
//	assert(obj);
//	assert(!myQueueEmpty(obj));
//
//	int peek = myQueuePeek(obj);
//	StackPop(&(obj->popst));
//	return peek;
//}
//
//int myQueuePeek(MyQueue* obj) {
//	assert(obj);
//	assert(!myQueueEmpty(obj));
//	if (StackEmpty(&(obj->popst)))
//	{
//		while (!StackEmpty(&(obj->pushst)))
//		{
//			StackPush(&(obj->popst), StackTop(&(obj->pushst)));
//			StackPop(&(obj->pushst));
//		}
//	}
//
//	return StackTop(&(obj->popst));
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//	assert(obj);
//	return StackEmpty(&(obj->pushst)) && StackEmpty(&(obj->popst));
//}
//
//void myQueueFree(MyQueue* obj) {
//	assert(obj);
//	StackDestroy(&(obj->pushst));
//	StackDestroy(&(obj->popst));
//	free(obj);
//}
//
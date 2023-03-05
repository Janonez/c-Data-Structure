#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//struct BinaryTreeNode;// Ç°ÖÃÉùÃ÷
//typedef int BTDataType;

//typedef struct BinaryTreeNode
//{
//	BTDataType data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;
typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct Queue* next;
}QNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
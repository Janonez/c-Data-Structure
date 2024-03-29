#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

// 二叉树前序遍历
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL) {
//		printf("NULL ");
//		return;
//	}
//	printf("%d ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}
void PrevOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

// 二叉树中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);	
	InOrder(root->right);
}

// 二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}	

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}    

	node->data = x;
	node->left = node->right = NULL;
	return node;
}

// 求二叉树节点个数
int size = 0;
void TreeSize(BTNode* root)
{
	if (root == NULL)
		return;
	size++;
	TreeSize(root->left);
	TreeSize(root->right);
}

int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

// 叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return (root->left == NULL && root->right == NULL) ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// 求树的高度/深度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 求第k层节点个数 第k层
int TreeLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelSize(root->left, k - 1) + TreeLevelSize(root->right, k - 1);
}

// 二叉树查找值为x的结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
}

// 层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);
		if(front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)// 遇到第一个NULL就开始判断，如果后面都是NULL就true
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)// 判断是否全为空，如果有不为空的就为false
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(char* a,  int* pi)
{
	//char arr[] = { "ABD##E#H##CF##G##" };
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	// 创建一个结构体节点
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[(*pi)++];
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}

void TestBinaryTreeCreate()
{
	char a[] = { "ABD##E#H##CF##G##" };
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	PrevOrder(root);
}
int main()
{
	/*BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	BTNode* n7 = BuyNode(7);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n2->right = n7;

	PrevOrder(n1);
	printf("\n");

	InOrder(n1);
	printf("\n");

	PostOrder(n1);
	printf("\n");*/

	/*size = 0;
	TreeSize(n1);
	printf("TreeSize:%d\n", size);
	printf("TreeSize:%d\n", TreeSize2(n1));
	printf("TreeSize:%d\n", TreeSize2(n1));
	printf("TreeSize:%d\n", TreeSize2(n1));*/

	/*printf("TreeLeafSize:%d\n", TreeLeafSize(n1));
	
	printf("TreeHeight:%d\n", TreeHeight(n1));

	LevelOrder(n1);
	printf("TreeComplete:%d\n", TreeComplete(n1));*/
	
	TestBinaryTreeCreate();
	return 0;
}
// --------------------------------------练习----------------------------------------------
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == NULL)
		return;
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : 
		BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//int size = 0;
//void BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	size++;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return (root->left == NULL && root->right == NULL) ? 1
		: BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{

}
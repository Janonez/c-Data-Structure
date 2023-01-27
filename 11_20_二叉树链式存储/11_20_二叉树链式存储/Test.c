#define _CRT_SECURE_NO_WARNINGS 1


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
void PrevOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
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

// 节点个数
int size = 0;
void BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	size++;
	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);
}

int main()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;

	PrevOrder(n1);
	printf("\n");

	InOrder(n1);
	printf("\n");

	PostOrder(n1);
	printf("\n");

	size = 0;
	BinaryTreeSize(n1);
	printf("BinaryTreeSize:%d\n", size);

	return 0;
}
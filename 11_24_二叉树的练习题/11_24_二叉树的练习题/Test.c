#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。

//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->left->val != root->val)
//        return false;
//
//    if (root->right && root->right->val != root->val)
//        return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}


//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//    if (p->val != q->val)
//        return false;
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}


//给你一个二叉树的根节点 root ， 检查它是否轴对称。

//bool check(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//    if (p->val != q->val)
//        return false;
//    return check(p->left, q->right) && check(p->right, q->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    return check(root, root);
//}

//给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
//如果存在，返回 true ；否则，返回 false 。
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//    if (p->val != q->val)
//        return false;
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//
//
//    if (isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//
//}


//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* prevCreate(char* str, int* pi)
{
    if (str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = str[(*pi)++];
    root->left = prevCreate(str, pi);
    root->right = prevCreate(str, pi);
    return root;
}

void InOrder(struct TreeNode* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    struct TreeNode* root = prevCreate(str, &i);
    InOrder(root);
    return 0;
}
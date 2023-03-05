#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��

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


//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//    if (p->val != q->val)
//        return false;
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}


//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�

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

//�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������
//������ڣ����� true �����򣬷��� false ��
//������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������

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


//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ������������������������������

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
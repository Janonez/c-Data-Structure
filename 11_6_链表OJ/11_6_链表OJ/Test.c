#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//    
//};
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//
//    while (head != NULL && head->val == val)
//    {
//        head = head->next;
//    }
//    while (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* cur = head;
//    while (cur->next)
//    {
//        if (cur->next->val == val)
//        {
//            cur->next = cur->next->next;
//        }
//        else
//        {
//            cur = cur->next;
//        }
//    }
//    return head;
//}

//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//struct ListNode {
//    int val;
//    struct ListNode* next;
//    
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* phead, * ptail;
//    phead = ptail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = NULL;
//    while (list1 != NULL && list2 != NULL)
//    {
//        if (list1->val >= list2->val)
//        {
//            ptail->next = list2;
//            ptail = ptail->next;
//            list2 = list2->next;
//        }
//        else
//        {
//            ptail->next = list1;
//            ptail = ptail->next;
//            list1 = list1->next;
//        }
//    }
//    if (list1 == NULL)
//    {
//        ptail->next = list2;
//    }
//    if (list2 == NULL)
//    {
//        ptail->next = list1;
//    }
//    struct ListNode* cur = phead->next;
//    free(phead);
//    return cur;
//}

//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
// 
//    struct ListNode* n1, * n2, * n3;
//    if (head == NULL)
//        return NULL;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//    return n1;
//}

//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}


//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        struct ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
//        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        lesshead->next = greaterhead->next = NULL;
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val >= x)
//            {
//                greatertail->next = cur;
//                cur = cur->next;
//                greatertail = greatertail->next;
//            }
//            else {
//                lesstail->next = cur;
//                cur = cur->next;
//                lesstail = lesstail->next;
//            }
//        }
//        if (greatertail != NULL)
//            greatertail->next = NULL;
//
//        lesstail->next = greaterhead->next;
//        pHead = lesshead->next;
//        free(lesshead);
//        free(greaterhead);
//        return pHead;
//    }
//};
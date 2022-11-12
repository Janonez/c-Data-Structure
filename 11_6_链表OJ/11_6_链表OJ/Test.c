#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
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

//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
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


//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
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



//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//class PalindromeList {
//public:
//    struct ListNode* middleNode(struct ListNode* phead)
//    {
//        struct ListNode* slow, * fast;
//        slow = fast = phead;
//        while (fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//
//    struct ListNode* reverseList(struct ListNode* phead)
//    {
//        struct ListNode* cur = phead;
//        struct ListNode* newhead = NULL;
//        while (cur)
//        {
//            struct ListNode* Next = cur->next;
//            cur->next = newhead;
//            newhead = cur;
//            cur = Next;
//        }
//        return newhead;
//    }
//    bool chkPalindrome(ListNode* A)
//    {
//        // 寻找中间节点
//        struct ListNode* mid = middleNode(A);
//        // 反转后半部分节点
//        struct ListNode* newhead = reverseList(mid);
//        while (A && newhead)
//        {
//            if (A->val != newhead->val)
//                return false;
//
//            A = A->next;
//            newhead = newhead->next;
//        }
//        return true;
//    }
//};

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    if (headA == NULL || headB == NULL)
//    {
//        return NULL;
//    }
//    int sizeA = 0, sizeB = 0;
//    struct ListNode* curA = headA, * curB = headB;
//    while (curA)
//    {
//        sizeA++;
//        curA = curA->next;
//    }
//    while (curB)
//    {
//        sizeB++;
//        curB = curB->next;
//    }
//    // 差值 abs - 绝对值
//    int Dvalue = abs(sizeA - sizeB);
//    curA = headA;
//    curB = headB;
//    if (sizeA > sizeB)
//    {
//        while (Dvalue)
//        {
//            curA = curA->next;
//            Dvalue--;
//        }
//    }
//    else
//    {
//        while (Dvalue)
//        {
//            curB = curB->next;
//            Dvalue--;
//        }
//    }
//    while (curA != curB)
//    {
//        curA = curA->next;
//        curB = curB->next;
//    }
//    return curA;
//}
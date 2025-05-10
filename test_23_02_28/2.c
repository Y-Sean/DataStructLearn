#include<stdio.h>
#include<stdlib.h>

//删除链表中等于给定值 val 的所有节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // 基础思想
 /*struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode *prev = NULL, *next = head;
	while (next != NULL) {
		if (next->val != val) {
			prev = next;
			next = next->next;
		} else {
			if (prev == NULL) {
				head = next->next;
				free(next);
				next = head;
			} else {
				prev->next = next->next;
				free(next);
				next = prev->next;
			}
		}
	}
	return head;
 }
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newhead = NULL, * tail = NULL, * cur = head;
	while (cur) {
		if (cur->val != val) {
			if (tail == NULL) {
				newhead = tail = cur;
			}
			else {
				tail->next = cur;
				tail = tail->next;
			}
			cur = cur->next;
		}
		else {
			struct ListNode* tmp = cur->next;
			free(cur);
			cur = tmp;
		}
	}
	if (tail)
		tail->next = NULL;
	return newhead;
}*/

//反转一个单链表
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    while (cur) {
//        struct ListNode* temp = cur->next;
//        if (tail == NULL) {
//            newhead = tail = cur;
//            cur->next = NULL;
//        }
//        else {
//            cur->next = newhead;
//            newhead = cur;
//        }
//        cur = temp;
//    }
//    return newhead;
//}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点

//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* slow = NULL, * fast = NULL;
//	slow = fast = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}
//
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//	struct ListNode* cur = middleNode(n1);
//	return 0;
//}

//输入一个链表，输出该链表中倒数第k个结点
/*int kthToLast(struct ListNode* head, int k) {
	struct ListNode* fast,*slow;
	fast=slow=head;
	while(k--){
		fast=fast->next;
	}
	while(fast){
		slow=slow->next;
		fast=fast->next;
	}
	return slow->val;
}*/

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//		return list2;
//	if (list2 == NULL)
//		return list1;
//	struct ListNode* cur1 = list1, * cur2 = list2;
//	struct ListNode* guard = NULL, * tail = NULL;
//	guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	tail->next = NULL;
//	while (cur1 && cur2) {
//		if (cur1->val <= cur2->val) {
//			tail->next = cur1;
//			tail = tail->next;
//			cur1 = cur1->next;
//		}
//		else {
//			tail->next = cur2;
//			tail = tail->next;
//			cur2 = cur2->next;
//		}
//	}
//	if (cur1)
//		tail->next = cur1;
//	if (cur2)
//		tail->next = cur2;
//	struct ListNode* head = guard->next;
//	free(guard);
//	return head;
//}
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
/*class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (pHead == NULL)
			return NULL;
		//不改变原来顺序，尾插
		//分离两类链表，最后合并
		ListNode* cur = pHead;
		ListNode* Gguard, * Gtail;
		ListNode* Lguard, * Ltail;
		Gguard = Gtail = (ListNode*)malloc(sizeof(ListNode));
		Lguard = Ltail = (ListNode*)malloc(sizeof(ListNode));
		while (cur)
		{
			if (cur->val < x)
			{
				Ltail->next = cur;
				Ltail = Ltail->next;
			}
			else {
				Gtail->next = cur;
				Gtail = Gtail->next;
			}
			ListNode* tmp = cur->next;
			cur->next = NULL;//********断开原来节点，防止成环
			cur = tmp;
		}
		Ltail->next = Gguard->next;
		Gtail->next = NULL;
		ListNode* newhead = Lguard->next;
		free(Lguard);
		free(Gguard);
		return newhead;
	}
}; */

/*对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
测试样例：*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
/*
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//找到中间节点slow
		ListNode* cur = A;
		ListNode* fast = cur, * slow = cur;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//将中间节点后的链表逆置
		cur = slow;
		ListNode* head = NULL, * tail = cur->next;
		while (cur->next)
		{
			cur->next = head;
			head = cur;
			cur = tail;
			tail = tail->next;
		}
		//一一进行比对
		tail = A;
		while (cur)
		{
			if (cur->val != tail->val)
				return false;
			tail = tail->next;
			cur = cur->next;
		}
		return true;
	}
}; */

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	 if (headA == NULL || headB == NULL) {
		 return NULL;
	 }
	 struct ListNode* cur1 = headA, * cur2 = headB;
	 int num1 = 1, num2 = 1;
	 while (cur1->next)
	 {
		 cur1 = cur1->next;
		 num1++;
	 }
	 while (cur2->next)
	 {
		 cur2 = cur2->next;
		 num2++;
	 }
	 if (cur1 != cur2)
		 return NULL;
	 else
	 {
		 int k = num1 > num2 ? num1 - num2 : num2 - num1;
		 cur1 = headA;
		 cur2 = headB;
		 while (k--)
		 {
			 if (num1 > num2)
			 {
				 cur1 = cur1->next;
			 }
			 else
			 {
				 cur2 = cur2->next;
			 }
		 }
		 while (cur1 != cur2)
		 {
			 cur1 = cur1->next;
			 cur2 = cur2->next;
		 }
		 return cur1;
	 }
 }*/

 //判断链表是否有环
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };
  */
  /*bool hasCycle(struct ListNode* head) {
	  struct ListNode* fast = head, * slow = head;
	  while (fast && fast->next)
	  {
		  fast = fast->next->next;
		  slow = slow->next;
		  if (fast == slow)
			  return true;
	  }
	  return false;
  }*/
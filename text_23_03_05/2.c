//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
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
		//���ı�ԭ��˳��β��
		//���������������ϲ�
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
			cur->next = NULL;//********�Ͽ�ԭ���ڵ㣬��ֹ�ɻ�
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

/*����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
����������*/
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
		//�ҵ��м�ڵ�slow
		ListNode* cur = A;
		ListNode* fast = cur, * slow = cur;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//���м�ڵ�����������
		cur = slow;
		ListNode* head = NULL, * tail = cur->next;
		while (cur->next)
		{
			cur->next = head;
			head = cur;
			cur = tail;
			tail = tail->next;
		}
		//һһ���бȶ�
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

//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
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

 //�ж������Ƿ��л�
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
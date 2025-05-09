#include"SList.h"

void SListTest1()
{
	SListNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushFront(&phead, 0);
	SListPushFront(&phead, 5);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopFront(&phead);
	SListPrint(phead);
}

void SListTest2()
{
	SListNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);
	SListNode* cur = SListFind(phead, 5);
	if (cur == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n", cur->data);
	}
}

int main()
{
	SListTest2();
	return 0;
}
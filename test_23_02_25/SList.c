#include"SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist;
	while (plist != NULL)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	//不用判空，空可以尾插
	/*SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;*/
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		// 找尾
		SListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	/*SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;*/
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SListNode** pplist)
{
	// 空链表不能删除
	assert(pplist && *pplist);

	// 如果链表只有一个节点
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}

	// 找到倒数第二个节点
	SListNode* tail = *pplist;
	while (tail->next->next)
	{
		tail = tail->next;
	}

	// 释放最后一个节点
	free(tail->next);
	tail->next = NULL;
}

void SListPopFront(SListNode** pplist)
{
	//空不能删除
	assert(pplist && *pplist);
	////只有一个结点
	//if ((*pplist)->next == NULL)
	//{
	//	free(*pplist);
	//	*pplist = NULL;
	//	return;
	//}不需要考虑这种情况，一个结点后面接的是NULL
	SListNode* head = *pplist;
	*pplist = head->next;
	free(head);
	head = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
		return NULL;
	SListNode* cur = plist;
	while (cur != NULL && cur->data != x)
	{
		cur = cur->next;
	}
	if (cur == NULL)
		return NULL;
	return cur;
}

// 在pos的前面插入
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	//可以为空表
	assert(pplist);
	//在第一个位置，即头插法
	if (pos == *pplist)
		SListPushFront(pplist, x);
	else
	{
		SListNode* newnode = BuySListNode(x);
		SListNode* prev = *pplist;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
	assert(*pplist);
	//在第一个位置，即头删法
	if (pos == *pplist)
		SListPopFront(pplist);
	else
	{
		SListNode* prev = *pplist;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SListDestroy(SListNode** pplist)
{
	//调用尾删法，麻烦
	/*while (*pplist != NULL)
		SListPopBack(pplist);*/
		//调用头删法
	while (*pplist != NULL)
		SListPopFront(pplist);
	/*SListNode* head = *pplist;
	while (head != NULL)
	{
		SListNode* next = head->next;
		free(head);
		head = NULL;
	}*/
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？

//*******没有给头指针,不能找到前一个结点指向的下一个结点的地址。
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	// 确保pos不为空并且pos后面有节点
	assert(pos && pos->next);
	SListNode* temp = pos->next;
	pos->next = temp->next;
	free(temp);
}
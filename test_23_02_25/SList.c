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
	//�����пգ��տ���β��
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
		// ��β
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
	// ��������ɾ��
	assert(pplist && *pplist);

	// �������ֻ��һ���ڵ�
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}

	// �ҵ������ڶ����ڵ�
	SListNode* tail = *pplist;
	while (tail->next->next)
	{
		tail = tail->next;
	}

	// �ͷ����һ���ڵ�
	free(tail->next);
	tail->next = NULL;
}

void SListPopFront(SListNode** pplist)
{
	//�ղ���ɾ��
	assert(pplist && *pplist);
	////ֻ��һ�����
	//if ((*pplist)->next == NULL)
	//{
	//	free(*pplist);
	//	*pplist = NULL;
	//	return;
	//}����Ҫ�������������һ��������ӵ���NULL
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

// ��pos��ǰ�����
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	//����Ϊ�ձ�
	assert(pplist);
	//�ڵ�һ��λ�ã���ͷ�巨
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
	//�ڵ�һ��λ�ã���ͷɾ��
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
	//����βɾ�����鷳
	/*while (*pplist != NULL)
		SListPopBack(pplist);*/
		//����ͷɾ��
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿

//*******û�и�ͷָ��,�����ҵ�ǰһ�����ָ�����һ�����ĵ�ַ��
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	// ȷ��pos��Ϊ�ղ���pos�����нڵ�
	assert(pos && pos->next);
	SListNode* temp = pos->next;
	pos->next = temp->next;
	free(temp);
}
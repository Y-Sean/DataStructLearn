#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	SLDateType* p = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	assert(p);
	ps->a = p;
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	ps->capacity = ps->size = 0;
	free(ps->a);
	ps->a = NULL;
}

void SeqListPrint(SeqList* ps) {
	assert(ps);
	assert(ps->a);
	int i = 0;
	for (; i < ps->size; i++)
	{
		printf("%d ", *(ps->a + i));
	}
	printf("\n");
}

void checkcapacity(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->capacity <= ps->size)
	{
		SLDateType* f = (SLDateType*)realloc(ps->a, 2 * ps->capacity * sizeof(SLDateType));
		assert(f);
		ps->a = f;
		ps->capacity *= 2;
		printf("���ݳɹ�\n");
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->a);
	checkcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->a);
	checkcapacity(ps);
	int i = 0;
	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->size == 0) {
		printf("�б�Ϊ�գ��޷�����\n");
		return;
	}
	int i = 0;
	for (; i <= ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->size == 0) {
		printf("�б�Ϊ�գ��޷�����\n");
		return;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	assert(ps->a);
	int i = 0;
	for (; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return 0;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	// ���ָ��Ϸ���
	assert(ps);
	assert(ps->a);

	// ������λ���Ƿ�Ϸ�
	if (pos < 0 || pos > ps->size)
	{
		printf("����λ�÷Ƿ�: %d\n", pos);
		return;
	}

	// ��������Ƿ��㹻
	checkcapacity(ps);

	// �ƶ����ݣ�ȷ������λ���пռ�
	memmove(ps->a + pos + 1, ps->a + pos, (ps->size - pos) * sizeof(SLDateType));

	// ������Ԫ��
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	// ���ָ��Ϸ���
	assert(ps);
	assert(ps->a);

	// ������λ���Ƿ�Ϸ�
	if (pos < 0 || pos > ps->size)
	{
		printf("����λ�÷Ƿ�: %d\n", pos);
		return;
	}
	memmove(ps->a + pos, ps->a + pos + 1, (ps->size - pos - 1) * sizeof(SLDateType));
	ps->size--;
}

void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListFind(&s, 1);
	SeqListInsert(&s, 1, 8);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	SeqListDestroy(&s);
}

int main()
{
	test();
	return 0;
}
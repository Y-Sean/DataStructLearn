#pragma once
#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
#include <string.h>

typedef int SLDateType;

////��̬˳���ʹ�ö�����ʵ��������
//#define N 7
//typedef struct SL
//{
//	SLDateType array[N];//��������
//	int size;//��ЧԪ�ظ���
//}SL;

//��̬���ٵ�˳���
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;
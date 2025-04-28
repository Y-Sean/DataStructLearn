#pragma once
#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
#include <string.h>

typedef int SLDateType;

////静态顺序表，使用定长。实质是数组
//#define N 7
//typedef struct SL
//{
//	SLDateType array[N];//定长数组
//	int size;//有效元素个数
//}SL;

//动态开辟的顺序表
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;
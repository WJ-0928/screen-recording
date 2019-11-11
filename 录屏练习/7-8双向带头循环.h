#if 0


#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



//1.���

typedef struct Node
{
	int val;
	struct Node *prev;
	struct Node *next;
} Node;


//2.����
typedef struct List
{
	Node *head;//ͷ��㣨û����Чֵ��
} List;

//��ʼ��
void ListInit(List *list)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val =0;
	node->next = node;
	node->prev = node;
	list->head = node;
}

//ͷ��
void ListPushFront(List *list,int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	
	node->prev = list->head;
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
}

//β��
void ListPushBack(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;

	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
}

//�ѽ��鵽pos֮��
void ListInsertAfterPos(Node *pos, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;

	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

// �ѽ��鵽pos֮��
void ListInsertBeforePos(Node *pos, int val)
{
	ListInsertAfterPos(pos->prev, val);
}
#endif
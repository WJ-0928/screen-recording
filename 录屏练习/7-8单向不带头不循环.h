#if 0
#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.���
typedef struct Node
{
	int val;
	struct Node *next;
} Node;

//2.����
typedef struct List
{
	Node *head;//����ĵ�һ�����
} List;


//��ʼ��
void ListInit(List *list)
{
	list->head = NULL;
}

//����
void ListDestroy(List *list)
{
	//��ÿ����㶼��Ҫ�ͷ�
	Node *cur = list->head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
}

//ͷ��
void ListPushFront(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = list->head;
	list->head = node;
}

//β��
void ListPushBack(List *list, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (list->head == NULL)
	{
		list->head = node;
	}
	else
	{
		Node *cur = list->head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}


//ͷɾ
void ListPopFront(List *list)
{
	assert(list->head != NULL);
	Node *second = list->head->next;
	free(list->head);
	list->head=second;
}

//βɾ
void ListPopBack(List *list)
{
	assert(list->head != NULL);
	//�ҵ����ڶ�����㣨�������������)
	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}
	else
	{
		Node *cur = list->head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}


//�м�ɾ��(index�϶��Ϸ���
void ListInsert(List *list,int index, int val)
{
	Node *prev = list->head;
	for (int i = 0; i < index - 1; i++)
	{
		prev = prev->next;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = prev->next;
	prev->next = node;
}
#endif

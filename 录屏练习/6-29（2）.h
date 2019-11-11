#if 0
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//���Ķ���
typedef struct Node
{
	int val;//����
	struct Node *next;//��һ����������
	                  //��next==NULLʱ����ʾû�к��������
	                  //������˵�����һ������nextһ��==NULL
} Node;

//ͷ��
Node * ListPushFront(Node *head,int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//��node����һ��Ϊԭ��һ�����
	node->next = head;
	//noed��Ϊ�µĵ�һ�����
	return node;
}

//β��
Node *ListPushBack(Node *head, int val)
{
	//1.װ�������
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//2.node��next��λNULL
	node->next = NULL;
	if (head != NULL)
	{
		//�������н������
		//3.�ҵ�ԭ���һ�����
		Node *cur = head;
		while (cur != NULL)
		{
			cur = cur->next;
		}
		//cur�������һ�����
		//��ԭ���һ��������һ��Ϊnode
		cur->next = node;
	}
	else
	{
		node = head;
	}
	return head;
}

//ͷɾ
Node *ListPopFront(Node *head)
{
	assert(head != NULL);
	/*
	Node *oldHead = head;
	free(oldHead);
	return head->next;
	*/
	Node *next = head->next;
	free(head);
	return next;
	
}

//βɾ
Node *ListPopBack(Node *head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		//���ҵ������ڶ����ڵ�
		Node *cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//
		//�ͷ�cur->next�Ŀռ�
		free(cur->next);
		cur->next = NULL;
	}
		return head;
}

//��ת����
Node *reverseList(Node *head)
{
	Node *rHead = NULL;
	Node *cur = head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		cur->next = rHead;
		rHead = cur;
		cur = cur->next;
	}
	return rHead;
}


//��ӡ
void ListPrint(Node *head)
{
	//��α���ָ��
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d--> ", cur->val);
	}
	printf("NULL\n");
}


//��ʼ��
void Test()
{
	Node *head = NULL;//����ĳ�ʼ��

	//��������ͷ��
	ListPrint(head);
	head = ListPushFront(head, 1);
	ListPrint(head);
	head = ListPushFront(head, 2);
	ListPrint(head);
	head = ListPushFront(head, 3);
	ListPrint(head);
	head = ListPushFront(head, 4);
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);

	ListPrint(head);

	head = ListPopBack(head, 10);
	head = ListPopBack(head, 20);
	head = ListPopBack(head, 30);
	ListPrint(head);
	//֮ǰ����ڴ�й©��û���ͷ�
	head = NULL;
	head = ListPushBack(10);
	head = ListPushBack(20);
	ListPrint(head);
	//head��Ӧ����NULL��
}
#endif
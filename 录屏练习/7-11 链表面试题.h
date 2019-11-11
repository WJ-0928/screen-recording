#if 0
#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *random;
	struct Node *next;
} Node;



//���д�randomָ���������
Node *copy(Node *head)
{
	/*
	��ÿ����㣨�Ͻ�㣩���Ƴ�һ����㣨�½�㣩
	���½������Ͻ�����
	*/
	Node *cur = head;
	while (cur != NULL)
	{
		//�ȸ����½��
		Node *node = (Node *)malloc(sizeof(Node));
		node->val = cur->val;
		//���½�㣨node�������Ͻ�㣨cur������
		node->next = cur->next;
		cur->next = node;
		//��������curָ����һ���Ͻ��
		cur = node->next;
	}
	/*
	����random�ĸ���
	curָ��ÿһ���Ͻ��
	*/
	cur = head;
	while (cur != NULL)
	{
		//cur->next����cur��Ӧ���½��
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;
	}
	/*
	���������µĺ��ϵ�
	*/
	cur = head;
	Node *newHead = head->next;
	while (cur != NULL)
	{
		Node *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}

Node *createNode(int val)
{
     Node *node = (Node *)malloc(sizeof(Node));
	 node->val = val;
	 return node;
}

void test()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n3;
	n4->next = n4;
	n5->next = NULL;

	n1->random = n3;
	n2->random= n1;
	n3->random= n4;
	n4->random= n4;
	n5->random = NULL;

	Node *result = copy(n1);

	for (Node *cur = n1; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
	for (Node *cur = result; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
}
#endif
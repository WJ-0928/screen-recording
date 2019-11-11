#if 0
#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *rendom;
} Node;

//����������ɾ���ظ����
Node *deleteDuplication(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = head;
	Node *prev = node;
	Node *p1 = head;
	Node *p2 = head->next;//headһ������NULL
	while (p2!=NULL)
	{
		if (p1->val != p2->val)
		{
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p1->val == p2->val)
			{
				p2 = p2->next;
			}
			prev->next = p2;
			p1 = p2;
			if (p2 != NULL)
			{
                 p2 = p2->next;//��֤p2��Ϊ��
			}
		}
	}
	return node->next;
}

//��������
Node *reverseList(Node *head)
{
	Node *rHead = NULL;
	Node *cur = head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		cur->next = rHead;
		rHead = cur;
		cur = next;
	}
	return rHead;
}

//ɾ������val
Node *remoneAll(Node *head, int val)
{
	Node *prev = head;
	Node *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			prev->next = cur->next;
		}
		else
		{
			prev = cur;
		}
		cur = cur->next;
	}
	if (head->val == val)
	{
		head = head->next;
	}
	return head;
}



//�ҵ�������ڵ㣬�ж��Ƿ����
bool hasCycle(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//����жϴ���/����ָ����������
	Node *fast = head;
	Node *slow = head;
	do
	{
		fast = fast->next;
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			return NULL;
		}
		slow = slow->next;
	} while (fast != slow);
	//fast��slow����������
	//����ҵ�������ڵ�
	//һ����������head
	//һ�������������slow
	//�������ָ������ˣ�������ڵ�
	Node *p1 = head;
	Node *p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


//������ͨ����

Node * copy(Node *head)
{
	Node *rHead = NULL;
	Node *cur = head;
	Node *last = NULL;
	while (cur != NULL)
	{
		Node * node = (Node *)malloc(sizeof(Node));
		node->val = cur->val;
		if (rHead == NULL)
		{
			rHead = node;
		}
		else
		{
			last->next = node;
		}
		last = node;
		cur = cur->next;
	}
	last->next = NULL;
	return rHead;
}



//��������ĸ���

Node *copyRandomList(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node *cur = head;
	while (cur!=NULL)
	{
		Node *node = (Node *)malloc(sizeof(Node));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while (cur!=NULL)
	{
		if (cur->rendom == NULL)
		{
			cur->next->rendom = NULL;
		}
		else
		{
			cur->next->rendom = cur->rendom->next;
		}
		cur = cur->next->next;
	}
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

#endif
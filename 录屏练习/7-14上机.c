#if 0

#include"7-14上机.h"

#include<stdio.h>
#include<stdlib.h>


//复杂链表的复制
Node *copy(Node *head)
{
	Node *cur= head;
	while (cur != NULL)
	{
		Node *node = (Node *)malloc(sizeof(Node));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		else
		{
			cur->next->random =NULL;
		}
		cur = cur->next->next;
	}
	cur = head;
	Node *newHead = head->next;
	while (cur != NULL)
	{
		Node * node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}

//删除重复链表
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
	Node *p2 = head->next;
	while (p2 != NULL)
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
				p2 = p2->next;
			}
		}
	}
	return node->next;
}


//创造结点
Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}


#endif
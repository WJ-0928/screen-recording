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

//有序链表中删除重复结点
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
	Node *p2 = head->next;//head一定不能NULL
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
                 p2 = p2->next;//保证p2不为空
			}
		}
	}
	return node->next;
}

//链表逆置
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

//删除所有val
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



//找到环的入口点，判断是否带环
bool hasCycle(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//如何判断带环/快慢指针找相遇点
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
	//fast和slow都是相遇点
	//如何找到环的入口点
	//一个从起点出发head
	//一个从相遇点出发slow
	//如果两个指针相等了，环的入口点
	Node *p1 = head;
	Node *p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


//复制普通链表

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



//复杂链表的复制

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
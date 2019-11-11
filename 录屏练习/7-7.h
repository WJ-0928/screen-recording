#if 0
#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	int val;
	struct Node *next;
} Node;


/*
�ϲ�������������

����һ��������������
Node * rHead=NULL��

ͬʱ������������Ҫ�����������л��н�㣩
   ѡ��С��һ����β�嵽������rHead��

Node*c1=head1��
Node *c2=head2;

while(c1!=NULL&&c2!=NULL)
{
     if(c1->val<=c2->val)
	 {
	      //��c1β�嵽rHead��
		  c1=c1->next;
	}
	else
	{
	    //��c2β�嵽rHead��
		c2=c2->next;
	}
}

��c1β�嵽rHead��
1������Ϊ�գ�rHead==NULL��
   ԭ������һ����㶼û�У���c1β�嵽rHead��
   ��ζ��rHead������ֻ��c1һ�����
   rHeadָ��c1���ڵĽ�㣬[c1����һ����NULL�ⲽ�ǿ�ѡ��]
   rHead=c1��   c1->next=NULL;
2)����Ϊ�գ�rHead��=NULL��
   1������rHead�����һ�����last
      ��һ��������  �ӵ�һ����ʼ������
	  �ڶ���������  ��¼
	  last=c1��
	2����last����һ�������c1
	  last->next=c1;
	3����Ӱ��rHead����ĵ�һ�������˭ô������
	4��[c1����һ����NULL�ⲽ�ǿ�ѡ��]
	  c1->next=NULL;

���ѭ����������ζ���и������еĽ�㱻ȡ��
��ʣ�����������ӵ����������
*/


Node *merge(Node *head1, Node *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	Node *rHead = NULL;
	Node *cur1 = head1;
	Node *cur2 = head2;
	Node *last = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->val <= cur2->val)
		{
			Node *next = cur1->next;
			if (rHead == NULL)
			{
				rHead = cur1;
			}
			else
			{
				last->next = cur1;
			}
			last = cur1;
			cur1 = next;
		}
		else
		{
			Node *next = cur2->next;
			if (rHead == NULL)
			{
				rHead = cur2;
			}
			else
			{
				last->next = cur2;
			}
			last = cur2;
			cur2 = next;
		}
	}
	if (cur1 != NULL)
	{
		last->next = cur1;
	}
	else
	{
		last->next = cur2;
	}
	return rHead;
}




//�����м�ֵ
Node * findMiddle(Node *head)
{
	/*
	  Node *fast=head;
	  Node *slow=head;
	  while(fast!=NULL)
	  {
	      fast=fast->next;
		  if(fast==NULL)
		  {
		     break;
		  }
		  slow=slow->next;
		  fast=fast->next;
		}
		return slow;
	*/
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		count++;
	}
	Node *p = head;
	for (int i = 0; i < count / 2; i++)
	{
		p = p->next;
	}
	return p;
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

//���ģ�1->2->2->1)��ǰ����ʹӺ���ǰ����ͬ
bool chkpalindrome(Node *A)
{
	Node *middle = findMiddle(A);
	Node *result = reverseList(middle);

	Node *c1 = A;
	Node *c2 = result;

	while (c1 != NULL && c2 != NULL)
	{
		if (c1->val != c2->val)
		{
			return false;
		}
		c1 = c1->next;
		c2 = c2->next;
	}
	return true;
}


//�����������ཻ����ʼ���
/*
˼·��
1��������������ĳ���
2���ó������߼��������Ȳ
3��ͬʱ�����ߣ�ʲôʱ������ָ��ָ��ͬһ����㣬��ʾ�ҵ������
*/
int getLength(Node *head)
{
	int length = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		length++;
	}
	return length;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
	int lengthA = getLength(headA);
	int lengthB = getLength(headB);

	Node *longer = headA;//���賤�ľ���A
	Node *shorter = headB;
	int diff = lengthA - lengthB;
	if (lengthB > lengthA)
	{
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}
	//�ó����������߳��Ȳ��
	for (int i = 0; i < diff; i++)
	{
		longer = longer->next;
	}
	//��ʹû�н���㣬���longer��shorterҲ��ͬʱ�ߵ�NULL
	//����ѭ������������
	while (longer!=shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}
#endif
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
合并两个有序链表

申请一个新链表（空链）
Node * rHead=NULL；

同时遍历两个链表（要求两个链表中还有结点）
   选择小的一个，尾插到新链表rHead上

Node*c1=head1；
Node *c2=head2;

while(c1!=NULL&&c2!=NULL)
{
     if(c1->val<=c2->val)
	 {
	      //把c1尾插到rHead上
		  c1=c1->next;
	}
	else
	{
	    //把c2尾插到rHead上
		c2=c2->next;
	}
}

把c1尾插到rHead上
1）链表为空（rHead==NULL）
   原来链表一个结点都没有，把c1尾插到rHead上
   意味着rHead链表中只有c1一个结点
   rHead指向c1所在的结点，[c1的下一个是NULL这步是可选的]
   rHead=c1；   c1->next=NULL;
2)链表不为空（rHead！=NULL）
   1）手上rHead的最后一个结点last
      第一个方法：  从第一个开始遍历找
	  第二个方法：  记录
	  last=c1；
	2）让last的下一个结点变成c1
	  last->next=c1;
	3）会影响rHead链表的第一个结点是谁么？不会
	4）[c1的下一个是NULL这步是可选的]
	  c1->next=NULL;

如果循环结束，意味着有个链表中的结点被取完
把剩余链表整个接到新链表后面
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




//先求中间值
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
//逆置链表
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

//回文（1->2->2->1)从前往后和从后往前看相同
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


//找两个链表相交的起始结点
/*
思路：
1）先求两个链表的长度
2）让长度先走几步（长度差）
3）同时往后走，什么时候两个指针指向同一个结点，表示找到交叉点
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

	Node *longer = headA;//假设长的就是A
	Node *shorter = headB;
	int diff = lengthA - lengthB;
	if (lengthB > lengthA)
	{
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}
	//让长的先往后走长度差个
	for (int i = 0; i < diff; i++)
	{
		longer = longer->next;
	}
	//即使没有交叉点，最后longer和shorter也会同时走到NULL
	//导致循环条件不满足
	while (longer!=shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}
#endif
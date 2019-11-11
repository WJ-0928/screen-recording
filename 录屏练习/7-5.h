
#if 0
#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	int val;
	struct Node *next;
} Node;

//头插
Node * pushFront(Node *head, int val)
{
	//head表示链表的第一个结点，可能为NULL
	//1、先把val装到结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//2、node应该成新的第一个结点，所以原来的第一个结点
	//应该是node的下一个结点
	node->next = head;
	//3、通知函数的调用者，链表的第一个结点已经发生变化
	//从原来的的head变成node
	return node;
}

//尾插
Node *pushBack(Node *head, int val)
{
	//先把val装结点
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	//分情况处理，如果链表为空
	if (head == NULL)
	{
		//node是插入后链表中唯一的结点
		//node也就是第一个结点
		return node;
	}
	//链表不为空
	else
	{
		//先找到当前最后一个结点
		Node *cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		//cur指向链表的最后一个结点
		//让node成为最后一个结点
		//也就是让node成为cur的下一个结点
		cur->next = node;
		//链表的第一个结点没有变化
		return head;
	}
}

//反转链表
Node *reverseList(Node *head)
{
	//遍历当前链表，不断头插到新的链表中
	Node* rHead = NULL;
	//遍历
	Node *cur = head;
	while (cur!=NULL)
	{
		//先记录原来的下一个节点
		Node *next = cur->next;
		//把cur头插到rHead中
		cur->next = rHead;
		rHead = cur;
		//让cur走到下一个结点上
		cur = next;
	}
	return rHead;
}


//删除所有的val
Node *removeAll0(Node *head, int val)
{
	Node *rHead = NULL;
	Node *cur = head;
	Node *last = NULL;
	while (cur!=NULL)
	{
		Node *next = cur->next;
		if (cur->val != val)
		{
			if (rHead == NULL)
			{
				cur->next = rHead;
				rHead = cur;
			}
			else
			{
				cur->next = NULL;
				last->next = cur;
			}
			last = cur;
		}
		cur = next;
	}
	return rHead;
}


//先删除除了第一个结点外的所有含val的结点
//最后去处理第一个结点
Node *removeAll2(Node *head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}//这里对head做解引用了，所以必须保证head不为NULL
	Node *prev = head;//永远指向cur的前一个结点，用于删除cur结点
	Node *cur = head->next;//用来遍历的指针，判断是否等于val
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			//需要删除cur结点
			prev->next = cur->next;
			//如果发生了删除，prev不需要变化，因为prev还是变化后cur的前驱
		}
		else
		{
			//如果没有删除，prev和cur一起往后走
			prev = cur;
		}
		cur = cur->next;
	}
	if (head->val == val)
	{
		return head->next;
	}
	else
	{
		return head;
	}
}



//合并两个有序链表
//不断去两个链表中比较，选择较小的结点，尾插到新链表中
Node *mergeOrderList(Node *head1, Node *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	Node *rHead = NULL;//新链表的第一个结点
	Node *cur1 = head1;
	Node *cur2 = head2;
	Node *last = NULL;//新链表最后一个结点
	//保证两个链表中还有结点，才比较谁大谁小
	while (cur1 != NULL&&cur2!=NULL)
	{
		if (cur1->val <= cur2->val)
		{
			//把cur1尾插到新链表
			Node *next = cur1->next;
			cur1->next = NULL;
			//尾插需要分情况处理
			if (rHead == NULL)
			{
				cur1->next = rHead;
				rHead = cur1;
			}
			else
			{
				cur1->next = NULL;
				last->next = cur1;
			}
			//更新新链表的最后一个结点
			last = cur1;
			//让cur1指向第一个链表的下一个结点
			cur1 = next;
		}
		else 
		{
			//把cur2尾插到新链表
			Node *next = cur2->next;
			if (rHead == NULL)
			{
				cur2->next = rHead;
				rHead = cur2;
			}
			else
			{
				cur2->next = NULL;
				last->next = cur2;
			}
			//更新新链表的最后一个结点
			last = cur2;
			//让cur2指向第二个链表的下一个结点
			cur2 = next;
		}
	}
	return rHead;
}




//所有小于x的结点排在大于等于x的结点之前


Node *partition(Node *head, int x)
{
	//遍历head所代表的链表，把每个结点的值和x进行比较
	//如果小于x，尾插到一条小于x的链表中
	//如果大于等于x，尾插到一条大于等于x的链表中
	//先定义两个变量，代表小于x和大于等于x的链表

	Node *small = NULL;//小于x的链表
	Node *big = NULL;//大于等于x的链表
	//通过cur来遍历原链表的每个结点
	Node *cur = head;
	Node *slast = NULL;//小于x的链表的最后一个结点
	Node *blast = NULL;//大于等于x的链表的最后一个结点
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//把cur尾插到small中
			/*
			让cur的下一个变为NULL
			cur->next=NULL;
			分情况讨论
			如果small所在的链表是空链表
			if（small==NULL）
			      其实也就是把cur头插到small所在链表中
				  让small指向cur当前指向的结点
				  small=cur；
			如果small所在链表不是空链表
			     先找到small链表中的最后一个结点
				 1）从第一个结点遍历找到最后一个去
				 2）应为之前的最后一个结点也是我们插进去的，所以我们记录一下即可【选择】
				    slast
				让slast的下一个结点变成cur
				    slast->next=cur；

			记录新的最后一个结点是谁？刚才我们尾插的结点cur
			      slast=cur;
			最后新的最后一个结点是谁？之前最后一个结点的下一个结点
			      slast=slast->next;
			让cur指向原链表的下一个结点
			cur=cur->next;
			Node *next=cur->next;
			尾插
			cur=next；
			*/
			Node *next = cur->next;
			cur->next = NULL;
			if (small == NULL)
			{
				small = cur;
			}
			else
			{
				slast->next = cur;
			}
			slast = cur;
			cur = next;
		}
		else
		{
			//把cur尾插到big中
			Node *next = cur->next;
			cur->next = NULL;
			if (big == NULL)
			{
				big = cur;
			}
			else
			{
				blast->next = cur;
			}
			blast = cur;
			cur = next;
		}
	}

	//如果没有<x的链表怎么办？
	if (small == NULL)
	{
		return big;
	}
	else
	{
		slast->next = big;
		return small;
	}
}


//找到链表的中间结点

Node *middleNode(Node *head)
{
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


//快慢指针
Node *middleNode1(Node *head)
{
	Node *fast = head;
	Node *slow = head;
	while (fast!=NULL)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


//找到链表的倒数第k个结点

Node * FindkthToTail(Node *head,unsigned int k)
{
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		count++;
	}
	if (count >= k)
	{
		Node *p = head;
		for (int i = 0; i < count - k; i++)
		{
			p = p->next;
		}
		return p;
	}
	else
	{
		return NULL;
	}   
}



//前后指针
Node * FindkthToTail1(Node *head, unsigned int k)
{
	Node *front = head;
	Node *back = head;
	for (int i = 0; i < k; i++)
	{
		if (front == NULL)
		{
			return NULL;
		}
		front = front->next;
	}
	while (front != NULL)
	{
		front = front->next;
		back = back->next;
	}
	return back;
}



//在有序链表中，存在重复的结点，删除重复的结点
//如1->2->3->3->4->4->5 处理后为1->2->5;


Node *deleteDuplicatio(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = head;
	Node *prev = node;//前驱
	Node *p1 = head;
	Node *p2 = head->next;
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
			while (p2!=NULL&&p1->next==p2->next)
			{
				p2 = p2->next;
			}
			prev->next = p2;
			p1 = p2;
			if (p2 != NULL)
			{
				p2=p2->next;
			}
		}
	}
	return node->next;
}



Node *deleteDuplicatio1(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	Node *prev = NULL;//前驱
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
			while (p2 != NULL && p1->next == p2->next)
			{
				p2 = p2->next;
			}
			if (prev != NULL)
			{
                 prev->next = p2;
			}
			else
			{
				head = p2;
			}
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	return head;
}

#endif
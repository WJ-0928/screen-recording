
#if 0
#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	int val;
	struct Node *next;
} Node;

//ͷ��
Node * pushFront(Node *head, int val)
{
	//head��ʾ����ĵ�һ����㣬����ΪNULL
	//1���Ȱ�valװ�������
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	//2��nodeӦ�ó��µĵ�һ����㣬����ԭ���ĵ�һ�����
	//Ӧ����node����һ�����
	node->next = head;
	//3��֪ͨ�����ĵ����ߣ�����ĵ�һ������Ѿ������仯
	//��ԭ���ĵ�head���node
	return node;
}

//β��
Node *pushBack(Node *head, int val)
{
	//�Ȱ�valװ���
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	//����������������Ϊ��
	if (head == NULL)
	{
		//node�ǲ����������Ψһ�Ľ��
		//nodeҲ���ǵ�һ�����
		return node;
	}
	//����Ϊ��
	else
	{
		//���ҵ���ǰ���һ�����
		Node *cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		//curָ����������һ�����
		//��node��Ϊ���һ�����
		//Ҳ������node��Ϊcur����һ�����
		cur->next = node;
		//����ĵ�һ�����û�б仯
		return head;
	}
}

//��ת����
Node *reverseList(Node *head)
{
	//������ǰ��������ͷ�嵽�µ�������
	Node* rHead = NULL;
	//����
	Node *cur = head;
	while (cur!=NULL)
	{
		//�ȼ�¼ԭ������һ���ڵ�
		Node *next = cur->next;
		//��curͷ�嵽rHead��
		cur->next = rHead;
		rHead = cur;
		//��cur�ߵ���һ�������
		cur = next;
	}
	return rHead;
}


//ɾ�����е�val
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


//��ɾ�����˵�һ�����������к�val�Ľ��
//���ȥ�����һ�����
Node *removeAll2(Node *head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}//�����head���������ˣ����Ա��뱣֤head��ΪNULL
	Node *prev = head;//��Զָ��cur��ǰһ����㣬����ɾ��cur���
	Node *cur = head->next;//����������ָ�룬�ж��Ƿ����val
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			//��Ҫɾ��cur���
			prev->next = cur->next;
			//���������ɾ����prev����Ҫ�仯����Ϊprev���Ǳ仯��cur��ǰ��
		}
		else
		{
			//���û��ɾ����prev��curһ��������
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



//�ϲ�������������
//����ȥ���������бȽϣ�ѡ���С�Ľ�㣬β�嵽��������
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
	Node *rHead = NULL;//������ĵ�һ�����
	Node *cur1 = head1;
	Node *cur2 = head2;
	Node *last = NULL;//���������һ�����
	//��֤���������л��н�㣬�űȽ�˭��˭С
	while (cur1 != NULL&&cur2!=NULL)
	{
		if (cur1->val <= cur2->val)
		{
			//��cur1β�嵽������
			Node *next = cur1->next;
			cur1->next = NULL;
			//β����Ҫ���������
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
			//��������������һ�����
			last = cur1;
			//��cur1ָ���һ���������һ�����
			cur1 = next;
		}
		else 
		{
			//��cur2β�嵽������
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
			//��������������һ�����
			last = cur2;
			//��cur2ָ��ڶ����������һ�����
			cur2 = next;
		}
	}
	return rHead;
}




//����С��x�Ľ�����ڴ��ڵ���x�Ľ��֮ǰ


Node *partition(Node *head, int x)
{
	//����head�������������ÿ������ֵ��x���бȽ�
	//���С��x��β�嵽һ��С��x��������
	//������ڵ���x��β�嵽һ�����ڵ���x��������
	//�ȶ�����������������С��x�ʹ��ڵ���x������

	Node *small = NULL;//С��x������
	Node *big = NULL;//���ڵ���x������
	//ͨ��cur������ԭ�����ÿ�����
	Node *cur = head;
	Node *slast = NULL;//С��x����������һ�����
	Node *blast = NULL;//���ڵ���x����������һ�����
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//��curβ�嵽small��
			/*
			��cur����һ����ΪNULL
			cur->next=NULL;
			���������
			���small���ڵ������ǿ�����
			if��small==NULL��
			      ��ʵҲ���ǰ�curͷ�嵽small����������
				  ��smallָ��cur��ǰָ��Ľ��
				  small=cur��
			���small���������ǿ�����
			     ���ҵ�small�����е����һ�����
				 1���ӵ�һ���������ҵ����һ��ȥ
				 2��ӦΪ֮ǰ�����һ�����Ҳ�����ǲ��ȥ�ģ��������Ǽ�¼һ�¼��ɡ�ѡ��
				    slast
				��slast����һ�������cur
				    slast->next=cur��

			��¼�µ����һ�������˭���ղ�����β��Ľ��cur
			      slast=cur;
			����µ����һ�������˭��֮ǰ���һ��������һ�����
			      slast=slast->next;
			��curָ��ԭ�������һ�����
			cur=cur->next;
			Node *next=cur->next;
			β��
			cur=next��
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
			//��curβ�嵽big��
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

	//���û��<x��������ô�죿
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


//�ҵ�������м���

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


//����ָ��
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


//�ҵ�����ĵ�����k�����

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



//ǰ��ָ��
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



//�����������У������ظ��Ľ�㣬ɾ���ظ��Ľ��
//��1->2->3->3->4->4->5 �����Ϊ1->2->5;


Node *deleteDuplicatio(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = head;
	Node *prev = node;//ǰ��
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
	Node *prev = NULL;//ǰ��
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
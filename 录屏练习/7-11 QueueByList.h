#if 0

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct Node
{
	int val;
	struct Node *next;
} Node;

typedef struct Queue
{
	Node *front;//head
	Node *rear;//last
} Queue;


void QueueInit(Queue *q)
{
	q->front = q->rear = NULL;
}


//����
void QueuePush(Queue *q, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	if (q->front == NULL)
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}
	q->rear = node;
}

//ɾ��(��ɾ���߷�������ֵ��
int QueuePop(Queue *q)
{
	assert(q->front != NULL);

	Node *second = q->front->next;
	int val = q->front->val;
	free(q->front);
	q->front = second;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}
	return val;
}

//���ض��еĶ���Ԫ��
int QueueFront(Queue *q)
{
	assert(q->front != NULL);

	return q->front->val;
}

#endif
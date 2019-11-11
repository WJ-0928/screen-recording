#if 0

#include"6-29(1)SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_CAPACITY (16)

//����

//static��������
//���ⲿ�������Ը���Ϊ�ڲ���������
//1.static���ξֲ�������Ӱ�������������ڣ��Ӻ�����ִ�б�����������ڼ䣩
//2.static����ȫ�ֱ�����Ӱ�������������ԣ����ⲿ����ڲ���
//3.static���κ�����Ӱ�������������ԣ����ⲿ����ڲ���
//ʱ�临�Ӷ�O��n��
static void ensureCapacity(SeqList *seq)
{
	if (seq->capacity > seq->size)
	{
		//��������
		return;
	}
	//1.���·���
	//ͨ����˵��������ķ�����ԭ����1.5��2��
	int *newArray = (int *)malloc(sizeof(int)*seq->capacity * 2);
	//2.ȫ����С���
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i]=seq->array[i];
	}
	//3.�˵��Ϸ���
	free(seq->array);
	//4.������Ȧ
	seq->array = newArray;
}
//��ʼ��

void SeqListInit(SeqList *seq)
{
	//��������Ҳ���¼
	//��¼���ҵ�����
	//size=0;
	seq->array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}
//����

void SeqListDestroy(SeqList *seq)
{
	free(seq->array);
	//�������ڿɼӿɲ���
	seq->capacity = 0;
	seq->size = 0;
}
//ͷ�� O(n) 
void SeqListPushFront(SeqList *seq, int val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}
//β�� 
//O(1) ƽ��
//����������ݾ���O(n)
//���û�����ݾ���O(1)
void SeqListPushBack(SeqList *seq, int val)
{
	//�Ȳ����ǷŲ��µ�����
	seq->array[seq->size] = val;
	seq->size++;
}

//�����±�����

void SeqListInsert(SeqList *seq, int index, int val)
{
	if (index < 0 || index >= seq->size)
	{
		printf("�±겻�Ϸ�");
		return;
	}
	ensureCapacity(seq);
	for (int i = seq->size - 1; i >= index; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = val;
	seq->size++;
}

//ͷɾ
void SeqListPopFront(SeqList *seq)
{
	assert(seq->size > 0);
	for (int i =0; i <= seq->size-2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//βɾ
void SeqListPopBack(SeqList *seq)
{
	//�������úϷ��Ե�У��
	/*
	if (seq->size <= 0)
	{
		printf("�յ�\n");
		return;
	}
	*/
	assert(seq->size > 0);
	seq->size--;
}
//�����±���ɾ��
void SeqListErase(SeqList *seq, int index)
{
	assert(seq->size > 0);
	for (int i = index; i <=seq->size-2; i++) 
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//����
int SeqListFind(SeqList *seq, int val)
{
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}
//��ӡ
void SeqListPrint(SeqList *seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	 }
	printf("\n");
}

//ɾ��˳����е�һ��������val
void SeqListRemove(SeqList *seq, int val)
{
	int index = SeqListFind(seq, val);
	if (index != -1)
	{
		SeqListErase(seq, index);
	}
}


//ɾ��˳��������е�val
void SeqListRemoveAll(SeqList *seq, int val)
{
#if 0
	int index;

	//O(n^2)
	//O(n)
	while ((index = SeqListFind(seq, val)) != -1)
	{
		//O(n)
		SeqListErase(seq, index);
	}
#endif
#if 0
	//������õ�����Ŀռ䣬ʱ���Ͽ�һ��
	//�ռ临�Ӷ�O(n��
	int *extra = (int *)malloc(sizeof(int)*seq->size);
	int j = 0;
	//ʱ�临�Ӷ�O(n) 
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			extra[j++] = seq->array[i];
		}
	}
	//ɾ��֮��˳����л��ж��ٸ�����   j����
	free(seq->array);
	seq->array = extra;
	seq->size = j;
#endif
	//ʱ�临�Ӷ�O(n)  �ռ临�Ӷ�O(1)
	int j = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			seq->array[j++] = seq->array[i];
		}
	}
	seq->size = j;
}
#endif
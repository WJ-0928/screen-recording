#pragma once

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



//ð������
void  bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//�����Ѿ�������
		int ordered = 1;
		//����[size-i,size)
		//����[0,size-i)
		//ð�ݲ��֣�ֻ�����������ڽ���
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				//�����������������򲻳���
				ordered = 0;
			}
		}
		//���������Ȼ����������˳���
		if (ordered == 1)
		{
			break;
		}
	}
}


//���ֲ���
int binarySearch(int a[], int size, int value)
{
	int left = 0;//�����������߽磬�Ǹ��±�����
	int right = size - 1;//����������ұ߽磬�Ǹ��±�������
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] == value)
		{
			return mid;
		}
		else if (a[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 9,5,2,7,3,6,8,4 };
	int size = sizeof(a) / sizeof(int);
	bubbleSort(a, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");

	int index = binarySearch(a, size, 3);
	printf("3�� %d\n", index);
}
#endif
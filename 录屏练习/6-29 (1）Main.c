#if 0
#include"6-29(1)SeqList.h"

void testSeqList()
{
	//��ʼ��/����
	//��/ɾ/��/��

	SeqList seqList;//û�г�ʼ��
	//SeqListInit(seqList);������
	SeqListInit(&seqList);
	//1.��ʼ��һ������������ֵ��ֵ����û����
	//2.ָ��Ƚṹ���СҪС
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);

	SeqListPrint(&seqList);//1,2,3,4

	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPushFront(&seqList, 30);
	

	SeqListPrint(&seqList);//30,20,10,1,2,3,4

	SeqListInsert(&seqList, 3, 100);
	SeqListInsert(&seqList, 2, 200);

	SeqListPrint(&seqList);//30,20,200,10,100,1,2,3,4

	SeqListPopFront(&seqList);
	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);//200,10,100,1,2,3,4

	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);//200 ,10,100,1,2

	SeqListErase(&seqList, 1);

	SeqListPrint(&seqList);//200,100,1,2



	SeqListDestroy(&seqList);
}


int main()
{
	testSeqList();
	system("pause");
}
#endif

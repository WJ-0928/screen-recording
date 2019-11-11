#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_bf(0)
	{}


	AVLTreeNode<T>* _pLeft;//�ýڵ������
	AVLTreeNode<T>* _pRight;//�ýڵ���Һ���
	AVLTreeNode<T>* _pParent;//�ýڵ��˫��
	T _data;
	int _bf;//�ýڵ��ƽ������
};


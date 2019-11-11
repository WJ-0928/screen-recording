#pragma once

#include<iostream>
using namespace std;

template <class T>
struct BSTreeNode
{
	BSTreeNode(const T& data=T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}

	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;

};

#if 0
template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		//����---ֱ�Ӳ���
		if (nullptr == _pRoot)
			_pRoot = new Node(data);

		//�ǿ�--�Ҵ�����ڵ��ڶ����������е�λ��
		//��������˫�׽ڵ�
		Node* cur = _pRoot;
		Node* pParent = nullptr;
		while (cur)
		{
			pParent = cur;
			if (data < cur->_data)
			{
				cur = cur->_pLeft;
			}
			else if (data > cur->_data)
			{
				cur = cur->_pRight;
			}
			else
			{
				return false;
			}
		}

		//����Ԫ��
		cur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = cur;
		}
		else
		{
			pParent->_pRight = cur;
		}
		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
		{
			return false;
		}

		//�Ҵ�ɾ���ڵ��ڶ����������е�λ��
		//������˫��
		Node* cur = _pRoot;
		Node* pParent = nullptr;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data < cur->_data)
			{
				pParent = cur;
				cur = cur->_pLeft;
			}
			else if (data > cur->_data)
			{
				pParent = cur;
				cur = cur->_pRight;
			}
		}

		//�ýڵ㲻�ڶ�����������
		if (nullptr == cur)
			return false;

		//�Ѿ��ҵ��ýڵ㣬ɾ��
		//ֻ���Һ���||Ҷ�ӽڵ�
		if (nullptr = cur->_pLeft)
		{
			if (nullptr == pParent)
				return false;
			else
			{
				if (cur == pParent->_pLeft)
					pParent->_pLeft = cur->_pRight;
				else
					pParent->_pRight = cur->_pRight;
			}
		}
		else if (nullptr == cur->_pRight)
		{
			//ֻ������
			if (nullptr == pParent)
				return false;
			else
			{
				if (cur == pParent->_pLeft)
					pParent->_pLeft = cur->_pLeft;
				else
					pParent->_pRight = cur->_pLeft;
			}
		}
		else
		{
			//���Һ��Ӷ�����
			Node* pDelNode = cur->_pRight;
			pParent = cur;
			//������ڵ㣺��������������С
			while (pDelNode->_pLeft)
			{
				pParent = pDelNode;
				pDelNode = pDelNode->_pLeft;
			}
			//������ڵ��е�ֵ���滻ɾ���ڵ�
			cur->_data = pDelNode->_data;

			if (pDelNode == pParent->_pLeft)
				pParent->_pLeft = pDelNode->_pRight;
			else
				pParent->_pRight = pDelNode->_pRight;

			cur = pDelNode;
		}
		delete cur;
		return true;

	}
	//��ѯ
	Node* Find(const T& data)
	{
		Node* cur = _pRoot;
		while (cur)
		{
			if (data == cur->_data)
			{
				return cur;
			}
			else if (data < cur->_data)
			{
				cur = cur->_pLeft;
			}
			else
			{
				cur = cur->_pRight;
			}
		}
		return nullptr;
	}
	//��Сֵ
	Node* leftMost()
	{
		if (nullptr == _pRoot)
		{
			return nullptr;
		}
		Node* cur = _pRoot;
		while (cur->_pLeft)
			cur = cur->_pLeft;
		return cur;
	}

	//���ֵ
	Node* rightMost()
	{
		if (nullptr == _pRoot)
		{
			return nullptr;
		}
		Node* cur = _pRoot;
		while (cur->_pRight)
		{
			cur = cur->_pRight;
		}
		return cur;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	//�������
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	Node* _pRoot;
};



void TestBSTree()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> bst;
	for (auto e : a)
		bst.Insert(e);

	cout << bst.leftMost()->_data << endl;
	cout << bst.rightMost()->_data << endl;
	bst.InOrder();
}
#endif

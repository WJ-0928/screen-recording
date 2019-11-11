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
		//空树---直接插入
		if (nullptr == _pRoot)
			_pRoot = new Node(data);

		//非空--找待插入节点在二叉搜索树中的位置
		//并保存其双亲节点
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

		//插入元素
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

		//找待删除节点在二叉搜索树中的位置
		//保存其双亲
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

		//该节点不在二叉搜索树中
		if (nullptr == cur)
			return false;

		//已经找到该节点，删除
		//只有右孩子||叶子节点
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
			//只有左孩子
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
			//左右孩子都存在
			Node* pDelNode = cur->_pRight;
			pParent = cur;
			//找替代节点：在右子树中找最小
			while (pDelNode->_pLeft)
			{
				pParent = pDelNode;
				pDelNode = pDelNode->_pLeft;
			}
			//用替代节点中的值域替换删除节点
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
	//查询
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
	//最小值
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

	//最大值
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
	//中序遍历
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

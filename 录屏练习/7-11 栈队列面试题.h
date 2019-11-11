#if 0

#pragma once
#include<stdio.h>
#include<cstring>
#include<stack>


//�ж��ַ����Ƿ���Ч������ƥ������
class solution
{
public:
	bool isValid(string s)
	{
		std::stack<char>     s;
		int size = str.size();
		for (int i = 0; i < size; i++)
		{
			char ch = str[i];
			switch (ch)
			{
			case'(': case'[':case'{':
				s.push(ch);//��ջ
				break;
			case')':case']':case'}':
			{
				if (s.empty())
				{
					return false;
				}
				char left = s.top();
				s.pop();
				if (!((left == '('&&ch == ')')
					|| (left == '['&&ch == ']')
					|| (left == '{'&&ch == '}')))
				{
					return false;
				}
				break;
			}
			default:
				break;
			}
		}
	if (!s.empty())//ջ��Ϊ��
	{
		return false;
	}
	return true;
 	}
	
};



//�ö���ʵ��ջ

/*
ѹջ
    ���ݽ�����
��ջ
     �����Ȱ�ǰ��n-1)�����ݴӶ��н����У����ѵ�ǰ�������ݳ�ȥ
�鿴ջ��Ԫ��
       ���Ȱ�n-1....��׼�����ؾ��Ƕ���Ԫ�أ�����Ԫ�س����������
�ж�ջ�Ƿ�Ϊ��
      ���п�
*/

class Mystack
{
	std::queue<int>    q;
public:
	Mystack() {}
	void push(int x) { q.push(x); }//��ջ��ѹջ
	int pop()//��ջ
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.ftont();
			q.pop();
			q.push(v);
		}
		int v = q.front;
		q.pop();
		return v;
	}
	int top()//�鿴ջ��Ԫ��
	{
		int n = q.size();
		for (int i = 0; i < n - 1; i++)
		{
			int v = q.ftont();
			q.pop();
			q.push(v);
		}
		int v = q.front;
		q.pop();
		q.push(v);//ֻ��һ�۲���ջ
		return v;

	}
	bool empty()//�ж�ջ�Ƿ�Ϊ��
	{
		return q.empty();//����Ϊ�գ�ջ��Ϊ��
	}
};



//��ջʵ�ֶ���

class MyQueue
{
	std::stack<int>  in;
	std::stack<int>  out;
public:
	MyQueue(){}
	void push(int x)
	{
		in.push(x);
	}
	int pop()
	{
		if (out.empty())
		{
			int n = in.size();
			for (int i = 0; i < n; i++)
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		out.pop();
		return v;
	}
	int peek()
	{
		if (out.empty())
		{
			while (!in.empty())
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		return v;
	}
	bool empty()
	{
		return in.empty() && out.empty();
	}
 };
#endif
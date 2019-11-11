
#include<iostream>
using namespace std;

#include<string>
#include<map>


#if 0
int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("����", "������"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("�����", "ĸҹ��"));

	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.insert(make_pair("����", "��ţ"));
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;

	cout << m["�ν�"] << endl;
	cout << m["����"] << endl;
	m["³��"] = "������";
}
#endif

#if 0
//����key����
int main()
{
	map<int, int> m;
	int array[] = { 5,1,0,9,7,3,6,4,2,8 };
	for (size_t i = 0; i < 10; ++i)
	{
		m.insert(make_pair(array[i], i));
	}
	for (auto e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
}
#endif

#if 0
int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m.insert(make_pair("�����", "ĸҹ��"));

	cout << m.count("�ν�") << endl;
	cout << m.count("³��") << endl;

	auto it = m.find("�ν�");

	//���һ��Ҫ�ģ���ɾ����key�������²���
	pair<string, string> data("����", it->second);
	if (it != m.end())
		m.erase(it);

	m.insert(data);

	m.clear();
	return 0;
}
#endif


#if 0
#include<functional>

int main()
{
	//map�е�Ԫ��Ĭ�ϰ���less(С��)��ʽ���бȽ�--����
	map<int, int> m1;
	int array[] = { 5,1,0,9,7,3,6,4,2,8 };
	for (int i = 0; i < 10; ++i)
	{
		m1.insert(make_pair(array[i], i));
	}

	for (auto e : m1)
		cout << e.first << "---->" << e.second << endl;

	map<int, int, greater<int>> m2;
	for (int i = 0; i < 10; ++i)
	{
		m2.insert(make_pair(array[i], i));
	}

	for (auto e : m2)
		cout << e.first << "---->" << e.second << endl;
	return 0;
}
#endif

#if 0
#include<set>
int main()
{
	int array[] = { 5,2,9,0,8,1,7,3,6,4,5,2,9,0,8,1,7,3,6,4 };
	set<int> s;
	for (auto e : array)
		s.insert(e);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
#include<set>
int main()
{
	int array[] = { 5,2,9,0,8,1,7,3,6,4,5,2,9,0,8,1,7,3,6,4 };
	multiset<int> s;
	for (auto e : array)
		s.insert(e);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
#endif
#if 0
#include"BSTree.h"
int main()
{
	TestBSTree();
	return 0;
}
#endif



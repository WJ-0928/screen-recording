//#include<string>
//#include<iostream>
//using namespace std;

#if 0
int main()
{
	string s1;//构造空的string类对象，即空字符串
	string s2("hello");//用C-string来构造string类对象
	string s3(10, '$');//string类对象中包含n个字符C
	string s4(s2);//拷贝构造函数

	//string类支持C++标准的输入输出
	cin >> s1;
	cout << s1 << endl;
	
	//遍历字符串的方式
	for (auto e : s2)
	{
		cout << e;//e拿到每一个字符
	}
	cout << endl;

	//下标的方式遍历
	for (int i = 0; i < s3.size(); ++i)
	{
		cout << s3[i];
	}
	cout << endl;

	//采用迭代器遍历------很少用
	//迭代器：当成是一种指针
	//string类中 :[begin,end)---begin：代表首字符的位置   end：最后一个有效字符得下一个位置
	string::iterator it = s4.begin();
	while (it != s4.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}
#endif


#if 0
//capacity相关

int main()
{
	string s("hello");
	cout << s.size() << endl;//有效字符个数
	cout << s.length() << endl;//有效字符个数
	cout << s.capacity() << endl;//容量

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	if (s.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" <<endl;
	}
	system("pause");
	return 0;
}
#endif

#if 0
//void resize(size_t n,char ch):将string类中有效字符改到n个，多出的位置用ch填充
//resize功能：改变string类中有效字符的个数，在改变有效字符时，可能需要扩容
//将有效字符个数增多到n个：多出的位置需要使用ch进行填充（可能需要扩容）
//将有效字符个数减少到n个：只修改有效字符的个数，不会缩小空间
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//扩增有效字符的个数
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '$');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//减少有效字符的个数
	s.resize(18);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif

#if 0
//扩容：
//void reserve(size_t n):改变低层容量的大小，不会修改有效元素的个数
//1、扩大容量：n<=旧空间                不会扩容   
//             n>旧空间大小             扩容
//2、缩小容量：n>最初默认空间大小       不会缩小
//             n<=最初默认空间大小      缩小容量
int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(80);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(60);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(16);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(8);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s1;
	s1.resize(10, '$');
	s1[0] = '%';

	string s2;//里面没有元素
	s2.reserve(10);
	s2[0] = '%';

	return 0;
}
#endif

#if 0
int main()
{
	string s("hello");
	cout << s << endl;

	reverse(s.begin(),s.end());//逆转
	cout << s << endl;

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s1;
	s1 += 'I';

	string s2(" Love");
	s1 += s2;

	s1 += " china ";

	string s3(" too ");
	s1.append(s3);
	s1.append("!!!");
	s1.append(6, '.');

	cout << s1 << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();    
	cout << "making s grow:\n";    
	for (int i = 0; i < 100; ++i) 
	{ 
		s.push_back('c');        
		if (sz != s.capacity()) 
		{ 
			sz = s.capacity();            
			cout << "capacity changed: " << sz << '\n';
		} 
	}
	return 0;
}
#endif

#if 0
int main()
{
	string s("IYOU");
	s.insert(1," LOVE ");
	cout << s << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s("hello wrold");
	s.erase(s.begin() + s.find(' '), s.end());
	cout << s << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s("111.txt");
	string ret=s.substr(s.rfind('.')+1);
	cout << ret << endl;

	string strNet("https://Users.com/ADMIN/Documents/C");
	size_t pos = strNet.find(':') + 3;
	if (pos != string::npos)
	{
		cout << "is in" << endl;
	}
	else
	{
		cout << "is not in" << endl;
	}
	size_t len = strNet.find(pos, '/') - pos;
	strNet.substr(pos,len);
	cout << ret << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	string s2("Hello");
	if (s1 > s2)
	{
		cout << s1 << endl;
	}
	else
	{
		cout << s2 << endl;
	}
	return 0;
}
#endif

#if 0
//深拷贝：每个对象都有独立的资源，拷贝的是资源中的内容
//如果一个类中涉及到资源管理：用户必须显示提供拷贝构造函数和赋值运算符重载
class String
{
public:
	String(const char* str = "")//构造
	{
		/*
		if (nullptr == str)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		*/
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}
		return *this;
	}
		
		
	~String()//析构
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);

	//系统提供的默认的赋值运算符重载：1、浅拷贝  2、资源泄漏
	String s3("world");
	s3 = s2;
}
int main()
{
	TestString();
	return 0;
}
#endif

#if 0
//深拷贝
class String
{
public:
	String(const char* str = " ")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	
	String(const String& s)
		:_str(nullptr)
	{
		String strTtemp(s._str);//创建临时对象
		swap(_str, strTtemp._str);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif

#if 0

#include<assert.h>
namespace bite
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = " ")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_size = strlen(str);
			_str = new char(_size + 1);
			strcpy(_str, str);
			_capacity = _size;
		}

		//拷贝构造
		string(const string& s)
			:_size(s._size)
			,_capacity(s._size)
		{
			_str = new char[_size + 1];
			strcpy(_str, s._str);
		}
		string(size_t n, char ch)
			:_str(new char[n + 1])
			,_size(n)
			,_capacity(n)
		{
			memset(_str, ch, _size);
			_str[_size] = '\0';
		}

		//拷贝构造赋值运算符重载
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* str = new char[s._size + 1];
				strcpy(str, s._str);
				delete[] _str;
				_str = str;
				_size = s._size;
				_capacity = _size;
			}
		}
		//析构
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		///////////////////////////////////////////////////////////
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

	    ///////////////////////////////////////////////////////////
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return 0 == _size;
		}

		void resize(size_t newSize, char ch=char())
		{
			size_t oldsize = _size;
			if(newSize>oldsize)
			{
				if (newSize > _capacity)
				{
					reserve(_capacity);
				}
				memset(_str + _size, ch, newSize - oldsize);
			}
			_size = newSize;
			_str[_size] = '\0';
		}

		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				//开辟新空间
				char* str = new char[newcapacity + 1];
				//拷贝元素
				strcpy(str, _str);
				//释放旧空间
				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}
	    ///////////////////////////////////////////////////////////////
		//任意位置元素访问
		char operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		//////////////////////////////////////////////////////
		string& operator+=(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}
		string& operator+=(char* str)
		{
			size_t len = strlen(str);
			size_t newsize = len + size();
			if (capacity() < newsize)
			{
				reserve(newsize);
			}
			strcat(_str, str);
			_size = newsize;
			return *this;
		}
		string& operator+=(const string& s)//+=类类型对象
		{
			*this += s._str;
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity); 
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t find(char ch)
		{
			for (int i = 0; i < size(); ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t rfind(char ch)
		{
			for (int i = _size - 1; i >= 0; --i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		string substr(size_t pos = 0, size_t n = npos)
		{
			if (n == npos)
			{
				n = size() - pos;
			}
			string strRet;//先构造一个空的
			strRet.reserve(n);
			strcpy(strRet._str, _str + pos);
			strRet._size = n;
			strRet._str[n] = '\0';

			return strRet;
		}

		friend ostream& operator<<(ostream& _cout,const string& s)
		{
			_cout << s.c_str();
			return _cout;
		}

		/*bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);*/

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		static size_t npos;
	};

	size_t string::npos = 0;
}
int main()
{
	bite::string s1;
	bite::string s2("hello");
	bite::string s3(10, 'a');
	bite::string s4(s2);

	for (int i = 0; i < s2.size();++i)
	{
		cout << s2[i];
	}
	cout << endl;

	auto it = s3.begin();
	while (it != s3.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	for (auto e : s4)
	{
		cout << e;
	}
	cout << endl;
	return 0;
}

#endif

#if 0
namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector();
		vector(size_t n,const T& data);

		template<class Iterator>
		vector(Iterator first, Iterator last);
		vector(const vector<T>& v);

		/////////////////////////////////////////////
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		/////////////////////////////////////////////////////
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}

		void resize(size_t newSize, const T& data = T)
		{
			size_t oldsize = size();
			if (newSize <= oldsize)
			{
				_finish = _start + newSize;
			}
			else
			{
				size_t cap = capacity();
				if (newSize > cap)
				{
					reserve(newSize);
				}
				for (int i = oldsize; i < newSize；++i)
				{
					*_finish++ = data;
				}
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* ptemp = new T[newcapacity];

				if (_start)
				{
					for (size_t i = 0; i < size(); ++i)
					{
						ptemp[i] = _start[i];
					}
					delete[] _start;
					_start = ptemp;
					_finish = _start + size();
					_endofstorage = _start + newcapacity;
				}
			}
		}
		//////////////////////////////////////////////
		T& operator[](size_t index)
		{
			assert(index < size);
			return _start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < size);
			return _start[index];
		}

		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}

		/////////////////////////////////////
		void push_back(const T& data)
		{
			if (size() == capacity())
			{
				reserve(2 * capacity());
			}
			*_finish++ = data;
		}
		void pop_back()
		{
			--_finish;
		}


		void clear()
		{
			_finish = _start;
		}
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}

int main()
{
	return 0;
}


#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

void Sort(int L[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (L[j] % 2 == 0 && L[j + 1] % 2 != 0)
			{
				int temp = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int L[] = { 4,3,4,8,5,1,2,9,7,6 };
	Sort(L, sizeof(L) / sizeof(L[0]));
	for (int i = 0; i < sizeof(L) / sizeof(L[0]); ++i)
	{
		printf("%d ", L[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

#endif
#if 0
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}

void deletenode(Node* b)
{
	Node* cur = b;
	Node* cur1 = NULL;
	while (1)
	{
		if (cur->next == b)
		{
			cur1 = cur;
		}
		cur = cur->next;
	}
	cur = b;
	while (cur->next!=cur1)
	{
		cur = cur->next;
	}
	cur->next = b;

}

int main()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n1;

	Node* s = n1;
	deletenode(s);
	return 0;
}
#endif
#include<stdio.h>
#include<stdlib.h>
void Sort(int L[], int len)
{
	int *p1, *p2, tmp;//采用俩个指针
	p1 = L;//分别指向第一个位置，和最后一个位置，

	p2 = L + len - 1;
	while (p1 < p2)
		//当前面的第一个指针遇到了偶数，并且后面一个指针遇到了奇数，那么就把这俩个指针指向的位置进行交换数据。优点是不用单独声明一个数组。
	{
		if ((*p1 % 2 == 1)) //奇数
		{
			p1++;
			continue;
		}
		if (*p2 % 2 == 0)
		{
			p2--;
			continue;
		}
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;


	}
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d", L[i]);
	}
}
int main()
{
	int L[] = { 1,2,3,5,4,7 };
	int len;
	len = sizeof(L) / sizeof(int);
	Sort(L, len);
	system("pause");
	return 0;
}

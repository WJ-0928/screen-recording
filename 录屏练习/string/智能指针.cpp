#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#if 0
//Ϊʲô������ָ���ԭ��
void Test1()
{
	throw 1;
}
bool Test2()
{
	return false;
}
//ȱ�ݣ���Func()������;�����˳���λ�ã������ͷſռ��Լ��ر��ļ�ָ��

void Func()
{
	int* p = new int[10];
	FILE* pf = fopen("444.txt", "rb");
	if (pf == nullptr)
	{
		delete[] p;
		return;
	}
	try
	{
		Test1();
	}
	catch (...)
	{
		delete[] p;
		fclose(pf);
		throw;
	}
	if (!Test2())
	{
		delete[] p;
		fclose(pf);
		return;
	}
	fclose(pf);
	delete[] p;
}

int main()
{
	return 0;
}

#endif


//ʲô���ڴ�й¶��
//�ڴ�й¶��Σ��
//�ڴ�й©�ļ��
//C++�����Ԥ���ڴ�й©��----����ָ��


#if 0

//RAII:����ָ��

class A
{
public:
	A(int n)
		:_ptr(new int[n])
	{}
	~A()
	{
		if (_ptr)
		{
			delete[] _ptr;
		}
	}

protected:
	int* _ptr;
};
void TestFunc()
{
	int *p = new int;
	A a(1);
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
//��һ�������ԭ��ָ̬��
//RAII
//���ƣ��û�����Ҫ���ĺ�ʱȥ�ͷ���Դ
//ȱ�ݣ�ǳ����---���ܲ�������ķ�ʽ���

//String����Դ�����Լ������

//Smartptr���Թ�����Դ����Դ���û�����
template<class T>
class Smartptr
{
public:
	Smartptr(T* ptr)
		:_ptr(ptr)
	{
		cout << "Smartptr()" << endl;
	}

	~Smartptr()
	{
		cout << "~Smartptr()" << endl;
		if (_ptr)
		{
			delete _ptr;
		}
	}

	//�ø���Ķ������ָ�����Ƶ���Ϊ
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

protected:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestFunc1()
{
	Smartptr<int> sp1(new int);
	*sp1 = 100;

	Smartptr<A> sp2(new A);
	sp2->a = 10;
	sp2->b = 20;
	sp2->c = 30;
}

//�����ǳ����������
void TestFunc2()
{
	Smartptr<int> sp1(new int);
	Smartptr<int> sp2(sp1);
}

int main()
{
	TestFunc2();
	return 0;
}
#endif

#if 0
//����ָ��---Smartptr��������ǳ��������
//����ָ��ԭ��RAII+������������ָ�����Ϊ(operator*()/operator->())+���ǳ����
//C++98�汾---auto_ptr�����ǳ������ʽ--->��Դ��ת��

namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//ap2(ap1);
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//ap1=ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	protected:
		T* _ptr;
	};
}

void TestFunc()
{
	//����ָ��
	int a = 10;
	int* p1 = &a;
	int* p2(p1);

	*p1 = 100;
	*p2 = 200;

	bite::auto_ptr<int> ap1(new int);

	//�����ʽ������Դת��
	bite::auto_ptr<int> ap2(ap1);
	//*ap1 = 10;//�����--ap1�ѽ���Դת�Ƹ�ap2���Լ�����Դ�Ͽ���ϰ
	*ap2 = 20;

	bite::auto_ptr<int> ap3(new int);

	ap3 = ap2;
}
int main()
{
	TestFunc();
	return 0;
}

#endif
#if 0

//�Ľ���auto_ptr
//ԭ��RAII+����ָ��������Ϊ+���ǳ��������ԭ����Ȩ��ת�ƣ�����Դ�ͷŵ�Ȩ����
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_owner(false)
		{
			if (_ptr)
				_owner = true;
		}

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			,_owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//�ȴ�����ǰ����Դ
				if (_ptr&&_owner)
					delete _ptr;

				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	protected:
		T* _ptr;
		mutable bool _owner;//��Դ������ӵ���ߣ�����Դ�����ͷ�Ȩ���Ķ���
	};
}

void TestFunc()
{
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);
	bite::auto_ptr<int> ap3;
	ap3 = ap2;

	*ap1 = 10;
	*ap2 = 20;
	*ap3 = 30;
}

int main()
{
	TestFunc();
	return 0;
}

//C++��׼�⽨�飺ʲô����£�����Ҫʹ��auto_ptr
#endif
#if 0

//����ָ��ԭ��ARII+����ָ��������Ϊ+���ǳ����
//unique_ptr:��Դ��ռ�ķ�ʽ��һ����Դֻ�ܱ�һ���������
//��ʽ����ֹ��������͸�ֵ��������ص���---������
//ȱ�ݣ����unique_ptr�Ķ���䲻�ܹ�����Դ

namespace bite
{
	template<class T>
	class unique_ptr
	{
	public:
		//RAII
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//��ֹ������--��ֹ���ÿ�������&��ֵ���������

#if 0

		//����һ��C++98��ֻ���������� &private
	private:
		unique_ptr(const unique_ptr<T>& up);
		unique_ptr<T>& operator =(const unique_ptr<T>& up);
#endif
		//��������C++11������:delete
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator =(const unique_ptr<T>& up) = delete;
	protected:
		T* _ptr;
	};
}

void TestFunc()
{
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);
	bite::unique_ptr<int> up2;
	//up2=up1;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

//shared_ptr��RAII+ָ�����Ƶ���Ϊ+���ü���

#if 0

//����������������
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_count(0)
		{
			if (_ptr)
				_count = 1;
		}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_count(++sp._count)
		{}
		
		~shared_ptr()
		{
			if (_ptr && 0 == --_count)
			{
				delete _ptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	protected:
		T* _ptr;
		int _count;
	};
}
#endif

#if 0
//���ü�������̬�ĳ�Ա����
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{
			if (_ptr)
				_count = 1;
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			_count++;
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --_count)
			{
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	protected:
		T* _ptr;
		static int _count;
	};

	template<class T>
	int shared_ptr<T>::_count = 0;
}
#endif

#if 0
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _count(nullptr)
		{
			if (_ptr)
				_count = new int(1);
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _count(sp._count)
		{
			if (_count)
				++*_count;
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//�õ�ǰ��������Դ�Ͽ�
				Release();

				//��sp����
				_ptr = sp._ptr;
				_count = sp._count;
				if (_count)
					++*(_count);
			}
			return *this;
		}

		~shared_ptr()
		{
			Release();
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_count;
		}
	private:
		void Release()
		{
			if (_ptr && 0 == --*_count)
			{
				delete _ptr;
				delete _count;

			}
		}
	protected:
		T* _ptr;
		int* _count;
	};
}
void TestSharedPtr()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	bite::shared_ptr<int> sp3(new int);
	bite::shared_ptr<int> sp4(sp3);

	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp1;
	cout << sp1.use_count() << endl;

	sp4 = sp1;
	cout << sp1.use_count() << endl;
}

int main()
{
	TestSharedPtr();
	return 0;
}

#endif

#if 0

#include <mutex>

// 1. �����̰߳�ȫ
// 2. ֻ�ܹ���new����Դ
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(nullptr)
		{
			if (_ptr)
			{
				_pMutex = new mutex;
				_pCount = new int(1);
			}
		}

		// shared_ptr<int> sp2(sp1);
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			if (_pCount)
				AddRef();
		}

		// sp1  sp2(sp1);
		// sp3  sp4(sp3);
		// sp3 = sp1;
		// sp4 = sp1;
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// �õ�ǰ��������Դ�Ͽ�
				Release();

				// ��sp����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_pCount)
					AddRef();
			}

			return *this;
		}

		~shared_ptr()
		{
			Release();
		}

		// ����ָ��������Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		int SubRef()
		{
			_pMutex->lock();
			--(*_pCount);
			_pMutex->unlock();

			return *_pCount;
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				delete _ptr;
				delete _pCount;
			}
		}
	protected:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;  // ��֤�����İ�ȫ��
	};
}

// mutex: ���Ա�֤�����İ�ȫ�� || ���Ա�֤shared_ptr�౾��İ�ȫ��
//        �����ܱ�֤shared_ptr������Դ�����ݵİ�ȫ��
struct A
{
	A()
		: a(0)
		, b(0)
		, c(0)
	{}

	int a;
	int b;
	int c;
};


void TestThread(bite::shared_ptr<A>& sp, int N)
{
	for (size_t i = 0; i < N; ++i)
	{
		sp->a++;
		sp->b++;
		sp->c++;
	}
}



#include <thread>
int main()
{
	bite::shared_ptr<A> sp(new A);
	thread t1(TestThread, sp, 100000);
	thread t2(TestThread, sp, 100000);

	t1.join();
	t2.join();
	return 0;
}
#endif

#if 0

//����ɾ����
template<class T>
class DelRef
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};


class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};
#include<mutex>

//ֻ�ܹ���new����Դ
namespace bite
{
	template<class T, class DF = DelRef<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(nullptr)
		{
			if (_ptr)
			{
				_pMutex = new mutex;
				_pCount = new int(1);
			}
		}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			if (_pCount)
				AddRef();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// �õ�ǰ��������Դ�Ͽ�
				Release();

				// ��sp����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_pCount)
					AddRef();
			}

			return *this;
		}

		~shared_ptr()
		{
			Release();
		}

		// ����ָ��������Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		int SubRef()
		{
			_pMutex->lock();
			--(*_pCount);
			_pMutex->unlock();

			return *_pCount;
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				// �û���Դ��ȷ���ͷŷ�ʽ��Ӧ�ø�����Դ������
				//delete _ptr;
				DF d;
				d(_ptr);
				delete _pCount;
			}
		}
	protected:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;  // ��֤�����İ�ȫ��
	};
}

void TestFunc()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	//bite::shared_ptr<FILE, FClose> sp3(fopen("1.txt", "rb"));
}

int main()
{
	TestFunc();
	return 0;
}

#endif

#if 0
//shared_ptrȱ�ݣ�����ѭ����������
#include<memory>

struct ListNode
{
	ListNode(int d)
		:next(nullptr)
		, pre(nullptr)
		, data(d)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}
	shared_ptr<ListNode> next;
	shared_ptr<ListNode> pre;
	int data;
};

void TestFunc()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0

// ѭ�����õĽ����ʽ��weak_ptr
#include <memory>

struct ListNode
{
	//ListNode* next;
	//ListNode* pre;

	ListNode(int d)
		: data(d)
		// 	: next(nullptr)
		// 	, pre(nullptr)
		// 	, data(d)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}

	//shared_ptr<ListNode> next;
	//shared_ptr<ListNode> pre;
	weak_ptr<ListNode> next;
	weak_ptr<ListNode> pre;

	int data;
};

void TestList()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	// weak_ptr<int> wp(new int); // ���뱨��weak_ptr�����ܶ���������Դ
	TestList();
	return 0;
}
#endif



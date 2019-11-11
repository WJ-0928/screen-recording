#include<iostream>

using namespace std;


#if 0
//智能指针：管理指针，自动去释放资源

//RAII+就有指针行为（*、->)
template<class T>
class Smartptr
{
public:
	Smartptr(T* ptr=nullptr)
		:_ptr(ptr)
	{}
	~Smartptr()
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

struct A
{
	int a;
	int b;
	int c;
};
void TestFunc()
{
	Smartptr<int> sp1(new int);
	*sp1 = 20;
	Smartptr<A> sp2(new A);
	sp2->a = 1;
	sp2->b = 2;
	sp2->c = 3;
}
int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
//C++98

namespace bite
{
	//1、通过RAII的方式管理指针
	//2、具有像指针的行为：解引用、->
	//3、解决浅拷贝问题: 深拷贝（不行）

	//auto：资源转移
	//C++标准库建议：什么情况下，都不要用auto_ptr
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (_ptr)
					delete _ptr;

				_ptr = sp._ptr;
				sp._ptr =nullptr;
			}
			return *this;
		}
		~auto_ptr()
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
	private:
		T* _ptr;
	};
}
void TestFunc()
{
	bite::auto_ptr<int> sp1(new int);
	bite::auto_ptr<int> sp2(sp1);

	sp1 = sp2;
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
namespace bite
{
	//资源管理权的转移
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

		auto_ptr<T>& opeartor=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
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
				delete _ptr;
		}
		T& operator* ()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		mutable bool _owner;
	};
}

void Testfun()
{
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
}
int main()
{
	Testfun();
	return 0;
}
#endif

#include<iostream>
using namespace std;

#if 0
void Testfun()
{
	FILE* f = fopen("666.txt", "rb");
	if (NULL == f)
	{
		cout << 1;
	}
	fclose(f);
}

int main()
{
	try 
	{
		Testfun();
	}
	catch (int)
	{
		cout << "open file flase" << endl;
	}
}
#endif

#if 0
//栈展开
double Division(int a, int b)
{
	if (b == 0)
	{
		throw"Division by zero condition!";
	}
	else
	{
		return ((double)a / (double)b);
	}
}

void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
	return 0;
}
#endif

#if 0
//异常的重新抛出
double Division(int a, int b)
{
	if (b == 0)
	{
		throw"Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete[]" << array << endl;
		delete[] array;
		throw;
	}

	cout << "delete[]" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
#endif

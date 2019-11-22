#include<iostream>
#include<functional>

void foo(int &a)
{
	++a;
}

void foo2(const int& a)
{
	std::cout << "a = " << a << "\n";
}

void test_function(std::function<void(void)> func)
{
	func();
}

int main()
{
	int a = 1;
	using namespace std;
	cout << "init1=" << a << endl;
	test_function(std::bind(foo, a));
	cout << "init2=" << a << endl;
	test_function(std::bind(foo, std::ref(a)));
	cout << "init3=" << a << endl;
	test_function(std::bind(foo2, a));
	cout << "init4=" << a << endl;
	test_function(std::bind(foo2, std::cref(a)));
	return 0;
}

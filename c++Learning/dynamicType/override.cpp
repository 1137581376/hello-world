#include<iostream>


class A {
public:
	virtual void print(int a) { std::cout << "A::print()\n"; }
};
class B : public A {
public:
	void print(int a) { std::cout << "B::print()\n"; }
};

int main()
{
	using namespace std;

	B b;
	A& a = b;
	a.print(10);
	//b.A::print();
	return 0;
}

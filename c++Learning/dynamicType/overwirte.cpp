#include<iostream>


class A {
public:
	void print(int a, int b) { std::cout << "A::print()\n"; }
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
	a.print(10, 20);
	//b.A::print();
	return 0;
}

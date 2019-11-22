#include<iostream>


class A {
public:
	virtual void print(int a) { std::cout << "A::print()\n"; }
};
class B : public A {
public:
	void print(int a) override { std::cout << "B::print()\n"; }
	void print(int a, int b) {std::cout << "B::print(int, int)\n";}
};

int main()
{
	using namespace std;

	B b;
	A& a = b;
	b.print(10);
	b.print(10, 20);
	std::cout << sizeof(A) << std::endl;
	//b.A::print();
	return 0;
}

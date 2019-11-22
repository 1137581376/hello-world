#include<iostream>
struct AA{
	int a[11];
};
struct A{
	long a;
	struct AA c;
	char b;
};
int main()
{
	std::cout << sizeof(struct A) << std::endl;
	return 0;
}

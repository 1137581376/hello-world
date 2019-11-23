#include<iostream>
#include "my_string.hpp"

int main()
{
	my_string a("hello world");
	std::cout << a << std::endl;
	my_string b(a);
	std::cout << a << "\t" << b << std::endl;
	my_string b1(std::move(a));
	std::cout << a << "\t" << b1 << std::endl;
	my_string c = b;
	std::cout << c + b << std::endl;
	c += b;
	std::cout << c << std::endl;
	return 0;
}

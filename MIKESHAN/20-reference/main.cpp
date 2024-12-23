#include <iostream>

int main()
{
	int x = 32;
	int& ref = x;
	int* p = nullptr;
	int*& ref2 = p;//引用空指针是不合法的，编译期会警告
	std::cout << "x value    :" << x << std::endl;
	std::cout << "x address  :" << &x << std::endl;
	std::cout << "x type     :" << typeid(x).name() << std::endl; 
	ref = 999;

	std::cout << "x value:" << x << std::endl;
	std::cout << "ref address" << &ref << std::endl;
}

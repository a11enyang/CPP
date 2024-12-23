#include <iostream>
void foo()
{
}

int main()
{
	int x = 32;
	float y = 1.0;
	char a = 'a';
	signed char b = 'b';
	unsigned char c = 'c';

	std::cout << "x address:" << &(x) << std::endl;
	std::cout << "y address:" << &(y) << std::endl;
	std::cout << "a address:" <<(void*) &(a) << std::endl;
	std::cout << "b address:" << (void*)&(b) << std::endl;// 获取变量的地址时，将&符号作为一个函数看待，所以将变量作为参数穿进去
	std::cout << "c address:" << (void*)&(c) << std::endl;
	std::cout << "function foo address:" << (viod*)&foo << std::endl;
	std::cout << "function main address:" << (void*)&main << std::endl;
	return 0;
}

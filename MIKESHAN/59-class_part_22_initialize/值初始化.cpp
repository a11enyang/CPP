#include <codecvt>
#include <iostream>
#include <string>

struct Other
{
	Other() 
	{
		std::cout << "Other 默认构造函数 \n";
	}
};

struct Base 
{
	Base() 
	{
		std::cout << "Base 默认构造函数 \n";
	}

	int age = 20;
	std::string name = "123";
	Other other;
};

int main()
{
	Base b;
	std::cout << b.name << std::endl;
}

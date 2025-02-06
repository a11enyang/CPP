#include <iostream>
#include <string>
class Base
{
private:
	int age;
	std::string name;
public:
	Base()
       	{
		std::cout << "默认构造函数 \n";
	}
};


int main()
{
	Base b;
}

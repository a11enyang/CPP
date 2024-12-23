#include <algorithm>
#include <iostream>
#include <memory>
class UDT
{
public:
	UDT() 
	{
		std::cout << "调用构造函数" << std::endl;
	}

	~UDT()
	{
		std:: cout << "调用析构函数" << std::endl;
	}
};



int main()
{
	std::unique_ptr<UDT> u_ptr = std::unique_ptr<UDT>(new UDT);
	
	return 0;
}

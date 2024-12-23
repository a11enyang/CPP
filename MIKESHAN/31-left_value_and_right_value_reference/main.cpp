#include <iostream>
#include <string>
#include <utility>
std::string createString()
{
	return "临时字符串";
}

int main()
{
	int&& r_ref = 10;
	std::cout << r_ref << std::endl;
	std::string&& str = createString();
	std::string str_2 = std::move(str);
	std::cout << str_2 << std::endl;
	return 0;
}


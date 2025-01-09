#include <iostream>
#include <string>

void print(const char* param)
{
	std::cout << param << '\n';
}


int main()
{
	std::string name = "ywdyangweidong";
	std::cout << name.size() << '\n';
	std::cout << name.length() << '\n';
	std::cout << name.capacity() << '\n';

	for (auto& e: name)
	{
		std::cout << e << '\n';
	}

	std::basic_string<char> str("123456");
	std::cout << str << '\n';

	std::cout << name.find("yang", 0, 2) << '\n';

	const char* company = "lenovo";
	std::cout << company << std::endl;
	print(company);
}

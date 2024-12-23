#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::string s1 = " 字符串内容";
	std::string s2 = "";

	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;

	s2 = std::move(s1);
        std::cout << "s1:" << s1 << std::endl;
   	std::cout << "s2:" << s2 << std::endl;
}

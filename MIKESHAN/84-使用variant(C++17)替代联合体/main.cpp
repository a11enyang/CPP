#include <iostream>
#include <variant>

int main()
{
	std::variant<int, char> s = 1000;
	std::cout <<  std::get<char>(s);

}

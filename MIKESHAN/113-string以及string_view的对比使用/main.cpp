#include <iostream>
#include <string>
#include <string_view>

void changeStr(std::string_view str)
{
	std::cout << str << '\n';
}


int main()
{
	const char * name = "yangweidong";
	changeStr(name);


}

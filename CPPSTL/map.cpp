#include <iostream>
#include <map>
#include <utility>
// map: key只会出现一次， value是有顺序的

void print_map(std::string_view comment, std::map<std::string, int>& map)
{
	std::cout << comment << '\n';
	for (auto& e: map)
	{
		std::cout << '[' << e.first << ']' << '=' << 
	}
}




int main() 
{
	// 初始化
	std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
	
}

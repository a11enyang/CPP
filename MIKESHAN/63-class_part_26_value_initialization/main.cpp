#include <iostream>
#include <string>

struct Entity
{
	std::string name;
	int x;
	int y;
};

int main()
{
	Entity e{"yangweidong", 1, 2};
	Entity t{};//采用了聚合初始化
	std::cout << e.name << std::endl;
	std::cout << e.x << std::endl;
	std::cout << e.y << std::endl;
}

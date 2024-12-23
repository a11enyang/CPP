#include <functional>
#include <iostream>

int add(int x, int y)
{
	std::cout << "x+y=" << x+y << std::endl;
	return x+y;
}


int main()
{
	std::function<int(int, int)> op;
	op = add;
	op(2, 3);
	return 0;
}

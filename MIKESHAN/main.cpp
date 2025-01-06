#include <iostream>

void foo()
{
	std::cout << "停止" << std::endl;
}

template <typename T, typename... Args>
void foo(T first, Args... args)
{
	std::cout << first << std::endl;
	foo(args...);
}

int main()
{
	foo(1, 2, 4, 5, 6);
}

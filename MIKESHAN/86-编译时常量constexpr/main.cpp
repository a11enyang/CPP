#include <iostream>

constexpr int add(int a, int b)
{
	return a+b;
}

int main()
{
	constexpr int c = add(1, 3);
	std::cout << c << std::endl;


	int array[c];
}

#include <iostream>

template <typename T1, size_t N>
void foo(T1 number)
{
	for (size_t i = 0; i < N; i++)
	{
		std::cout << number << std::endl;
	}
}


int main()
{
	foo<int, 5>(3);
}

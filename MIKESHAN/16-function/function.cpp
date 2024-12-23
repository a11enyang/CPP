#include <iostream>

auto add(int, int) -> int;
auto add(float, float) -> float;

int main()
{
	int a = 1;
	int b = 4;
	int sum1 = add(a, b);
	
	float f1 = 10.0;
	float f2 = 12.0;
	float f3 = add(f1, f2);
	return 0;
}

int add(int a, int b)
{
	std::cout << "a+b=" << std::endl;
	return a + b;
}

float add(float a, float b)
{
	return a +b;
}

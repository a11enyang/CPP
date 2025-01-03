#include <iostream>

template <typename T>
T square(T x)
{
	return x*x;
}

int main()
{
	std::cout << square(5) << "\n";
	std::cout << square<int>(5.5) << "\n";
	std::cout << square(5.6) << "\n";

}

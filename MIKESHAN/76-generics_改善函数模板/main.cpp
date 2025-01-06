#include <iostream>

template <typename T>
auto multiple(const T& a, const T& b) -> decltype(a*b)//decltype是c++11才需要的，C++14是可以只使用auto这一个关键字的
{
	return a * b;
}

int main()
{
	std::cout << multiple<float>(3.1, 2.2) << std::endl;
	return 0;
}

#include <iostream>

template <typename T1, typename T2>
bool equal(T1 n1, T2 n2)
{
	return (n1 == n2);
}

template<>
bool equal(const char* str1, const char* str2)
{
	return !std::strcmp(str1, str2);
}

int main()
{
	std::cout << "equal(1, 2):" << equal(1, 2) << std::endl;
	std::cout << "equal(abc,abc):" << equal("abc", "abc") << std::endl;
	return 0;
}

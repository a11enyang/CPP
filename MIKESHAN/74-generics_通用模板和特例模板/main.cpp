#include <iostream>

// 函数模板的通用模板
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

// 函数模板的特例模板
template<>
bool equal<float, float>(float n1, float n2)
{
	std::cout << "函数模板特化:";
       	return false;
}

template<typename T>
class Container
{
public:
	Container(T param) 
	{
		std::cout << param << std::endl;
	}

};

template<>
class Container<std::string>
{
public:
	Container(std::string param)
	{
		std::cout << "std::string:" << param << std::endl;
	}
};

int main()
{
	std::cout << "equal(1, 2):" << equal(1, 2) << std::endl;
	std::cout << "equal(abc,abc):" << equal("abc", "abc") << std::endl;
	std::cout << "equal(1.0f,2.0f):" << equal(1.0f, 2.0f) << std::endl;
	
	Container c(100);
	Container c2(std::string("123"));
	return 0;
}

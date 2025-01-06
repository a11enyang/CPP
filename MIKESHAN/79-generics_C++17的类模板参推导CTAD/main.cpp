#include <iostream>

template <typename first, typename second>
class MyClass
{
public:
	MyClass(first f, second s): f(f), s(s)
	{
	
	}

	first f;
	second s;	
};

int main()
{
	MyClass<int, int> obj(2, 3); // C++14的写法，需要显式指明类模板参数
	MyClass obj2(1, 1);			     // C++17可通过编译器自动推导
}

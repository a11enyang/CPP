//委托构造函数是C++11 引入的特性，允许一个构造函数调用同一个类中的另一个构造函数，从而避免代码重复并且简化初始化逻辑
//委托构造函数的语法很简单，只需要在构造函数的初始化列表中调用另一个构造函数即可

#include <iostream>

class MyClass
{
	public:
		MyClass(int x): value(x)//主构造函数
		{
			std::cout << "主构造函数 \n";
		}

		MyClass() : MyClass(0)
		{
			std::cout << "委托构造函数 \n";
		}
	private:
		int value;
};


int main()
{
	MyClass obj;
}

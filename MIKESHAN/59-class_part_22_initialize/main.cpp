#include <initializer_list>
#include <iostream>

class MyClass
{
	public:
		MyClass(std::initializer_list<int> list)
		{
			for (auto& e: list)
			{
				std::cout << e << std::endl;
			}
		}

};

int main()
{
	int x = 1;//先创建一个临时对象，然后再调用赋值运算符
	int y(2);//直接调用构造函数
	//int z{3.0};//调用初始化成员列表，不允许窄化转换
	MyClass mc{1, 2, 4};
	MyClass mc2({1, 2, 4});
}

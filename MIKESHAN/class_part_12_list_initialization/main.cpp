#include <iostream>

//防止单参数构造函数被隐式调用

class MyClass
{
public:
	explicit MyClass(int x): x(x)
	{
	}
	
private:
	int x;
};

void printValue(const MyClass& obj)
{
}


int main()
{	
	//printf(4.3);//避免单参数的构造函数被隐式调用，这种会出现编译错误
	
	//MyClass obj1 = 4;//先进行隐式类进行转换创建一个临时对象，然后调用拷贝构造函数创建创建
	MyClass obj2{4.1};//列表初始化，不允许窄化转换，例如 double 到 int
	MyClass obj3(4);//直接初始化，允许窄化转换
	return 0;
}

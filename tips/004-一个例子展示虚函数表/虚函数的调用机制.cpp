#include <iostream>

class Base
{
public:
	Base() {}
	~Base() {}
	virtual void showName()
	{
		std::cout << "Base() \n";
	}
};

class Derived: public Base
{
public:
	Derived() {}
	~Derived() {}
	virtual void onlyDerived() 
	{
		std::cout << "Derived 独有 \n";
	}
	virtual void showName()
	{
		std::cout << "Derived() \n";
	}
};

int main() 
{
	Base* ptr = new Derived();
	ptr->showName();
}

/**
 *当执行 ptr->showName() 时：
 *编译器通过 ptr 找到对象的 vptr， 通过vptr找到Derived类的虚函数，在虚函数表中查找showName()函数的条目（索引为1）, 然后再调用子类中的showName函数
 *+-------------------+
 *| vptr              |  --> 指向 Derived 的虚函数表
  +-------------------+
  | Base 子对象数据   |
  +-------------------+
  | Derived 数据      |
 *+-------------------+
 
 vtable for Derived:
[0]: Derived::~Derived()  // 析构函数
[1]: Derived::showName()  // 重写的 showName 函数
 *
 *
 * 如果子类中没有重写父类的虚函数，那么直接使用父类的虚函数内容
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **/

/**
 *虚函数表是C++实现动态多态的机制。每个包含虚函数的类都有一个虚函数表，其中存储了虚函数的地址。当调用虚函数时，程序会通过对象的虚函数表查找正确的函数地址。

如果 memFunc() 是虚函数：

Base 类的虚函数表会存储 Base::memFunc() 的地址。

Derived 类的虚函数表会存储 Derived::memFunc() 的地址。

当通过 Base* 调用 memFunc() 时，程序会查找实际对象（Derived 对象）的虚函数表，并调用 Derived::memFunc()。

如果 memFunc() 不是虚函数：

没有虚函数表，编译器直接根据指针类型（Base*）调用 Base::memFunc()
 *
 *
 *
 **/


#include <iostream>

class Base
{
	public:
		Base()
		{
			std::cout << "Base() 构造函数 \n";
		}

		virtual ~Base()//如果基类的析构函数没有被声明为虚函数，那么编译器会根据指针的类型静态调用指针对应的类的析构函数。如果声明为虚函数，那么就是动态绑定，会先调用基类的析构，然后再调用子类的析构
		{
			std::cout << "Base() 析构函数 \n";
		}

		virtual void memFunc()//没有加virtual的时候，函数调用是静态绑定，是根据指针的类型。有virtual时，是动态绑定，会根据实际对象的类型决定调用哪个函数
		{
			std::cout << "Base::menFunc() \n";
		}//父类是虚函数，那么子类继承了也是虚函数，只是子类函数可以不用virtual显式标明
};

class Derived: public Base
{
	public:
		Derived()
		{
			std::cout << "Derived() 构造函数 \n";
		}

		~Derived()
		{
			std::cout << "Derived() 析构函数 \n";
		}

		
		virtual void memFunc() override
		{
			std::cout << "Derived::memFunc() \n";
		}
		

};

int main()
{
	Base* instantce = new Derived();
	instantce->Base::memFunc();
	instantce->memFunc();
	delete instantce;
}

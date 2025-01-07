#include <iostream>

class Base {};
class Derived: public Base {};

int main()
{
	int a = 0;
	double b = static_cast<double>(a);// 1 适合基本类型的转换
	
	Derived obj;
	Base* obj22 = static_cast<Base*>(&obj);//2 适合子类指针向父类指针的转换
	
	int c = 10;// 3 适合 void* 指针的转换
	void* v = static_cast<void*>(&c); // int* -> void*
	int* p = static_cast<int*>(v);    // void* -> int*
}

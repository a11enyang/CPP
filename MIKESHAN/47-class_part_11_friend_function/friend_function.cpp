#include <iostream>
#include <ostream>

//友元函数经常用于运算符重载
class MyClass
{
public:
	MyClass(int x): x(x)
	{
	}

	
	friend std::ostream& operator<<(std::ostream& , MyClass& );
private:
	friend MyClass add(const MyClass& a, const MyClass &b);
	int x;
};


std::ostream& operator<<(std::ostream& os, MyClass& obj)
{
	os << obj.x;
	return os;
}



//友元函数也可以用于非成员工具类
MyClass add(const MyClass&a , const MyClass &b)
{
	return MyClass(a.x+b.x);
}

int main()
{
	MyClass obj(1);
	std::cout << obj << '\n';

	MyClass obj2(2);
	MyClass obj3(3);
	MyClass obj5 = add(obj2, obj3);
	std::cout << obj5 << '\n';
}

#include <iostream>

class Base
{
private:
	std::string m_privateBase;
protected:
	std::string m_protectedBase;
public:
	std::string m_publicBase;

	Base(): m_privateBase("m_privateBase"), m_protectedBase("m_privateBase"), m_publicBase("m_publicBase")
	{
	}
};

class Derived: public Base
{
public:
	Derived()//不能在子类的初始化成员列表中对父类的成员进行初始化，只能在函数体中进行赋值，因为成员变量初始化都是构造函数的责任
	{
		m_publicBase = "m_publicBaseDerived";
	}
};


int main()
{
	Derived derived;
	
	derived.m_publicBase = "1";
	//derived.m_protectedBase = "2";//错误，保护成员变量不能在类外访问
}

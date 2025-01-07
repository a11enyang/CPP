// static_cast
// 1 基本类型的转换
// 2 子类指针向基类指针的转换
// 3 void* 指针的转换
//
// dynamic_cast
// 基类指针向子类指针的转换
#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;
    virtual void Print() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
public:
    void Print() override { std::cout << "Derived" << std::endl; }
    void SpecialMethod() { std::cout << "Special Method in Derived" << std::endl; }
};


int main()
{
	Base* obj = new Derived();
	obj->Print();
	Derived* derived = dynamic_cast<Derived*>(obj);
	derived->SpecialMethod();
}

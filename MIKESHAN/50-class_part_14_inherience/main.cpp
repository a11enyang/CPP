#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base 构造函数 \n";
	}

	~Base()
	{
		std::cout << "Base 析构函数 \n";
	}

	int m_base_public;

protected:
	int m_base_protected;

private:
	int m_base_private;

};

class Derived_Public: public Base
{
public:
	Derived_Public()
	{
		std::cout << "Derived_Public 构造函数 \n";
	}

	~Derived_Public()
	{
		std::cout << "Derived_Public 析构函数 \n";
	}

	void print()
	{
		std::cout << m_base_public << "," << m_base_protected << std::endl;
	}
};

class Derived_Protected: protected Base
{
public:
	Derived_Protected()
	{
		std::cout << "Derived_Protected 构造函数 \n";
	}

	~Derived_Protected()
	{
		std::cout << "Derived_Protected 析构函数 \n";
	}

	void print()
	{
		std::cout << m_base_public << "," << m_base_protected << std::endl;
	}
};

int main()
{
	Derived_Public son;
	son.print();
	Derived_Public son2;
	son2.print();
}





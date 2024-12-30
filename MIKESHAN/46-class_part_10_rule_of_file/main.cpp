//如果一个类需要显式定义以下五个特殊成员函数中的任何一个，那么很可能需要显式定义所有五个：
//析构函数
//复制构造函数
//复制赋值运算符
//移动构造函数
//移动赋值运算符
#include <iostream>
#include <cstring>
class MyClass
{
public:
	//构造函数
	MyClass(const char* str) 
	{
		size = std::strlen(str);
		data = new char[size + 1];
		std::strcpy(data, str);
		std::cout << "调用构造函数,创建" << str << std::endl;
	}

	//析构函数
	~MyClass()
	{
		std::cout << "调用析构函数,删除" << data << std::endl;
		delete[] data;
	}

	//拷贝构造函数
	MyClass(const MyClass& other): size(other.size)
	{
		data = new char[size + 1];
		std::strcpy(data, other.data);
		std::cout << "调用复制构造函数, from" << other.data << std::endl;
	}

	//赋值运算符
	MyClass& operator=(const MyClass& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] data;
		size = other.size;
		data = new char[size + 1];
		std::strcpy(data, other.data);
		std::cout << "调用赋值运算符,from" << other.data << std::endl;

		return *this;
	}

	//移动构造函数
	MyClass(MyClass&& other) : size(other.size), data(other.data)
	{
		std::cout << "调用移动构造函数,from" << other.data << std::endl;
		other.size = 0;
		other.data = nullptr;
	}

	//移动赋值运算符	
	MyClass& operator=(MyClass&& other)
	{
		std::cout << "调用移动赋值构造函数, from" << other.data << std::endl;
		if (this == &other)
		{
			return *this;
		}
		delete[] data;
		size = other.size;
		data = other.data;

		other.data = nullptr;
		other.size = 0;
		
		return *this;
	
	}

	void print() const
	{
		std::cout << "data: " << (data ? data : "nullptr") << std::endl;
	}
private:
	size_t size;
	char* data;

};

void printData(MyClass obj)
{
	obj.print();
}

void printData2(MyClass& obj)
{
	obj.print();
}


void printData3(MyClass&& obj)//以右值引用的方式作为入参，并不会进行复制
{
	obj.print();
}

MyClass makeNewOne()//会被编译器进行返回值优化，导致返回的临时对象不会调用复制构造函数
{
	MyClass one("new one");
	return one;
}

int main()
{
	//调用复制构造函数
	std::cout << "=======复制构造函数 \n";
	MyClass obj1("Hello");
	printData(obj1);	
	
	std::cout << "=======引用的方式 \n";
	//采用引用的方式
	printData2(obj1);
	
	std::cout << "=========移动语义的方式 \n";

	printData(std::move(obj1));//调用移动构造函数
	printData3(std::move(obj1));//传递右值引用
	obj1.print();

	std::cout << "==========\n";
	MyClass newOne = makeNewOne();
	return 0;
}

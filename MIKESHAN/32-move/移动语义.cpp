#include <iostream>
#include <utility>

class Resource
{
private:
	int* data;
	size_t size;
public:
	Resource() : data(nullptr), size(0) 
	{
		std::cout << "默认构造函数" << std::endl;
	}

	// 参数化构造函数
	Resource(size_t s) : size(s)
	{
		data = new int[s];
		std::cout << "参数化构造函数, s:" << s << std::endl;
	}

	// 移动构造函数
	Resource(Resource&& other) noexcept : data(other.data), size(other.size)
	{
		other.data = nullptr;
		other.size = 0;
		std::cout << "移动构造函数" << std::endl;
	}

	// 移动赋值运算符
	Resource& operator=(Resource&& other) noexcept
	{
		if (this == &other)
		{
			return *this;
		}

		data = other.data;
		size = other.size;
		other.data = nullptr;
		other.size = 0;
		std::cout << "移动赋值运算符" << std::endl;
		return *this;
	}

	~Resource() 
	{
		delete[] data;
		std::cout << "析构函数" << std::endl;
	}

	void print() const
	{
		std::cout << "Resource, size: " << size << std::endl;
	}
};

Resource takeResource(Resource&& resource)// resource是一个右值引用，表示可以绑定到一个右值
{
	resource.print();
	return std::move(resource);// resource在函数中还是一个左值，虽然是右值引用的类型，所以需要使用move将其转换为右值从而触发移动构造函数和移动赋值运算符
}

int main()
{
	Resource res(5);
	Resource newRes{};
       	newRes = takeResource(std::move(res));
	
	res.print();
	newRes.print();
}

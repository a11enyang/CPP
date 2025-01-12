//RAII的核心思想
//将资源的获取与对象的初始化绑定
//将资源的释放与对象的析构绑定

#include <algorithm>
#include <iostream>

class Collection
{
public:
	Collection(int size): size(size)
	{
		std::cout << "构造函数 \n";
		data = new int[size];
	}	

	~Collection()
	{
		delete[] data;
	}

	Collection(const Collection& other): size(other.size)
	{
		std::cout << "复制构造函数 \n";
		data = new int[size];
		std::copy(other.data, other.data + size, data);
	}

	Collection& operator=(const Collection& other)
	{
		std::cout << "赋值运算符重载 \n";
		if (this == &other)
		{
			return *this;
		}

		delete[] data;
		size = other.size;
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		return *this;
	}

	int& getValueByIndex(std::size_t index) const
	{
		return data[index];
	}

	void setValueByIndex(std::size_t index, int value)
	{
		data[index] = value;	
	}


	int& operator[] (std::size_t index)
	{
		return data[index];
	}

	const int& operator[] (const::size_t index) const
	{
		return data[index];
	}
private:
	int* data;
	int size;
};

int main()
{
	std::cout << "Collection c1(1); \n";
	Collection c1(1);
	std::cout << "c1[0] = 2 \n";
	c1[0] = 2;
	std::cout << c1[0] << '\n';

	std::cout << "Collection c2(1) \n";
	Collection c2(1);
	std::cout << "c2 = c1 \n";
	c2 = c1;
	std::cout << c2[0] << '\n';
	return 0;
}


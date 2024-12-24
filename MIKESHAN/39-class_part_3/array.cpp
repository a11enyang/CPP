#include <algorithm>
#include <iostream>

class Array
{
public:
	Array(int size): size(size)
	{
		data = new int[size];
		std::cout << "构造函数 \n";
	}

	Array(const Array& other): size(other.size)
	{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		std::cout << "复制构造函数 \n";
	}

	Array& operator=(const Array& other)
	{
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

	~Array()
	{
		delete[] data;
		std::cout << "析构函数 \n";
	}
private:
	int *data;
	int size;

};

int main()
{
	Array arr(20);
	

}

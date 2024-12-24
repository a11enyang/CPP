#include <iostream>

class ShallowCopy
{
public:
	ShallowCopy(int size): size(size)
	{
		data = new int[size];
	}

	//默认的浅拷贝构造函数
	ShallowCopy(const ShallowCopy& other): size(other.size), data(other.data)
	{
		std::cout << "浅拷贝" << std::endl;
	}

private:
	int* data;
	int size;

};


class DeepCopy
{
public:
	DeepCopy(int size): size(size)
	{
		data = new int[size];
	}

	//默认的浅拷贝构造函数
	DeepCopy(const DeepCopy& other): size(other.size)
	{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		std::cout << "浅拷贝" << std::endl;
	}

private:
	int* data;
	int size;

};



#include <iostream>

class ShallowCopy
{
public:
	ShallowCopy(int size): size(size)
	{
		data = new int[size];
	}

	//浅拷贝构造函数，浅拷贝只会复制int、float、数组的地址（但是不会复制数组的内容，但是如果是静态数组，两个指针都会指向同一个内存）
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

	//深拷贝构造函数
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



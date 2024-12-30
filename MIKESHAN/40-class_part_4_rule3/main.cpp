//三个法则：
//	如果类需要显示定义析构函数、复制构造函数、赋值运算符中的任何一个。那么它很可能需要显式定义所有的三个。
//
//大两法：
//	如果类中的所有资源都由智能指针或其他RAII对象(std::ifstream std::ofstream std::ftream std::lock_guard std::unique_lock std::scoped_lock std::thread)管理，则析构函数可以由编译器自动生成，程序员只需要显式定义复制构造函数和赋值运算符。

//如果需要手动创建构造函数，那么应该也应该手动编写析构函数、复制构造函数、赋值运算符
#include <iostream>
#include <vector>

class Array
{
public:
	Array(int number)
	{
		for (auto& element: numbers)
		{
			element = number;
		}
	}
		
	void printArray() const 
	{
		for (auto& element: numbers)
		{
			std::cout << element << std::endl;
		}
	}

private:
	int numbers[10];
};


class MyVector
{
public:
	MyVector()
	{
		for (int i = 0; i < 10; i++)
		{
			nums.push_back(i);
		}	
	}

	MyVector(const MyVector& other)
	{
		for (int i = 0; i < other.nums.size(); i++)
		{
			nums.push_back(other.nums.size());
		}
	}

	MyVector& operator=(const MyVector& other)
	{
		if (this == &other)
		{
			return *this;
		}
		
		nums.clear();
		for (int i = 0; i < other.nums.size(); i++)
		{
			nums.push_back(other.nums.size());
		}
		return *this;
	}

private:
	std::vector<int> nums;
};

int main()
{
	Array arr1(1);
	Array arr2(2);
	arr1.printArray();
	arr2.printArray();
	arr2 = arr1;
	arr2.printArray();

	std::cout << "MyVector=== \n";
	MyVector v1;
	MyVector v2(v1);

}

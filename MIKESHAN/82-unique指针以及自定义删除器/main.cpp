#include <memory>
#include <iostream>


template <typename T>//通用模板
struct DeleteUniquePtr
{
	void operator() (T* ptr)
	{
		std::cout << "通用模板: 删除唯一指针 \n";
		delete ptr;
	}

};

template <typename T>//模板特化
struct DeleteUniquePtr<T[]>
{
	void operator() (T* ptr)
	{
		std::cout << "模板特化: 删除唯一指针 \n";
		delete[] ptr;
	}
};


int main()
{
	std::unique_ptr<int, DeleteUniquePtr<int[]>> ptr(new int[2]);
	std::unique_ptr<int, DeleteUniquePtr<int>> ptr2(new int);
}


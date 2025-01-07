// functor，仿函数，通过创建类，然后重载operator()运算符模拟函数的操作
// 普通函数是一次性的，无法保存状态信息的。但是仿函数可以，因为仿函数其实是一个类。
#include <algorithm>
#include <iostream>
#include <vector>

class Addr
{
	public:
		Addr(int value): sum(value)
		{
		}


		int operator() (int value)
		{
			sum += value;
			return sum;
		}

	private:
		int sum;
};

class Compare
{
	public:
		bool operator() (const int& a, const int& b)
		{
			return a>b ? true: false;
		}
};
int main()
{
	Addr add(10);
	std::cout << add(5) << std::endl;
	std::cout << add(1) << std::endl;

	std::vector<int> vec = {10, 3, 5, 7, 2, 0};
	std::sort(vec.begin(), vec.end(), Compare());
	for (auto& e: vec)
	{
		std::cout << e << '\n';
	}
}

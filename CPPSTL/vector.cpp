// vector数组，长度可变的数组
#include <algorithm>
#include <iostream>
#include <vector>


template <typename T>
void forPrint(std::vector<T>& v)
{
	std::for_each(v.begin(), v.end(), [] (T n) {std::cout << n << ", ";});
	std::cout << '\n';
}

int main()
{
	// 初始化
	std::cout << "初始化 \n";
	std::vector<int> vec(2, 0);// vector <类型> vec(长度，初值);
	
	std::vector<std::vector<int>> dp(5, std::vector<int> (6, 10));// 5行 6列的二维数组
	std::vector<std::vector<std::vector<int>>> dp2(5, std::vector<std::vector<int>> (6, std::vector<int> (7, 1)));//5行 6列 7层的三维数组

	std::vector<std::vector<int>> vec2(10, std::vector<int> (11, 0));// 10行  11列数组，初始值为0
	
	// 尾增
	std::cout << "尾增 \n";
	std::vector<int> arr(5, 0);
	arr.push_back(1);
	forPrint(arr);
	// 尾删
	std::cout << "尾删 \n";
	arr.pop_back();
	arr.pop_back();
	forPrint(arr);
	// 获得数组的长度
	std::cout << "获得数组长度 \n";
	std::cout << arr.size() << std::endl;

	// 清空和判空数组
	std::cout << "清空和判空数组 \n";
	arr.clear();
	if (arr.empty()) {std::cout << "数组已清空 \n";}

	// 更改数组长度  resize(长度，新值)
	std::cout << "更改数组长度 \n";
	std::vector<int> v(5, 0);
	v.resize(10, 3); 
	forPrint(v);

	v.resize(3, 12);// 改短会直接删除
	forPrint(v);	


	
}

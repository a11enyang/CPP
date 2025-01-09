// 集合 set：提供对数时间的插入、删除、查找
// 确定性、互异性、无序性


#include <algorithm>
#include <iostream>
#include <set>

// set: 元素只会出现一次；元素是有序的
// multiset: 元素可以出现多次；元素是有序的
// unordered_set: 元素只可以出现一次；元素是无序的

int main() 
{

	// ================ set 集合	
	// set集合
	int data[] = {1, 33, 100, 44, 1};
	std::set<int> s(data, data+5);
	std::for_each(s.begin(), s.end(), [] (int n) {std::cout << n << ", ";} );	

	// 查找元素
	if (s.end() != s.find(101))
	{
		std::cout << "找到对应元素 \n";
	}

	// 删除对应元素
	s.erase(100);

	// 清空和判空
	//s.clear();
	std::cout << s.empty() << '\n';

	// 查看对应的元素有多少个
	std::cout << s.count(33) << '\n';
	std::cout << s.count(-1) << '\n';
	
	// 使用迭代器进行遍历
	for (std::set<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		std::cout << *i << std::endl;
	}


	// ================multiset
	int data1[] = {11, 22, 33, 66, 44, 66};
	std::multiset<int> ms(data1, data1+6);
	
	// 遍历
	for (std::multiset<int>::iterator i = ms.begin(); i != ms.end(); i++)
	{
		std::cout << *i << ' ';
	}
	std::cout << '\n';

	//  查找
	std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> p = ms.equal_range(66);
	for (std::multiset<int>::iterator i = p.first; i != p.second; i++)
	{
		std::cout << *i << " ";
	}
	std::cout << '\n';

	// 清除
	ms.erase(p.first, p.second);
	for (std::multiset<int>::iterator i = ms.begin(); i != ms.end(); i++)
	{	
		std::cout << *i << ' ';
	}
}

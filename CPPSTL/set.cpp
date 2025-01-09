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
	// set集合
	std::set<int> s;
	
	// 插入元素
	s.insert(1);
	s.insert(33);
	s.insert(100);
	s.insert(44);
	s.insert(1);//元素重合了是不会放进集合中的
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
	
}

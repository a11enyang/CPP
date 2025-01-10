
// 序列化容器：vector  dequeue  list  forward_list array
// 关联容器：map  set  multiset multimap
// 无序容器：unordered_set   unordered_map
#include <deque>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);


	std::cout << vec[2]; // 没有范围检查
	std::cout << vec.at(2); // 超出范围会抛出range_error的异常
	
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	for (auto& it: vec)
	{
		std::cout << it << " ";
	}

	int* p = &vec[0];//vec数组是分配的连续内存
	
	std::vector<int> vec2(vec);
	vec.clear();
	if (vec.empty() ) {}
	
	vec2.swap(vec);



	std::deque<int> 	
}

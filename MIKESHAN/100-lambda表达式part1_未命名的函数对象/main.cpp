// 仿函数是一个函数对象
// lambda表达式是一个匿名的函数对象
// [捕获] (参数) {函数体}

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {1, 2 ,3 ,4 ,5 ,6};
	std::for_each(v.begin(), v.end(), [] (int& n) {std::cout << n << ',';});

}

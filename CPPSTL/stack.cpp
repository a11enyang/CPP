#include <iostream>
#include <stack>
#include <vector>

int main()
{
	//初始化
	std::stack<int> stk;
	
	//入栈
	stk.push(1);
	stk.push(2);

	//查看栈顶
	std::cout << stk.top() << '\n';

	//出栈
	stk.pop();
	std::cout << stk.top() << '\n';

	//查看栈内数据的size
	std::cout << stk.size() << '\n';

	//判空
	while(stk.size() != 0)
	{
		stk.pop();
	}
	std::cout << stk.empty() << '\n';


	//可以使用vector数组作为栈使用
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	std::cout << v.back() << std::endl;
	std::cout << v.front() << std::endl;
}

#include <iostream>
#include <thread>
#include <vector>

int main()
{
	auto test=[](int x)
	{
		std::cout << "入参的值：" << x << std::endl;
		std::cout << "线程的 id: " << std::this_thread::get_id() << std::endl;
	};

	std::vector<std::jthread> jthread_collection;//jthread 会在析构函数的时候自动调用 join
	for(int i = 0; i < 10; i++)
	{
		jthread_collection.push_back(std::jthread(test, i));
	}

	return 0;
}

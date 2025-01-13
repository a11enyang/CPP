#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

static int x = 0;
std::mutex gLock;
void add()
{
	std::lock_guard<std::mutex> lockGuard(gLock);// 离开作用域后，会调用析构函数将锁释放
	try {
		x++;
		throw "excetion";
	}
	catch(...)
	{
		std::cout << "catch exception" << std::endl;
		return;
	}
}

int main ()
{

	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread(add));
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}
	std::cout << "x 的值：" << x << std::endl;
	return 0;
}

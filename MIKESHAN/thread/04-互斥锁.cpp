#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int count = 0;
std::mutex gLock;
int main()
{
	auto test=[]()
	{
		std::cout << "线程 id: " << std::this_thread::get_id() << std::endl;
		gLock.lock();//互斥锁，因为没有用到条件变量，所以线程会不断去访问锁是否释放
		count++;
		gLock.unlock();
	};

	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread(test));
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	std::cout << "最后的结果: " << count << std::endl;
	return 0;
}

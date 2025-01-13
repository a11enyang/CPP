#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
int main()
{
	auto test=[](int x)
	{
		std::cout << "子线程 id: " << std::this_thread::get_id() << std::endl;
		std::cout << "传入的参数: " << x << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	};

	std::vector<std::thread> thread_colleciton;
	for (int i = 0; i < 10; i++)
	{
		thread_colleciton.push_back(std::thread(test, i));
		//thread_colleciton[i].join();//只有等到每个线程执行完成之后才会进行下一次循环
	}

	for (auto& element: thread_colleciton)//如果不加上引用类型，那么就会调用  thread 的默认构造函数
	{
		element.join();
	}
	return 0;
}

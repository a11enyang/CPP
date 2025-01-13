#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main()
{
	int result = 0;
	bool notified = false;
	//报告线程
	std::thread repoter([&] {
		std::unique_lock<std::mutex> lock(gLock);
		while (!notified)//避免虚假唤醒，如果工作线程还没有执行的时候就被
				 //虚假唤醒，此时 notified 还为 false，这样可以进入
				 //函数内部进行阻塞
				 //
				 //还有就是逻辑更清晰，表示notified 为 false 的时候就应该阻塞

		{
			gConditionVariable.wait(lock);
		}
		std::cout << "result is " << result << std::endl;
	});


	//工作线程
	std::thread  worker([&] {
			std::unique_lock<std::mutex> lock(gLock);
			result = 50;
			notified = true;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			gConditionVariable.notify_one();	
	});

	worker.join();
	repoter.join();
	std::cout << "主线程完成" << std::endl;
}

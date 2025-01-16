#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main()
{
	int result = 0;
	bool isWorkerThreadDone = false;
	//报告线程
	std::thread repoter([&] {
		std::unique_lock<std::mutex> lock(gLock);// 执行期间上锁，执行结束后自动解锁，一个线程持有锁的时候，另一个线程就会阻塞
		while (!isWorkerThreadDone)//避免虚假唤醒，如果工作线程还没有执行的时候就被
				 //虚假唤醒，此时 notified 还为 false，这样可以进入
				 //函数内部进行阻塞
				 //
				 //还有就是逻辑更清晰，表示notified 为 false 的时候就应该阻塞

		{
			gConditionVariable.wait(lock);// 释放锁并等待
		}
		std::cout << "result is " << result << std::endl;
	});


	//工作线程
	std::thread  worker([&] {
			std::unique_lock<std::mutex> lock(gLock); // 上锁
			result = 50;
			isWorkerThreadDone = true;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			gConditionVariable.notify_one();// 释放锁，并唤醒其他线程
			// 如果不使用条件变量的时候，其他线程会持续去忙等待CPU	
	});

	worker.join();
	repoter.join();
	std::cout << "主线程完成" << std::endl;
}

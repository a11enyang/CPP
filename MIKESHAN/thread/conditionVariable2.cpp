#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>


std::mutex gLock;
std::condition_variable conditionVariable;


void worker()
{
	std::unique_lock<std::mutex> lock(gLock);
	conditionVariable.wait(lock);//worker 线程后执行
	std::cout << "worker线程:" << std::this_thread::get_id() << std::endl;
}


void notify()
{
	std::unique_lock<std::mutex> lock(gLock);
	std::cout << "notify线程" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	conditionVariable.notify_one();//这样保证了 notify 线程肯定是先执行的。
}

int main()
{
	std::thread t1(worker);
	std::thread t2(worker);
	std::thread t3(notify);

	t1.join();
	t2.join();
	t3.join();
}


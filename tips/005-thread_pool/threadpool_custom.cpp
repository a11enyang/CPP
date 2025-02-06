#include <atomic>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>


class ThreadPool
{
private:
	std::queue<std::function<void()>> tasks;// 任务池
	std::vector<std::thread> workers;//线程池
	size_t numThreads;
	std::atomic_bool isStop;
	

	// 同步
	std::mutex mutex;
	std::condition_variable condition;	
public:
	ThreadPool(size_t n): numThreads(n)
	{
		isStop = false;
		for (size_t i = 0; i < n; i++)
		{
			workers.emplace_back([this] { worker(); });
		}
	}

	~ThreadPool()
	{
		isStop = true;
		condition.notify_all();
		for (size_t i = 0; i < numThreads; i++)
		{
			workers.at(i).join();
		}
	}

	void newTask(std::function<void()> f)
	{
		{
			std::unique_lock lock(mutex);		
			tasks.emplace(f);
		}
		condition.notify_one();
	}

	void worker()// 可以理解这个就是工作线程，负责从队列中取出任务并执行
	{
		while(!isStop)
		{
			std::function<void()> task;
			{
				std::unique_lock<std::mutex> lock(mutex);	
				condition.wait(lock, [this] {return !isStop && !tasks.empty(); });
				task = tasks.front();
				tasks.pop();
			}	
			task();
		}
	}

};


int main()
{
	ThreadPool threadpool(5);
	threadpool.newTask([] {
		while(1)
		{
			std::cout << "线程1" << std::endl;	
		}		
	});
	threadpool.newTask([] {
		while(1)
		{
			std::cout << "线程2" << std::endl;	
		}		
	});
	return 0;
}

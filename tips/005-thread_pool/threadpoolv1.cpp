#include <atomic>
#include<cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>
class ThreadPool
{
public:
	ThreadPool(size_t numThreads);
	~ThreadPool();

	// 提交任务到线程池
	template <typename F>
	void enqueue(F&& f);

private:
	void worker();

	std::vector<std::thread> workers;

	std::atomic_bool stop;
};

// 构造函数
ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
	for (size_t i = 0; i < numThreads; ++i)
	{
		workers.emplace_back([this] {worker();});
	}

}

// 析构函数
ThreadPool::~ThreadPool()
{
	stop = true;
	for (auto& e: workers)
	{
		e.join();
	}
	std::cout << "析构函数结束 \n";
}

void ThreadPool::worker() 
{
	while(!stop)
	{
		std::this_thread::yield();
	}
}

// 提交任务到线程池
template <typename F>
void ThreadPool::enqueue(F&& f)
{
	std::thread([this, task = std::forward<F> (f)] {
		task();// 执行任务
	}).detach();
}

int main() 
{
    ThreadPool pool(4); // 创建4个线程的线程池

    for (int i = 0; i < 8; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " is running on thread " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Task " << i << " is done" << std::endl;
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(5)); // 等待所有任务完成
    return 0;
}

#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::queue<std::function<void()>> tasks;
std::mutex gLock;
std::condition_variable condition;
static std::atomic_int number = 0;
int main()
{
	
	std::thread produc([] {
		std::unique_lock<std::mutex> lock(gLock);
		tasks.emplace([] {
			std::cout << "入队任务 \n";
		});
		condition.notify_one();		
	});	

	std::thread dequeue([] {
		std::unique_lock<std::mutex> lock(gLock);
		condition.wait(lock, !tasks.empty());
		if (tasks.empty())
		{
			return;
		}
		std::cout << "出队任务 \n";			
	});


	tasks.emplace([] {
		std::cout << "这是任务1 \n";		
	});

	tasks.emplace([] {
		std::cout << "这是任务2 \n";		
	});

	while(!tasks.empty())
	{
		std::function<void()> task = tasks.front();
		tasks.pop();
		task();
	}
	return 0;
}

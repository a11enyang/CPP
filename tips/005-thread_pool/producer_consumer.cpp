#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>


struct Box
{
	int sn;
	int weight;
	
	Box(int sn, int weight) : sn(sn), weight(weight) {}
};

std::queue<Box> q;
static std::atomic<int> sn{0};
static std::atomic<int> weight{39};

// 同步
std::mutex gMutex;
std::condition_variable condition;
bool isProducerDone = false;
int main()
{
	
	std::thread producer([&] {
		while (1)
		{
			std::unique_lock<std::mutex> lock(gMutex);
			if (q.size() > 9)
			{
				std::cout << "仓库已满" << std::endl;	
				condition.notify_all();// notify 只是唤醒其他线程，并没有阻塞当前线程
				condition.wait(lock);
			}
			std::cout << "新生产商品，序号：" << sn << std::endl;
			q.emplace(sn, weight);
			sn++;
			weight += 5;
			isProducerDone = true;
			condition.notify_all();			
		}

	});

	std::thread consumer1([&] {
		while (1)
		{
			std::unique_lock<std::mutex> lock(gMutex);
			condition.wait(lock, [&] {
				if (q.empty())
				{
					std::cout << "仓库已空 \n";
				}
				return isProducerDone && !q.empty();
			}); 
			std::cout << "消费商品，序号：" << q.front().sn << std::endl;
			q.pop();
			condition.notify_all();
		}
	});
	std::thread consumer2([&] {
		while (1)
		{
			std::unique_lock<std::mutex> lock(gMutex);
			condition.wait(lock, [&] {
				if (q.empty())
				{
					std::cout << "仓库已空 \n";
				}
				return isProducerDone && !q.empty();
			});// 就算唤醒后也会去校验条件 
			std::cout << "消费商品，序号：" << q.front().sn << std::endl;
			q.pop();
			condition.notify_all();
		}
	});

	producer.join();
	consumer1.join();
	consumer2.join();
	return 0;
}

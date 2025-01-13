#include <condition_variable>
#include <thread>
#include <vector>

class ThreadPool
{
public:
	explicit ThreadPool(size_t numThreads)
	{
		start(numThreads);
	}

	~ThreadPool()
	{
	}
private:
	std::vector<std::thread> mThreads;
	std::condition_variable mEventVar;
	std::mutex mEventMutex;
	bool mStopping = false;

	void start(std::size_t numThreads)
	{
		for (auto i = 0u; i < numThreads; i++)
		{
			mThreads.emplace_back([=] {
				while (1)
				{
					std::unique_lock<std::mutex> lock(mEventMutex);
					mEventVar.wait(lock, [=] {return mStopping; });
					if (mStopping)
					{
						break;
					}
				}		
			
			});
		}
	}

	void stop() noexcept
	{
		
	}
};

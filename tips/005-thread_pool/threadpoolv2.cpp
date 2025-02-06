#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    // 提交任务到线程池
    template<class F>
    void enqueue(F&& f);

private:
    // 工作线程函数
    void worker();

    // 线程池中的线程
    std::vector<std::thread> workers;

    // 任务队列
    std::queue<std::function<void()>> tasks;

    // 同步
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

// 构造函数，启动指定数量的工作线程
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this] { worker(); });
    }
}

// 析构函数，等待所有线程完成
ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

// 提交任务到任务队列
template<class F>
void ThreadPool::enqueue(F&& f) {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.emplace(std::forward<F>(f));
    }
    condition.notify_one();// 唤醒一个工作线程去执行任务
}

// 工作线程函数
void ThreadPool::worker() 
{
    while (!stop)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);// 对任务队列操作的时候先上锁
            condition.wait(lock, [this] { return stop || !tasks.empty(); });// 线程等待， 除非满足后面的条件
            if (stop && tasks.empty())// 重复确认，确保没有被虚假唤醒
	    {
                return;
            }
            task = std::move(tasks.front());// 拿到一个任务
            tasks.pop();
        }
        task();
    }
}

// 示例使用
int main() {
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

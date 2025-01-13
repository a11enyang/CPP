#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

static std::atomic_int x = 0;
std::mutex gLock;
void add()
{
	x++;
}

int main ()
{

        std::vector<std::thread> threads;
        for (int i = 0; i < 10; i++)
        {
                threads.push_back(std::thread(add));
        }

        for (int i = 0; i < threads.size(); i++)
        {
                threads[i].join();
        }
        std::cout << "x 的值：" << x << std::endl;
        return 0;
}

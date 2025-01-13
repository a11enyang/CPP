#include <iostream>
#include <thread>

void test(int x)
{
	std::cout << "这是子线程" << std::endl;
	std::cout << "入参的值：" << x << std::endl;
}


int main()
{
	std::thread myThread(&test, 100);
	myThread.join();//主线程阻塞，等待子线程执行完成之后再继续运行
	std::cout << "这是主线程" << std::endl;
	return 0;
}

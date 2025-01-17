#include <functional>
#include <iostream>
#include <vector>

void yibu(const std::function<void()>& func)
{
        std::cout << "执行任务..." << std::endl;
        func();
}

struct functor
{
	void operator() ()
	{
		std::cout << "仿函数 \n";
	}
};

void Hello()
{
	std::cout << "函数指针 \n";
}



int main()
{
   	yibu([] {std::cout << "lambda表达式 \n";});
    	yibu(functor());
	yibu(Hello);	

	
	std::vector<std::function<void()>> v;
	for (int i = 0; i < 10; i++)
	{
		v.emplace_back([i] {std::cout << "创建第" << i << "个函数 \n" ;});
	}

	v.at(2)();
	return 0;
}

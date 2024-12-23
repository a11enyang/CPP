#include<iostream>

int countdown(int n)
{
	//base station基础情况
	if ( n == 0)
	{
		std::cout << " 0。。。已经最后了" << std::endl;
		return 0;
	}
	
	//当前这一层需要完成的内容
	std::cout << n << std::endl;
	
	//下一层
	return countdown(n-1);
}

int f(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	std::cout << n << std::endl;
	return f(n-1) + f(n-2);
}

int main()
{
	//countdown(7);
	std::cout << f(6) << std::endl;
	return 0;
}


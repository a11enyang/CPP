#include <exception>
#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		throw std::runtime_error(" 空指针异常");
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}

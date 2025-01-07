#include <iostream>
#include <memory>

// 第一种方式：通过内部类隐藏内部实现
class API1
{
public:
	API1();
	~API1();
	void doSomeThing();
private:
	class InterClass;
	std::unique_ptr<InterClass> ptr;
};

class API1::InterClass
{
public:
	void doSomeThing()
	{
		std::cout << "do doSomeThing" << std::endl;
	}
};
API1::~API1()
{
}

API1::API1(): ptr(std::make_unique<API1::InterClass> ())
{
}


void API1::doSomeThing()
{
	ptr->doSomeThing();
}


// 第二种方式：通过结构体传递多种参数
 struct WindowOptions
{
	int width=800;
	int height=900;
	std::string title = "my window";
};

void printWindowOptions(const WindowOptions& option = {})
{
	std::cout << option.width << std::endl;
	std::cout << option.height << std::endl;
	std::cout << option.title << std::endl;
}

int main()
{
	API1 api;
	api.doSomeThing();

	WindowOptions wo;
	printWindowOptions(wo);
}


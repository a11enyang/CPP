//类组合是一种设计模式，指的是一个类包含其他类的对象作为其成员变量

#include <iostream>

class Engine
{
	public:
		void start()
		{
			std::cout << "Engine started \n";
		}
};

class Car
{
	private:
		Engine engine;
	public:
		void start()
		{
			engine.start();
			std::cout << "Car started \n";
		}
};

int main()
{
	Car car;
	car.start();

}

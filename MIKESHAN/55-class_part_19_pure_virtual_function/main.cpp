#include <iostream>

class IRenderer
{
	public:
		virtual void draw() = 0;//子类一定要实现这个纯虚函数
		virtual void update() = 0;
};


class OpenGL: public IRenderer
{
	public:
		virtual void draw() override
		{
			std::cout << "OpenGL Draw \n";
		}

		virtual void update() override
		{
			std::cout << "OpenGL Update \n";
		}
};


int main()
{
	IRenderer* irender = new OpenGL();
	irender->update();
}

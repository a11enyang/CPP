#include <iostream>

namespace ModuleA
{
	float calcArea(float w, float h)
	{
		return w * h;
	}
}

namespace ModuleB
{
	void print(float area)
	{
		std::cout << "area:" << area << std::endl;
	}
}

namespace ModuleC
{
	class Student
	{
		public:
			Student() {}
			~Student() {}
		private:
			std::string m_name;
		
	};
}



int main()
{
	float area = ModuleA::calcArea(3, 4);
	ModuleB::print(area);
	ModuleC::Student mike;
	return 0;
}


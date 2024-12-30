#include "student.hpp"
Student::Student()
{
	std::cout << "构造函数\n";
}

Student::~Student()
{
	std::cout << "析构函数\n";
}

void Student::printName()
{
	std::cout << "名字:" << m_name << std::endl;
}

#include <iostream>
#include <string>

class Student
{
	private:
		std::string m_name;

	public:
		Student(const std::string& name): m_name(name)//创建一个带参构造函数，则不会生成默认构造函数
							      //但是会生成默认的复制构造函数
							      //并且会生成一个默认重载=的复制构造函数
		{
			
		}

		Student& operator=(const Student& other)
		{
			std::cout << "赋值操作符 \n";
			return *this;
		}
};
//创建一个类
//编译器会隐式生成：
//默认构造函数与析构函数
//复制构造函数
//重载了运算符的复制构造函数
//赋值运算符
int main()
{
	Student s1("mike");
	Student s2(s1);
	Student s3 = s1;
	s3 = s1;
	return 0;
}

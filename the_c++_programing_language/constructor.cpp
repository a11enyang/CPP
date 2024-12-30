#include <iostream>

class Student
{
	public:
		Student()
		{
			std::cout << "默认构造函数\n";
		}

		Student(const std::string& name): m_name(name)
		{
			std::cout << "带参构造函数 \n";
		}

		Student(const Student& s): m_name(s.m_name)//初始化成员列表可以直接访问私有成员变量
		{
			//m_name = s.getName();
			std::cout << "复制构造函数\n";
		}
	
		std::string getName() const
		{
			return m_name;
		}

		~Student()
		{
			std::cout << "析构函数\n";
		}
	private:
		std::string m_name;
};

int main()
{
	Student s1;
	Student s2("s2");
	Student s3(s2);
	Student* s4 = new Student;
	Student* s5 = new Student(s3);
	Student* s6 = new Student("s5");
	delete s4;//调用析构函数
	delete s5;
	delete s6;
	return 0;
}

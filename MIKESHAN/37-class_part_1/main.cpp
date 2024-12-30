#include "student.hpp"

int main()
{
	Student mike = Student();//先调用默认构造函数，再调用复制构造函数。
	mike.printName();
	Student allen;//调用默认构造函数
	return 0;
}

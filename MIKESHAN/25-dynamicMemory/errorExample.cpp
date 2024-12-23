#include <iostream>

int main()
{
	int number_of_students = 0;
	std::cin >> number_of_students;

	int students[number_of_students];//这种方式是不合法的，因为数组的大小是在编译期就确定的
	for (int i = 0; i < number_of_students; i++)
	{
		students[i] = 1;
	}
	return 0;
}

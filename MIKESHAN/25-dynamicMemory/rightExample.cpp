#include <iostream>

int main()
{
	int number_of_students = 0;
	std::cin >> number_of_students;
	int* students = new int[number_of_students];
	for (int i = 0; i < number_of_students; i++)
	{
		students[i] = i;
	}
	delete[] students;//删除动态分配的内容
	return 0;
}

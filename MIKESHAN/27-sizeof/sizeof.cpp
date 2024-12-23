#include <iostream>
#include <vector>
int main()
{
	int x = 0;
	int* px = &x;
	int array[] = {1,2,3,4,5};
	int* students = new int[1000];
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::cout << "x:" << sizeof(x) << std::endl;
	std::cout << "px:" << sizeof(px) << std::endl;
	std::cout << "array:" << sizeof(array) << std::endl;//编译器计算的，所以 sizeof 数组时
							    //得到的是整个数组的长度
	std::cout << "students:" << sizeof(students) << std::endl;
	std::cout << "vector:" << sizeof(v) << std::endl;
}

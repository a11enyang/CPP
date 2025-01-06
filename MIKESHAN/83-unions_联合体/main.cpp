#include <iostream>
union U
{
	char a;
	short b;
	int c;
};//联合体的大小是最大的成员的大小，使用的时候只能选择其中的一个成员

int main()
{
	std::cout << sizeof(U) << std::endl;
}

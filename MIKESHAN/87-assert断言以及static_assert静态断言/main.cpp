#include <cassert>
int main()
{
	constexpr int a = 2;
	assert(a > 0 && "a应该是正数");
	static_assert(a > 0, "a应该为正数");
	
	//为特定架构进行一些测量
	static_assert(sizeof(int) == 4, "int的大小应该为4字节");
	static_assert(sizeof(short) == 2, "short的大小应该为2字节");
}

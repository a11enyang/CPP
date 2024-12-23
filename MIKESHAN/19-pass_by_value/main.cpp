#include <iostream>
#include <iterator>

void setValue(int argu) {
	std::cout << "argu初始值: " << argu << std::endl;
	argu = 999;
	std::cout << "argu 修改后的值：" << argu << std::endl;
}


int main(){
	int x = 1;
	setValue(x);
	std::cout << "x 的值：" << x << std::endl;
}

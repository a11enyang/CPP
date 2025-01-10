#include <bitset>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <thread>


int main()
{
	{
		std::ofstream os("text.txt");// 打开一个文件，如果文件不存在，就创建一个文件
		os << "text.txt" << std::endl;
		os << "123" << std::endl;
		os << 123 << std::endl;
		os << std::bitset<8> (14) << std::endl;//当超过ofstream的作用域时，文件就会自动关闭，不会出现资源泄露的情况，采用了RAII的设计思想
	}			

	{
		std::ofstream os("text.txt", std::ofstream::app);// 将指针移动到文件的末尾, 追加文件，不会修改文件的原来内容
		os << "这是新附加的内容"  << std::endl;
	}

	{
		std::ofstream os("text.txt", std::ofstream::in | std::ofstream::out);// 这种方式不会对文件截断
		os.seekp(0, std::ios_base::beg); // 设置指针相对于文件开头的位置
		os << "add in the beginning" << std::endl; // 会对原来位置的内容进行覆盖

		os.seekp(0, std::ios_base::end); // 设置指针相对于文件末尾的位置
		os << "在文件末尾新增几个字" << std::endl;
		
		// std::ios_base::cur 当前的位置
	}

	std::cout << 123; // std::cout 是一个全局对象
	std::cout.flush();// flush 刷新缓冲区
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

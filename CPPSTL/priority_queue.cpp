#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <vector>
// 优先队列就是堆，提供常数时间的最大元素查找，对数时间的插入与提取，底层原理是二叉堆
// 使用场景：每次需要插入大小不一的元素，然后取出来的时候需要取出最大或者最小的元素

struct Student
{
	std::string name;
	int age;

	Student(const std::string& name, int age):name(name), age(age) {} 

};

struct Compare
{
	bool operator() (const Student& s1, const Student& s2)
	{
		return s1.age < s2.age ? true : false;
	}
};



int main()
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pque; // 默认是大顶堆，顶部元素是最大的值
	pque.push(5);
	pque.push(100);
	pque.push(20);
	pque.push(44);
	pque.push(79);
	std::cout << pque.top() << '\n';


	std::priority_queue<Student, std::vector<Student>, Compare> pque2;
	pque2.push(Student(std::string("jack"), 22));
	pque2.push(Student(std::string("bob"), 10));
	pque2.push(Student(std::string("allen"),6));
	pque2.push(Student(std::string("bill"), 47));
	pque2.push(Student(std::string("bush"), 18));
	std::cout <<  pque2.top().name << ',' << pque2.top().age << std::endl;
}

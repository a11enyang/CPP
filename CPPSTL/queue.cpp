#include <iostream>
#include <ostream>
#include <queue>

int main()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);
	std::cout << q.back() << std::endl;
	
	q.pop();
}

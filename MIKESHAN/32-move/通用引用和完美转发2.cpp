#include <iostream>
#include <string>
#include <utility>
class Widget
{
private:
	std::string name;
	int value;
public:
	Widget(const std::string& n, int&& v): name(n), value(v) 
	{
		std::cout << "Widget 创建" << name << "," << std::endl;
	}
};

template<typename T1, typename T2>
Widget make_widget(T1&& arg1, T2&& arg2)
{
	return Widget(std::forward<T1>(arg1), std::forward<T2>(arg2));
}

int main()
{
	int value = 10;
	Widget w2 = make_widget("MyWidget", 10);
}

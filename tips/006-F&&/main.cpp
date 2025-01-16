#include <iostream>

template<typename F>
void showFunc(F&& f)
{
	f();
}

int main ()
{
	showFunc([] {
		std::cout << "123" << std::endl;		
	});
	return 0;
}

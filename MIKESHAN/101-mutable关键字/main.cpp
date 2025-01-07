#include <iostream>


struct MyClass
{
	mutable int x;
	int y;
	void changeValue() const
	{
		x = 1;
	}

};


int main()
{

}

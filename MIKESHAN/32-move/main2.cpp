#include <iostream>


struct Base
{
	int x;

};


int main()
{
	Base b;
	Base c = std::move(b);
};

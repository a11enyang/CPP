#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>

class Calculator
{
	public:
		Calculator();
		~Calculator();

		int add(int a, int b);
		int subtract(int a, int b);
	private:
		class Impl;
		std::unique_ptr<Impl> pImpl;
};



#endif

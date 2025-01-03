#include "Calculator.hpp"

class Calculator::Impl
{
	public:
		int add(int a, int b)
		{
			return a+b;
		}

		int subtract(int a, int b)
		{
			return a-b;
		}
};

Calculator::Calculator(): pImpl(std::make_unique<Impl>()) {}
Calculator::~Calculator() = default;

int Calculator::add(int a, int b)
{
	return pImpl->add(a, b);
}

int Calculator::subtract(int a, int b)
{
	return pImpl->subtract(a, b);
}

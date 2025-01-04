// main.cpp
#include "Calculator.hpp"
#include <iostream>

int main() {
    Calculator calc;

    std::cout << "10 + 5 = " << calc.add(10, 5) << "\n";
    std::cout << "10 - 5 = " << calc.subtract(10, 5) << "\n";

    return 0;
}

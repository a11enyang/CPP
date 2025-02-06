#include <iostream>
#include <utility> // for std::forward

// 目标函数，处理左值和右值
void process(int& x) {
    std::cout << "Processing lvalue: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Processing rvalue: " << x << std::endl;
    x = 20;
}

// 转发函数模板
template<typename T>
void forwarder(T&& arg) {
    // 使用 std::forward 完美转发参数
    process(std::forward<T>(arg));
}

int main() {
    int x = 10;

    // 传递左值
    //forwarder(x); // 调用 process(int&)

    // 传递右值
    //forwarder(20); // 调用 process(int&&)

    // 传递右值（通过 std::move）
    forwarder(std::move(x)); // 调用 process(int&&)

    std::cout << "x value: " << x << std::endl;
    return 0;
}

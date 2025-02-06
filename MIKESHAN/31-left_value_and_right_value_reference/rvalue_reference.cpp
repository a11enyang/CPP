#include <iostream>
#include <vector>

struct DebugVector {
    std::vector<int> data;

    DebugVector() = default;

    // 接受初始化列表的构造函数
    DebugVector(std::initializer_list<int> initList) : data(initList) {
        std::cout << "初始化列表 Initializer list constructor called!" << std::endl;
    }

    // 移动构造函数
    DebugVector(DebugVector&& other) noexcept {
        std::cout << "移动构造函数 Move constructor called!" << std::endl;
        data = std::move(other.data);
    }

    // 拷贝构造函数
    DebugVector(const DebugVector& other) {
        std::cout << "拷贝构造函数 Copy constructor called!" << std::endl;
        data = other.data;
    }
};

DebugVector processVector(DebugVector&& vec) {
    std::cout << "Processing vector of size: " << vec.data.size() << std::endl;
    vec.data.push_back(100); // 修改 vector
    return std::move(vec); // 返回右值
}

int main() {
    DebugVector result = processVector(DebugVector{1, 2, 3, 4, 5}); // 显式构造临时对象

    std::cout << "Result vector: ";
    for (int value : result.data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    DebugVector test2{2, 3, 4, 5};

    DebugVector test3 = std::move(test2);
    return 0;
}

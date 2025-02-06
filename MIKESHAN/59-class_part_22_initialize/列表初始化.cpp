#include <iostream>
#include <vector>
#include <initializer_list>

// 自定义类
class MyClass {
private:
    std::vector<int> data;

public:
    // 默认构造函数
    MyClass() {
        std::cout << "Default constructor called!" << std::endl;
    }

    // 接受初始化列表的构造函数
    MyClass(std::initializer_list<int> list) : data(list) {
        std::cout << "Initializer list constructor called!" << std::endl;
    }

    // 成员函数：打印数据
    void print() const {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // 列表初始化：使用花括号传递初始化列表
    MyClass obj1{1, 2, 3, 4, 5}; // 调用接受 std::initializer_list 的构造函数

    // 列表初始化：空列表
    MyClass obj2{}; // 调用默认构造函数

    MyClass obj3 = {1, 2, 3, 4};

    // 打印数据
    std::cout << "obj1: ";
    obj1.print();

    std::cout << "obj2: ";
    obj2.print();

    std::cout << "obj3: ";
    obj3.print();
    return 0;
}

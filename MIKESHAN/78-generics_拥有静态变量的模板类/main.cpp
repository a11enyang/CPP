#include <iostream>

// 类模板
template <typename T>
class MyClass {
public:
    static int count;  // 静态成员变量声明

    MyClass() {
        count++;  // 每次创建对象时，count 增加
    }

    void printCount() {
        std::cout << "Count: " << count << std::endl;
    }
};

// 静态成员变量定义
template <typename T>
int MyClass<T>::count = 0;  // 初始化为 0

int main() {
    // 使用 int 类型实例化类模板
    MyClass<int> obj1;
    obj1.printCount();  // 输出：Count: 1

    MyClass<int> obj2;  // 只有模板参数相同的模板类才会共享静态了变量
    obj2.printCount();  // 输出：Count: 2

    // 使用 double 类型实例化类模板
    MyClass<double> obj3;
    obj3.printCount();  // 输出：Count: 1

    return 0;
}

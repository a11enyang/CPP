#include <iostream>
#include <string>

// 自定义类
class Person {
private:
    std::string name;
    int age;

public:
    // 构造函数
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Constructor called: " << name << ", " << age << std::endl;
    }

    // 成员函数
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // 直接初始化：使用括号传递参数
    Person p1("Alice", 25); // 调用构造函数 Person(const std::string&, int)

    // 直接初始化：使用花括号传递参数（C++11 引入的列表初始化） 先去查找接受initializer_list的构造函数，然后再去寻找对应的参数化构造函数, 禁止摘花转换
    Person p2{"Bob", 30}; // 调用构造函数 Person(const std::string&, int)

    Person* p3 = new Person{"alleb", 20};

    // 调用成员函数
    p1.display();
    p2.display();

    return 0;
}

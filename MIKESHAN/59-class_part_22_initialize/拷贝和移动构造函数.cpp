#include <iostream>
#include <cstring>

class MyString {
private:
    char* data; // 动态分配的字符数组
    size_t length; // 字符串长度

public:
    // 默认构造函数
    MyString() : data(nullptr), length(0) {
        std::cout << "Default constructor called!" << std::endl;
    }

    // 参数化构造函数
    MyString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1]; // 分配内存
        std::strcpy(data, str); // 复制字符串
        std::cout << "Parameterized constructor called: " << data << std::endl;
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1]; // 分配内存
        std::strcpy(data, other.data); // 复制字符串
        std::cout << "Copy constructor called: " << data << std::endl;
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept {
        length = other.length;
        data = other.data; // 直接接管资源
        other.data = nullptr; // 将原对象的指针置为空
        other.length = 0;
        std::cout << "Move constructor called: " << data << std::endl;
    }

    // 析构函数
    ~MyString() {
        if (data) {
            delete[] data; // 释放内存
            std::cout << "Destructor called: " << data << std::endl;
        } else {
            std::cout << "Destructor called: nullptr" << std::endl;
        }
    }

    // 打印字符串
    void print() const {
        if (data) {
            std::cout << "String: " << data << std::endl;
        } else {
            std::cout << "String: nullptr" << std::endl;
        }
    }
};

int main() {
    // 参数化构造函数
    MyString str1("Hello, World!");
    str1.print();

    // 拷贝构造函数
    MyString str2 = str1; // 调用拷贝构造函数
    str2.print();

    // 移动构造函数
    MyString str3 = std::move(str1); // 调用移动构造函数
    str3.print();
    str1.print(); // str1 的资源已被移动，data 为 nullptr

    return 0;
}

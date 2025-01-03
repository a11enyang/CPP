#include <iostream>
#include <cstring>

class MyClass {
public:
    MyClass(const char* str) {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
        std::cout << "Constructor called\n";
    }

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // 将原对象的指针置空
        other.size = 0;
        std::cout << "Move Constructor called\n";
    }

    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    void print() const {
        std::cout << "Data: " << (data ? data : "nullptr") << std::endl;
    }

private:
    size_t size;
    char* data;
};

void stealResource(MyClass& obj) {
    MyClass newObj(std::move(obj)); // 窃取 obj 的资源
    newObj.print();
}

int main() {
    MyClass obj("Hello");
    stealResource(obj); // 将 obj 作为右值传递给函数
    obj.print(); // obj 的资源已被窃取，data 为 nullptr
    return 0;
}

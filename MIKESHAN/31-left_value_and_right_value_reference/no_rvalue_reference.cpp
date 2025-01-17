#include <iostream>
#include <cstring>

class MyString {
public:
    MyString(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        std::memcpy(data, str, size + 1);
	std::cout << "构造函数 \n";
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        size = other.size;
        data = new char[size + 1];
        std::memcpy(data, other.data, size + 1);
	std::cout << "拷贝构造函数 \n";
    }

    // 拷贝赋值运算符
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data; // 释放原有资源
            size = other.size;
            data = new char[size + 1];
            std::memcpy(data, other.data, size + 1);
	    std::cout << "赋值运算符 \n";
        }
        return *this;
    }

    ~MyString() {
        delete[] data;
    }

    void print() const {
        std::cout << "String: " << (data ? data : "nullptr") << std::endl;
    }

private:
    char* data;
    size_t size;
};

MyString createString() {
    return MyString("Hello"); // 返回临时对象
}

int main() {
    MyString s1 = createString(); // 调用2次拷贝构造函数
    s1.print();
    return 0;
}

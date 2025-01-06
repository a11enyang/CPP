#include <algorithm>
#include <cstring>
#include <iostream>

class MyClass {
public:
    int* data;

    MyClass(int value): data(new int(value)) {
    }

    MyClass(const MyClass& other): data(new int(*other.data))
    {
    }

    MyClass& operator=(const MyClass& other)
    {	
	if (this == &other)
	{
		return *this;
	}
	std::memcpy(data, other.data, 1);
 	return *this;	
    }
    
    ~MyClass() {
        delete data;
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = obj1;  // 浅拷贝，会导致双重释放
    return 0;
}

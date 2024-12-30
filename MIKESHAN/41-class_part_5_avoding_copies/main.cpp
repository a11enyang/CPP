#include <iostream>
#include <vector>

class MyClass
{
public:
        MyClass()
        {

        }

        MyClass(int size, int number): size(size)
        {
                data.resize(size);
                for (int i = 0; i < size; i++)
                {
                        data[i] = number;
                }
        }

        MyClass(const MyClass& other):size(other.size), data(other.data)//虽然浅拷贝构造函数
                                                                        //但是调用了vector的深拷贝构造函数
        {
                std::cout << "浅拷贝构造函数" << std::endl;
        }

        void print()
        {
                for (auto& e: data)
                {
                        std::cout << e << " ";
                }
        }
private:
        std::vector<int> data;
        int size;
};


void printData(MyClass myclass)//这种就会调用拷贝构造函数,但是通过引用的方式jiubuhui
{
	myclass.print();
}


int main()
{
	MyClass obj1(2,1);
	printData(obj1);

}

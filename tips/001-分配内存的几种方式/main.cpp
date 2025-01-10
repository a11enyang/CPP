

int main()
{
	int* ptr = new int[20];//先分配内存，然后调用构造函数创建对象，最后返回指向最后一个对象的指针
	delete[] ptr;
	int* ptr2 = static_cast<int*>(::operator new(20 * sizeof(int)));
	delete ptr2;
}

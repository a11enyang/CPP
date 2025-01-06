#include <cstring>
template <typename T, size_t size>
class Container
{
public:
	Container()
	{
		data = new T[size];
	}

	~Container()
	{
		delete[] data;
	}
private:
	T* data;

};

int main()
{
	Container<int, 5> c1;
}

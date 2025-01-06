#include <algorithm>
#include <iostream>
#include <cstring>
template <typename T, size_t N=10>
class Container
{
	public:
		Container(): data(new T[N])
		{
			size += N;
		}

		~Container()
		{
			delete[] data;
		}
		
		Container(const Container& other)
		{
			data = new T[N];
				
		}

		static int size;
	private:
		T* data;
};

template <typename T, size_t N>
int Container<T, N>::size = 0;

int main()
{
	Container<int, 5> c1;
	Container<int, 5> c2;
	std::cout << c2.size << std::endl;	
}

#include <iostream>

void prinfArray(const int arr[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << std::endl;
	}
}

void printArray2(const std::array<int, 5>& arr)
{
	for (auto& element: arr)
	{
		std::cout << element << std::endl;
	}
}

int main()
{
	int array[] = {1,2,3,4,5};
	std::array<int, 5> array2 = {1,2,3,4,5};
	prinfArray(array, sizeof(array)/sizeof(array[0]));
	printArray2(array2);
	return 0;
}

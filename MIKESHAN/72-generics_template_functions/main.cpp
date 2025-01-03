#include <array>
#include <cstring>
#include <iostream>
#include <type_traits>

template <typename T>
T max(T a, T b)
{
	return (a > b)? a : b;
}

template <>
const char* max(const char* a, const char *b)
{
	return (std::strcmp(a, b) > 0)? a : b;
}

int main()
{
    std::cout << "max(\"apple\", \"banana\") = " << max("apple", "banana") << "\n";
    std::cout << "max(\"1\", \"2\") = " << max(1, 2) << "\n";
    std::array<int, 3> arr{};
    for (auto& e: arr)
    {
    	std::cout << e << "\n";
    }
    return 0;
}

#include <iostream>
#include <vector>

auto pass_by_ref(int&) -> void;
auto pass_by_ref_vector(std::vector<int>& argu) -> void;



int main()
{
	int x = 100;
	std::cout << "main: " << x << std::endl;
	pass_by_ref(x);
	std::cout << "main: " << x << std::endl;
	
	std::vector<int> nums(100000000);
	std::fill(nums.begin(), nums.end(), 1000);
	pass_by_ref_vector(nums);
	return 0;
}

void pass_by_ref(int& argu)
{
	std::cout << "pass_by_ref argu: " << argu << std::endl;
	argu = 999;
}

void pass_by_ref_vector(std::vector<int>& argu)
{
	argu[0] = 0;
}

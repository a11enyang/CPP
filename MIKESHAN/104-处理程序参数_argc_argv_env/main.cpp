#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[], char* env[])
{
	std::cout << "argc: " << argc << '\n';
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << " ";
	}

	int i = 0;
	while(1)
	{
		std::cout << env[i++] << '\n';
		if (env[i] == nullptr)
		{
			break;
		}
	}

	std::cout << std::getenv("USER") << '\n';
}

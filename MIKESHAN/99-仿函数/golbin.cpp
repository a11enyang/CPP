#include <algorithm>
#include <iostream>
#include <vector>

class Golbin
{
public:
	Golbin(int h, int s): health(h), strength(s) {}
	Golbin(int h): Golbin(h, 20) {}
	struct CompareHealth
	{
		bool operator() (const Golbin& a, const Golbin& b)
		{
			return a.health < b.health ? true : false;
		}
	};

	struct CompareStrenth
	{
		bool operator() (const Golbin& a, const Golbin& b)
		{
			return a.strength < b.strength ? true : false;
		}
    
	};

	int getHealth() const
	{
		return health;
	}
	
	int getStrength() const 
	{
		return strength;
	}

	bool operator< (const Golbin& other)
	{
		return this->health > other.health ? true :false;
	}	
private:
	int health;
	int strength;
};


int main()
{
	std::vector<Golbin> golbins{Golbin(100, 23), Golbin(80, 43), Golbin(23, 35), Golbin(55, 77), Golbin(11, 81)};
	std::cout << "Golbin::CompareHealth() \n";
	std::sort(golbins.begin(), golbins.end(), Golbin::CompareHealth());
	std::for_each(golbins.begin(), golbins.end(), [] (Golbin& e) {std::cout << e.getHealth() << ',';});
	std::cout << "\n Golbin::CompareHealth() \n";
	std::sort(golbins.begin(), golbins.end(), Golbin::CompareStrenth());
	for (auto& e: golbins)
	{
		std::cout << e.getStrength() << ',';
	}

	std::vector<Golbin> golbins2(golbins);
	std::sort(golbins2.begin(), golbins2.end());
	for (auto& e : golbins2)
	{
		std::cout << e.getHealth() << std::endl;
	}
}

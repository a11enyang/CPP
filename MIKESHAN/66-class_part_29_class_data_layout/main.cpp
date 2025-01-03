#include <iostream>
struct GameState1
{
	bool isCheckPoint;
	long score;
	short numberOfPlayer;
};

struct GameState2
{
	bool isCheckPoint;
	short numberOfPlayer;
	int score;
};

int main()
{
	GameState1 gs1;
	GameState2 gs2;
	std::cout << "GameState1-bool: " << sizeof(gs1.isCheckPoint) << std::endl;
	std::cout << "GameState1-int: " << sizeof(gs1.score) << std::endl;
	std::cout << "GameState1-numberOfPlayer: " << sizeof(gs1.numberOfPlayer) << std::endl;
	std::cout << "GameState1: " << sizeof(gs1) << std::endl;
	std::cout << "GameState2: " << sizeof(gs2) << std::endl;
}

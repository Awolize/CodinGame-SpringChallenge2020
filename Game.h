#pragma once
#include <string>
#include <map>

class PacMan
{
public:
	PacMan() {};
	PacMan(int pacId, int x, int y) :
		pacId(pacId), x(x), y(y),
		cell(Map::GetCell(x, y))
	{};

	int pacId{ -1 };
	int x{ -1 };
	int y{ -1 };
	Cell cell;

	// unused in wood leagues
	std::string typeId{ "" };
	int speedTurnsLeft{ -1 };
	int abilityCooldown{ -1 };

};

class Player
{
public:
	inline Player(int score, int opponentScore) : score(score), opponentScore(opponentScore) {};
public:
	int score = 0;
	int opponentScore = 0;
	std::map<int, PacMan> pacs;
};

class Game
{
public:
	inline Game() : players{ Player(0, 0), Player(0, 0) } {};
public:
	Player players[2];
};



#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include "Map.h"

using namespace std;

class ReadInput
{
public:
	inline static void Initilize()
	{
		int width; // size of the grid
		int height; // top left corner is (x=0, y=0)

		std::cin >> width >> height; std::cin.ignore();

        Map::width = width;
        Map::height = height;

		for (int y = 0; y < height; y++) {
			string row;
            std::getline(std::cin, row); // one line of the grid: space " " is floor, pound "#" is wall
            for (int x = 0; x < row.size(); x++)
            {
                Map::AddCell(Cell(x, y, row[x]));
            }
		}
	}

	inline static Game ReadRound(Game lastGame)
	{
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();
        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();
        }
        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
        }
	}

	inline static std::string ReadLine()
	{

	}
};


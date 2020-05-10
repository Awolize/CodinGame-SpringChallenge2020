#pragma once
#include "Game.h"
#include "Map.h"
#include <random>
#include "BreadthFirstSearchService.h"

class ReactAgent
{
public:
	ReactAgent(Game& game): game(game), p1(game.players[0]), p2(game.players[1]) {};

	std::string think() {
		string returnStr = "";
		for (auto curr : p1.pacs)
		{
			PacMan currPac = curr.second;
			cerr << "Current pos: " << currPac.cell.pellet << endl;
			
			int cellIndex = BreadthFirstSearchService::FindNextPellet(currPac.cell, 10);
			if (cellIndex == -1)
			{
				cellIndex = BreadthFirstSearchService::FindNextPellet(currPac.cell, 1);
			}

			Cell cell = Map::GetCellByIndex(cellIndex);
			cerr << cell.x << ", " << cell.y << ": " << cell.pellet << endl;
			
			returnStr += MOVE + " " 
				+ to_string(currPac.pacId) + " "
				+ to_string(cell.x) + " " 
				+ to_string(cell.y) + " | "; // MOVE <pacId> <x> <y>
		}
		
		return returnStr; 
	}

private:
	Game& game;
	Player& p1;
	Player& p2;

	const std::string MOVE = "MOVE";
};


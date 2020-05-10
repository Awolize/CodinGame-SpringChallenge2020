#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>

class Cell
{
public:
	inline Cell() : x(-1), y(-1), type('*') {};
	inline Cell(int x, int y, char type) : x(x), y(y), type(type) {};
	inline Cell(int x, int y, char type, int value) : x(x), y(y), type(type), pellet(value) {};
	int index(); //  { return x + (y * Map::width); }
	void setPellet(int newPellet) { pellet = newPellet; };
	inline operator std::string() const { return x + " " + y; };

public:
	int x;
	int y;
	char type;
	int pellet = 0;
	std::unordered_map<char, Cell*> neighbors;
};


class Direction
{
public:
	Direction(int x, int y, char d) : dx(x), dy(y), dir(d) {};
	int dx;
	int dy;
	char dir;
};

class Map
{
public:
	static Cell GetCell(int x, int y) { return Board[x + (y * width)]; };
	static Cell GetCellByIndex(int index) { return Board[index]; };
	static Cell& GetCellRef(int x, int y) { return Board[x + (y * width)]; };
	static void AddCell(Cell cell) { Board.push_back(cell); };

	static void UpdateCell(int x, int y, int value) 
	{ 
		GetCellRef(x, y).pellet = value;
	};

	static bool IsValid(int x, int y) { return (x >= 0 && y >= 0 && x < width && y < height); };
	static void Initilize()
	{
		for (auto& cell : Board)
		{
			if (cell.type == ' ')
				SetupCell(cell);
		}
	}
private:
	static void SetupCell(Cell& cell)
	{
		Direction neighbors[4] = { Direction(0,-1,'N'), Direction(0,1,'S'),
			Direction(-1,0,'W'), Direction(1,0,'E') };
		for (size_t i = 0; i < 4; i++)
		{
			int x = cell.x + neighbors[i].dx;
			int y = cell.y + neighbors[i].dy;
			if (IsValid(x, y))
				if (GetCell(x, y).type == ' ')
				{
					cell.neighbors[neighbors[i].dir] = &GetCellRef(x, y);
				}

		}
	}

public:
	static std::vector<Cell> Board;
	static int width;
	static int height;
};


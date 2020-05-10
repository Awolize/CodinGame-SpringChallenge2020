#include <vector>
#include "Map.h"

std::vector<Cell> Map::Board;
int Map::width;
int Map::height;

int Cell::index()
{
    return x + (y * Map::width);
}

#pragma once
#include <queue>
#include <unordered_set>
#include "Map.h"

class BreadthFirstSearchService
{
public:
	static int FindNextPellet(Cell currentCell, int goal)
	{
		std::queue<int> q; // Nodes to explore
		std::unordered_set<int> visited;

		Cell curr = currentCell;
		q.push(curr.index());
		visited.insert(curr.index());

		while (!q.empty())
		{
			curr = Map::GetCellByIndex(q.front());
			q.pop();

			for (auto neigh : curr.neighbors)
			{
				Cell toFind = *neigh.second;

				if (visited.find(neigh.second->index()) != visited.end())
					continue;

				if (toFind.pellet == goal)
					return toFind.index();

				visited.insert(neigh.second->index());
				q.push(neigh.second->index());
			}
		}

		return -1;
	}
};

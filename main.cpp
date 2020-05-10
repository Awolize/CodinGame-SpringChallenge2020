#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Map.h"
#include "Game.h"
#include "ReadInput.h"
#include "ReactAgent.h"

using namespace std;


int main()
{
    ReadInput::Initilize();
    Map::Initilize();
    Game lastGame;

    while (1) {
        Game game = ReadInput::ReadRound(lastGame);

        ReactAgent agent(game);
        std::string result = agent.think();

        std::cout << result << endl;

        lastGame = game;
    }
}
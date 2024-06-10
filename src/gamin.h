#pragma once

class Game
{
public:
    Game();
    void GameUpdate();
    void GameDraw();
    void GameGridRender();
    bool wevegotawinner();
    char key;
    int loc;
    int PlayerTurnCount;
    char winner;
    bool failmove;
    int gamearr[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
};
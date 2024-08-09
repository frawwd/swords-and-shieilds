#pragma once

class Game
{
public:
    Game();
    void GameUpdate();
    void GameDraw();
    void GameGridRender();
    bool wevegotawinner();
    void GameClear();
    void GameEasyComputer();
    char key;
    bool comturn;
    int loc;
    int PlayerTurnCount;
    bool failmove;
    int gamearr[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    int Mode; // 1 for single , 2 for verses , 3 for online

private:
    bool canmove2(int x, int y);
};
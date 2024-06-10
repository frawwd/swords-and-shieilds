#include <raylib.h>
#include "gamin.h"

int main()
{
    SetTraceLogLevel(LOG_ERROR); // rem ugllyy

    Color dark = Color{10, 10, 10, 255};
    Color red = Color{200, 40, 40, 255};

    const int screenWidth = 900;
    const int screenHeight = 1000;

    Game game = Game();

    InitWindow(screenWidth, screenHeight, " on'x");
    SetTargetFPS(60);

    ClearBackground(dark);
    
    game.key = 's';

    game.PlayerTurnCount = 0;
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(dark);

        game.GameGridRender();
        game.GameDraw();

        if (game.PlayerTurnCount == 0) {
            if(IsKeyPressed(KEY_KP_0)){
                if(game.key == 'o'){
                    game.key = 'x';
                }
                else {
                    game.key = 'o';
                }
            }
        }
        if (game.wevegotawinner() == true){   
            if (game.key == 'x'){ 
                DrawText("O has won", 300, 915, 60, red);
            } else if (game.key == 'o'){
                DrawText("X has won", 300, 915, 60, red);
            }
            //DrawText(TextFormat("%c has won", game.key), 300, 915, 60, red);
        } 
        else if (game.PlayerTurnCount > 8) {
            DrawText("Its a Draw", 300, 915, 60, red);
        }
        else if (game.key == 's') {
            DrawText("Pick who starts", 240, 915, 60, red);
        }
        else if (game.PlayerTurnCount == 0) {
            if (game.key == 'x'){
                DrawText("X to move first", 220, 915, 60, red);
            } 
            else if (game.key == 'o') {
                DrawText("O to move first", 220, 915, 60, red);
            } 
        }
        else if (game.key == 'x'){
            DrawText("X to move", 300, 915, 60, red);
        } 
        else if (game.key == 'o') {
            DrawText("O to move", 300, 915, 60, red);
        } 
        else {
            DrawText("Pick who starts", 240, 915, 60, red);
        }

        if (!game.wevegotawinner()) {
            if(IsKeyPressed(KEY_KP_7)){
                game.loc = 1;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_8)){
                game.loc = 2;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_9)){
                game.loc = 3;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_4)){
                game.loc = 4;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_5)){
                game.loc = 5;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_6)){
                game.loc = 6;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_1)){
                game.loc = 7;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_2)){
                game.loc = 8;
                game.GameUpdate();
            }
            if(IsKeyPressed(KEY_KP_3)){
                game.loc = 9;
                game.GameUpdate();
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

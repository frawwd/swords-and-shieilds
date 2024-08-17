#include <raylib.h>
#include "gamin.h"
#include "button.h"

typedef enum GameScreen {
    TITLE = 0,
    GAME,
    SETTINGS
}
GameScreen;
int main()
{
    SetTraceLogLevel(LOG_ERROR); // rem ugllyy

    Color dark = Color{ 10, 10, 10, 255 };
    Color red = Color{ 200, 40, 40, 255 };

    const int screenWidth = 900;
    const int screenHeight = 1000;

    Game game = Game();
    Button SinglePlayerButton = Button();
    Button MultiPlayerButton = Button();
    Button SettingButton = Button();
    Button ExitButton = Button();
    Button SettingMenuButton = Button();

    InitWindow(screenWidth, screenHeight, "Swords And Shields");
    GameScreen currentScreen = TITLE;
    SetTargetFPS(60);

    ClearBackground(dark);
    SetMousePosition(screenWidth / 2, 200);

    bool windowshouldbeopen = true;
    while (windowshouldbeopen) {
        if (WindowShouldClose()) {
            windowshouldbeopen = false;
        }

        int mousePosx = GetMouseX();
        int mousePosy = GetMouseY();

        switch (currentScreen)
        {
        case TITLE:
        {
            if (ExitButton.ButtonCheck(mousePosx, mousePosy) && IsMouseButtonPressed(0)) {
                windowshouldbeopen = false;
            }
            if (SinglePlayerButton.ButtonCheck(mousePosx, mousePosy) && IsMouseButtonPressed(0)) {
                game.Mode = 1;
                currentScreen = GAME;
                game.GameClear();
            }
            if (MultiPlayerButton.ButtonCheck(mousePosx, mousePosy) && IsMouseButtonPressed(0)) {
                game.Mode = 2;
                currentScreen = GAME;
                game.GameClear();
            }
            if (SettingButton.ButtonCheck(mousePosx, mousePosy) && IsMouseButtonPressed(0)) {
                currentScreen = SETTINGS;
            }
        } break;
        case GAME:
        {
            game.gamenotwon = game.wevegotawinner();
            if (!game.gamenotwon && game.key != 's') {
                if (IsKeyPressed(KEY_KP_7)) {
                    game.loc = 1;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                        game.gamenotwon = game.wevegotawinner();
                        game.swapkey();
                    }
                }
                if (IsKeyPressed(KEY_KP_8)) {
                    game.loc = 2;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_9)) {
                    game.loc = 3;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_4)) {
                    game.loc = 4;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_5)) {
                    game.loc = 5;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_6)) {
                    game.loc = 6;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_1)) {
                    game.loc = 7;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_2)) {
                    game.loc = 8;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
                if (IsKeyPressed(KEY_KP_3)) {
                    game.loc = 9;
                    game.GameUpdate();
                    if (game.Mode == 1) {
                        game.GameEasyComputer();
                    }
                }
            }
            // for single player com move;;;

            if (IsKeyPressed(KEY_KP_0)) {
                if (game.wevegotawinner()) {
                    currentScreen = TITLE;
                }
                if (game.PlayerTurnCount > 8) {
                    currentScreen = TITLE;
                }
            }
            if (IsKeyPressed(KEY_SPACE)) {
                currentScreen = TITLE;
            }
        } break;
        case SETTINGS:
        {
            if (SettingMenuButton.ButtonCheck(mousePosx, mousePosy) && IsMouseButtonPressed(0)) {
                currentScreen = TITLE;
            }
        } break;
        default: break;
        }
        BeginDrawing();
        ClearBackground(dark);
        switch (currentScreen)
        {
        case TITLE:
        {
            DrawText("Swords And Shields", 60, 60, 80, red);
            SinglePlayerButton.TextOutlineButton("SinglePlayer", 250, 300, 425, 100, 60, red);
            SinglePlayerButton.textAjustmentX = 25;
            SinglePlayerButton.textAjustmentY = 20;
            MultiPlayerButton.TextOutlineButton("MultiPlayer", 260, 420, 405, 100, 60, red);
            MultiPlayerButton.textAjustmentX = 35;
            MultiPlayerButton.textAjustmentY = 20;
            SettingButton.TextOutlineButton("Settings", 300, 540, 300, 100, 60, red);
            SettingButton.textAjustmentX = 30;
            SettingButton.textAjustmentY = 20;
            ExitButton.TextOutlineButton("Exit", 300, 800, 300, 100, 60, red);
            ExitButton.textAjustmentX = 90;
            ExitButton.textAjustmentY = 20;
            //DrawText(TextFormat("mx: %i", mousePosx), 0, 0, 10, BLUE);
            //DrawText(TextFormat("my: %i", mousePosy), 0, 10, 10, BLUE);
        } break;
        case GAME:
        {
            game.GameGridRender();
            game.GameDraw();
            if (game.PlayerTurnCount == 0) {
                if (IsKeyPressed(KEY_KP_0)) {
                    if (game.key == 'o') {
                        game.key = 'x';
                    }
                    else {
                        game.key = 'o';
                    }
                }
            }
            if (game.wevegotawinner()) {
                if (game.Mode == 1) {
                    if (game.key == 'o') {
                        DrawText("O has won, Press 0", 30, 915, 60, red);
                    }
                    else if (game.key == 'x') {
                        DrawText("X has won, Press 0", 30, 915, 60, red);
                    }
                }
                else {
                    if (game.key == 'x') {
                        DrawText("O has won, Press 0", 30, 915, 60, red);
                    }
                    else if (game.key == 'o') {
                        DrawText("X has won, Press 0", 30, 915, 60, red);
                    }
                }
                // is inversed in multiplayer?
            }
            else if (game.PlayerTurnCount > 8) {
                DrawText(" Draw, Press 0.", 30, 915, 60, red);
            }
            else if (game.key == 's') {
                DrawText("Press 0 to select", 30, 915, 60, red);
            }
            else if (game.PlayerTurnCount == 0) {
                if (game.key == 'x') {
                    DrawText("X to move first", 30, 915, 60, red);
                }
                else if (game.key == 'o') {
                    DrawText("O to move first", 30, 915, 60, red);
                }
            }
            else if (game.key == 'x') {
                DrawText("X to move", 30, 915, 60, red);
            }
            else if (game.key == 'o') {
                DrawText("O to move", 30, 915, 60, red);
            }
            else {
                DrawText("rerrer", 30, 915, 60, red);
            }

        } break;
        case SETTINGS:
        {
            DrawText("SETTINGS", 300, 50, 50, BLUE);
            DrawText("Space: Takes you to menu", 30, 100, 40, BLUE);
            DrawText("NumPad: Keys 1-9 corispond to the grid ", 30, 150, 40, BLUE);
            DrawText("Numpad 0: Is used to start and end", 30, 200, 40, BLUE);
            DrawText("This is truly left wide open", 30, 250, 40, BLUE);
            DrawText("ensuring hundreds takes you compilation", 30, 300, 40, BLUE);

            SettingMenuButton.TextOutlineButton("Menu", 300, 800, 300, 100, 60, BLUE);
            SettingMenuButton.textAjustmentX = 80;
            SettingMenuButton.textAjustmentY = 20;
        } break;
        default: break;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

#include <raylib.h>
#include "button.h"

Color clear = Color{ 255,255,255, 0 };

Button::Button()
{
    butX = 0; butY = 0; butW = 0, butH = 0;
    textAjustmentX = 0;
    textAjustmentY = 0;

}

void Button::TextButton(const char text[], int PosX, int PosY, int Width, int Hight, int fs, Color color) {
    DrawText(text, PosX + textAjustmentX, PosY + textAjustmentY, fs, color);
    DrawRectangle(PosX, PosY, Width, Hight, clear);
    butX = PosX; butY = PosY; butW = Width; butH = Hight;
}

void Button::TextOutlineButton(const char text[], int PosX, int PosY, int Width, int Hight, int fs, Color color) {
    DrawText(text, PosX + textAjustmentX, PosY + textAjustmentY, fs, color);
    DrawRectangleLines(PosX, PosY, Width, Hight, color);
    butX = PosX; butY = PosY; butW = Width; butH = Hight;
}

bool Button::ButtonCheck(int MouseX, int MouseY) {
    int x2 = butX + butW;
    int y2 = butY + butH;

    if (MouseX > butX && MouseY > butY && MouseX < x2 && MouseY < y2) {
        return true;
    }

    return false;
}
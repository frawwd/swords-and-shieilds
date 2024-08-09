#pragma once

class Button
{
public:
    Button();
    void TextButton(const char text[], int PosX, int PosY, int Width, int Hight, int fs, Color color);
    //void OutlineButton(char text[], int PosX, int PosY, int Width, int Hight, int fs, Color color);
    void TextOutlineButton(const char text[], int PosX, int PosY, int Width, int Hight, int fs, Color color);

    bool ButtonCheck(int mx, int my);
    int butX, butY, butW, butH;
    int textAjustmentX, textAjustmentY;
};
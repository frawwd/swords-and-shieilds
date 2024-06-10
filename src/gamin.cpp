#include "gamin.h"
#include <raylib.h>

Color red = Color{200, 40, 40, 255};

Game::Game()
{
    PlayerTurnCount = 0;
}

void Game::GameUpdate()
{
    failmove = false;
    switch (loc)
    {
    case 1:

    if (gamearr[0][0] == 0) { 
        if (key == 'x') {
            gamearr[0][0] = 2;
        }
        else if (key == 'o') {
            gamearr[0][0] = 3;
        }
    } else { failmove = true; }
    break;
    case 2:
    if (gamearr[0][1] == 0) { 
        if (key == 'x') {
            gamearr[0][1] = 2;
        }
        else if (key == 'o') {
            gamearr[0][1] = 3;
        }        
    } else { failmove = true; }
    break;
    case 3:
    if (gamearr[0][2] == 0) { 
        if (key == 'x') {
            gamearr[0][2] = 2;
        }
        else if (key == 'o') {
            gamearr[0][2] = 3;
        }
    } else { failmove = true; }     
    break;
    case 4:
    if (gamearr[1][0] == 0) { 
        if (key == 'x') {
            gamearr[1][0] = 2;
        }
        else if (key == 'o') {
            gamearr[1][0] = 3;
        }
    } else { failmove = true; }        
    break;
    case 5:
    if (gamearr[1][1] == 0) { 
        if (key == 'x') {
            gamearr[1][1] = 2;
        }
        else if (key == 'o') {
            gamearr[1][1] = 3;
        }
    } else { failmove = true; }       
    break;
    case 6:
    if (gamearr[1][2] == 0) { 
        if (key == 'x') {
            gamearr[1][2] = 2;
        }
        else if (key == 'o') {
            gamearr[1][2] = 3;
        }
    } else { failmove = true; }          
    break;
    case 7:
    if (gamearr[2][0] == 0) { 
        if (key == 'x') {
            gamearr[2][0] = 2;
        }
        else if (key == 'o') {
            gamearr[2][0] = 3;
        }
    } else { failmove = true; }      
    break;
    case 8:
    if (gamearr[2][1] == 0) { 
        if (key == 'x') {
            gamearr[2][1] = 2;
        }
        else if (key == 'o') {
            gamearr[2][1] = 3;
        }
    } else { failmove = true; }        
    break;
    case 9:
    if (gamearr[2][2] == 0) { 
        if (key == 'x') {
            gamearr[2][2] = 2;
        }
        else if (key == 'o') {
            gamearr[2][2] = 3;
        }
    } else { failmove = true; }        
    break;
    }
    loc = 0;
    if (!failmove){
        PlayerTurnCount++;
        if (key == 'x'){
            key = 'o';
        } else if (key == 'o') {
            key = 'x';
        }
    }
}
void Game::GameGridRender()
{
    DrawRectangleLines(300,0,300,300,red);
    DrawRectangleLines(600,0,300,300,red);

    DrawRectangleLines(0,300,300,300,red);
    DrawRectangleLines(0,600,300,300,red);

    DrawRectangleLines(300,600,300,300,red);
    DrawRectangleLines(600,300,300,300,red);

    DrawRectangleLines(0,0,300,300,red);
    DrawRectangleLines(300,300,300,300,red);
    DrawRectangleLines(600,600,300,300,red);

}
void Game::GameDraw()
{
    // 1
    if (gamearr[0][0] == 2){
        DrawLine(0, 0, 300, 300, red);
        DrawLine(0, 300, 300, 0, red);
    }
    else if (gamearr[0][0] == 3){
        DrawCircleLines(150, 150, 120, red);
    }
    // 2
    if (gamearr[0][1] == 2){
        DrawLine(300, 0, 600, 300, red);
        DrawLine(300, 300, 600, 0, red);
    }
    else if (gamearr[0][1] == 3){
        DrawCircleLines(450, 150, 120, red);
    }
    // 3
    if (gamearr[0][2] == 2){
        DrawLine(600, 300, 900, 0, red);
        DrawLine(600, 0, 900, 300, red);
    }
    else if (gamearr[0][2] == 3){
        DrawCircleLines(750, 150, 120, red);
    }
    // 4
    if (gamearr[1][0] == 2){
        DrawLine(0, 300, 300, 600, red);
        DrawLine(0, 600, 300, 300, red);
    }
    else if (gamearr[1][0] == 3){
        DrawCircleLines(150, 450, 120, red);
    }
    // 5
    if (gamearr[1][1] == 2){
        DrawLine(300, 300, 600, 600, red);
        DrawLine(300, 600, 600, 300, red);
    }
    else if (gamearr[1][1] == 3){
        DrawCircleLines(450, 450, 120, red);
    }
    // 6
    if (gamearr[1][2] == 2){
        DrawLine(600, 600, 900, 300, red);    
        DrawLine(600, 300, 900, 600, red);
    }
    else if (gamearr[1][2] == 3){
        DrawCircleLines(750, 450, 120, red);
    }
    // 7
    if (gamearr[2][0] == 2){
        DrawLine(0, 600, 300, 900, red);
        DrawLine(0, 900, 300, 600, red);
    }
    else if (gamearr[2][0] == 3){
        DrawCircleLines(150, 750, 120, red);
    }
    // 8
    if (gamearr[2][1] == 2){
        DrawLine(300, 600, 600, 900, red);
        DrawLine(300, 900, 600, 600, red);
    }
    else if (gamearr[2][1] == 3){
        DrawCircleLines(450, 750, 120, red);
    }
    // 9
    if (gamearr[2][2] == 2){
        DrawLine(600, 600, 900, 900, red);
        DrawLine(900, 600, 600, 900, red);
    }
    else if (gamearr[2][2] == 3){
        DrawCircleLines(750, 750, 120, red);
    }
}

bool Game::wevegotawinner(){
    for (int i = 0; i < 2; i++) {
        if (gamearr[i][0] != 0){
            if (gamearr[i][0] == gamearr[i][1] && gamearr[i][1] == gamearr[i][2]){ // horri
                return true;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        if (gamearr[0][i] != 0){
            if (gamearr[0][i] == gamearr[1][i] && gamearr[1][i] == gamearr[2][i]){ // verti
                return true;
            }
        }
    }
    if (gamearr[0][2] != 0){
        if (gamearr[0][2] == gamearr[1][2] && gamearr[1][2] == gamearr[2][2]){ // verti 2
            return true;
        }  
    }
    if (gamearr[2][0] != 0){
        if (gamearr[2][0] == gamearr[2][1] && gamearr[2][1] == gamearr[2][2]){ // verti 2
            return true;
        }  
    }
    if (gamearr[0][0] != 0){
        if(gamearr[0][0] == gamearr[1][1] && gamearr[1][1] == gamearr[2][2]){  // diag 1
            return true;
        }
    }
    if (gamearr[2][0] != 0) { 
        if(gamearr[2][0] == gamearr[1][1] && gamearr[1][1] == gamearr[0][2]){  // diag 2
            return true;
        }
    }
    return false;
}

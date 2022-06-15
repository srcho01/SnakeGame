#include "map.h"
Map *gameMap = new Map;

#include "gameUI.h"
#include "kbhit.h"
#include "PlayGame.h"
#include <iostream>
#include <ncurses.h>
using namespace std;


int main() { 
    GameUI gameUI;
    int handle;
    int handlePrev = 'D';
    while(gameUI.playgame->playing()) {
        gameUI.update(100000); // ���� : microseconds (1s = 1000000ms)
        gameUI.updateScore(10000);
        gameUI.updateMission(10000);

        if(kbhit()){
            handle = getch();
            //cout << handle << endl;
        }
        else{
            if(gameUI.playgame->snake->headDirection == 1) handlePrev = 'D';
            else if(gameUI.playgame->snake->headDirection == 2) handlePrev = 'C';
            else if(gameUI.playgame->snake->headDirection == 3) handlePrev = 'A';
            else if(gameUI.playgame->snake->headDirection == 4) handlePrev = 'B';
            handle = handlePrev;
        }
        if(gameUI.playgame->snake->headDirection == 1){
            gameUI.playgame->snake->move_left();
            handlePrev = 'D';
        }
        else if(gameUI.playgame->snake->headDirection == 2){
            gameUI.playgame->snake->move_right();
            handlePrev = 'C';
        }
        else if(gameUI.playgame->snake->headDirection == 3){
            gameUI.playgame->snake->move_up();
            handlePrev = 'A';
        }
        else if(gameUI.playgame->snake->headDirection == 4){
            gameUI.playgame->snake->move_down();
            handlePrev = 'B';
        }
        if(handle == 'C'){
            gameUI.playgame->snake->headDirection = 2;
            handlePrev = 'C';
        }
        else if(handle == 'D'){
            handlePrev = 'D';
            gameUI.playgame->snake->headDirection = 1;
        }
        else if(handle == 'A'){
            gameUI.playgame->snake->headDirection = 3;
            handlePrev = 'A';
        }
        else if(handle == 'B'){
            gameUI.playgame->snake->headDirection = 4;
            handlePrev = 'B';   
        }
    }
}
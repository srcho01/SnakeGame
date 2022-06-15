#include "map.h"
Map *gameMap = new Map;

#include "gameUI.h"
#include "PlayGame.h"
#include "kbhit.h"
#include <iostream>
#include <ncurses.h>
using namespace std;
int main() {
    GameUI gameUI;
    PlayGame playgame; 
    int handle;
    int handlePrev = 'D';
    while(playgame.playing()) {
        gameUI.update(100000); // ���� : microseconds (1s = 1000000ms)

        if(kbhit()){
            handle = getch();
            //cout << handle << endl;
        }
        else{
            if(playgame.snake->headDirection == 1) handlePrev = 'D';
            else if(playgame.snake->headDirection == 2) handlePrev = 'C';
            else if(playgame.snake->headDirection == 3) handlePrev = 'A';
            else if(playgame.snake->headDirection == 4) handlePrev = 'B';
            handle = handlePrev;
        }
        if(playgame.snake->headDirection == 1){
            playgame.snake->move_left();
            handlePrev = 'D';
        }
        else if(playgame.snake->headDirection == 2){
            playgame.snake->move_right();
            handlePrev = 'C';
        }
        else if(playgame.snake->headDirection == 3){
            playgame.snake->move_up();
            handlePrev = 'A';
        }
        else if(playgame.snake->headDirection == 4){
            playgame.snake->move_down();
            handlePrev = 'B';
        }
        if(handle == 'C'){
            playgame.snake->headDirection = 2;
            handlePrev = 'C';
        }
        else if(handle == 'D'){
            handlePrev = 'D';
            playgame.snake->headDirection = 1;
        }
        else if(handle == 'A'){
            playgame.snake->headDirection = 3;
            handlePrev = 'A';
        }
        else if(handle == 'B'){
            playgame.snake->headDirection = 4;
            handlePrev = 'B';   
        }
    }
}
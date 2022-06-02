#include "map.h"
Map *gameMap = new Map;

#include "gameUI.h"
#include "PlayGame.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {
    GameUI gameUI;
    PlayGame playgame;
    while(playgame.playing()) {
        gameUI.update(1000000); // ���� : microseconds (1s = 1000000ms)
        int handle = getch();
        if(handle == 67){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_right();
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 68){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_left();
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

        }
        else if(handle == 65){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_up();
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 66){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_down();
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }

    }
}
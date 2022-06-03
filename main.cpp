#include "map.h"
Map *gameMap = new Map;

#include "gameUI.h"
#include "PlayGame.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

void mapUpdate(Map &map, Snake snake){
    int hx = snake.getHeadPos()[1];
    int hy = snake.getHeadPos()[0];
    map.changeMap(hy, hx, 3);
    for(int i = 0; i < snake.getBodyLen(); i++){
        int mx = snake.getBodyPos(i)[1];
        int my = snake.getBodyPos(i)[0];
        map.changeMap(my, mx, 4);
    }
    int tx = snake.getTailPos()[1];
    int ty = snake.getTailPos()[0];
    map.changeMap(ty, tx, 4);
}

int main() {
    GameUI gameUI;
    PlayGame playgame;
    while(playgame.playing()) {
        gameUI.update(1000000); // ���� : microseconds (1s = 1000000ms)
        int handle = getch();
        int handlePrev;
        if(handle == 67){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_right();
            handlePrev = 67;
            mapUpdate(gameMap, playgame.snake)
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 68){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_left();
            handlePrev = 68;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

        }
        else if(handle == 65){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_up();
            handlePrev = 65;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 66){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_down();
            handlePrev = 66;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else{
            if(handlePrev == 67){
                //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
                playgame.snake->move_right();
                //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
            }
            else if(handlePrev == 68){
                //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
                playgame.snake->move_left();
                //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

            }
            else if(handlePrev == 65){
                //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
                playgame.snake->move_up();
                //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
            }
            else if(handlePrev == 66){
                //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
                playgame.snake->move_down();
                //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
            }
        }

    }
}
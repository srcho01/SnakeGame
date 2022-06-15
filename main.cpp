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


    while(playgame.playing()) {
        gameUI.update(1000000); // ���� : microseconds (1s = 1000000ms)
        int handle= 68;
        int handlePrev = KEY_LEFT;

        if(kbhit()){
            handle = getch();
            //cout << handle << endl;
        }
        else{
            handle = handlePrev;
        }
        //cout << handle << endl;
        if(handle == KEY_RIGHT){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_right();
            handlePrev = KEY_RIGHT;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == KEY_LEFT){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_left();
            handlePrev = KEY_LEFT;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

        }
        else if(handle == KEY_UP){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_up();
            handlePrev = KEY_UP;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == KEY_DOWN){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_down();
            handlePrev = KEY_DOWN;
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        // else{
        //     if(handlePrev == 67){
        //         //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
        //         playgame.snake->move_right();
        //         //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        //     }
        //     else if(handlePrev == 68){
        //         //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
        //         playgame.snake->move_left();
        //         //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

        //     }
        //     else if(handlePrev == 65){
        //         //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
        //         playgame.snake->move_up();
        //         //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        //     }
        //     else if(handlePrev == 66){
        //         //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
        //         playgame.snake->move_down();
        //         //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        //     }
        //}

    }
}
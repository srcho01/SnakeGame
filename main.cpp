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
        gameUI.update(500000); // ���� : microseconds (1s = 1000000ms)

        if(kbhit()){
            handle = getch();
            //cout << handle << endl;
        }
        else{
            handle = handlePrev;
            //cout << handle << endl;
        }
        //cout << handle << endl;
        if(handle == 'C'){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_right();
            handlePrev = 'C';
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 'D'){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_left();
            handlePrev = 'D';
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;

        }
        else if(handle == 'A'){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_up();
            handlePrev = 'A';
            //cout << " next " << playgame.snake->getHeadPos()[0]<<" "<<playgame.snake->getHeadPos()[1] << endl;
        }
        else if(handle == 'B'){
            //cout << " prev " << playgame.snake->getHeadPos()[0] <<" "<<playgame.snake->getHeadPos()[1] << endl;
            playgame.snake->move_down();
            handlePrev = 'B';
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
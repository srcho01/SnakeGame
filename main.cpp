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
            //cout << handle << endl;
        }
        //cout << handle << endl;
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
            //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;;
            gameUI.playgame->snake->headDirection = 2;
            handlePrev = 'C';

            //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        }
        else if(handle == 'D'){
            //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
            handlePrev = 'D';
            gameUI.playgame->snake->headDirection = 1;
            //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;

        }
        else if(handle == 'A'){
            //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
            gameUI.playgame->snake->headDirection = 3;
            handlePrev = 'A';
            //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        }
        else if(handle == 'B'){
            //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
            gameUI.playgame->snake->headDirection = 4;
            handlePrev = 'B';   
            //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        }

        // else{
        //     if(handlePrev == 67){
        //         //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //         gameUI.playgame->snake->move_right();
        //         //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //     }
        //     else if(handlePrev == 68){
        //         //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //         gameUI.playgame->snake->move_left();
        //         //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;

        //     }
        //     else if(handlePrev == 65){
        //         //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //         gameUI.playgame->snake->move_up();
        //         //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //     }
        //     else if(handlePrev == 66){
        //         //cout << " prev " << gameUI.playgame->snake->getHeadPos()[0] <<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //         gameUI.playgame->snake->move_down();
        //         //cout << " next " << gameUI.playgame->snake->getHeadPos()[0]<<" "<<gameUI.playgame->snake->getHeadPos()[1] << endl;
        //     }
        //}

    }
}
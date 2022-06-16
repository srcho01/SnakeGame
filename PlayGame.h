#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#include <ctime>
#include "map.h"
#include "snake.h"
#include "Item.h"
#include "Gate.h"

extern Map *gameMap;
class PlayGame {
private:
    int mission[4][4] =  // 미션 달성을 위한 몸 최소 길이, 획득해야 할 Growth Item 수, 획득해야 할 Poison Item 수, Gate 사용 횟수
    {
        {4, 1, 0, 0}, // stage 1
        {4, 1, 1, 1}, // stage 2
        {5, 2, 2, 1}, // stage 3
        {6, 2, 2, 2} // stage 
    };
    int bodyLen = 3, growthNum = 0, poisonNum = 0, gateNum = 0;
    bool win;
    time_t startTime;

public:
    int currStage;
    bool success[4] = {false, false, false, false};
    Snake *snake;
    Item *item;
    Gate *gate;

    PlayGame();
    bool playing();
    void playingStage(int stage);
    void countPoint();
    bool isWin() {return win;};
    int getMission(int x, int y) {return mission[x][y];}
    int getBodyNum() {return bodyLen;}
    int getGrowthNum() {return growthNum;}
    int getPoisonNum() {return poisonNum;}
    int getGateNum() {return gateNum;}
    time_t getStartTime() {return startTime;}
};

#endif
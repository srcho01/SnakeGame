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
    int mission[4][5] =  // 미션 달성을 위한 몸 최소 길이, 획득해야 할 Growth Item 수, 획득해야 할 Poison Item 수, Gate 사용 횟수
    {
        {3, 1, 0, 0}, // stage 1
        {3, 2, 0, 0}, // stage 2
        {4, 3, 0, 0}, // stage 3
        {16, 6, 4, 6} // stage 4
    };
    int bodyLen = 3, growthNum = 0, poisonNum = 0;
    double gateNum = 0;
    time_t startTime;

public:
    int currStage;
    bool success[5] = {false, false, false, false, false};
    bool win;
    Snake *snake;
    Item *item;
    Gate *gate;

    PlayGame();
    bool playing();
    void playingStage(int stage);
    void countPoint();
    int getGrowthNum() {return growthNum;}
    int getPoisonNum() {return poisonNum;}
    int getGateNum() {return gateNum;}
    time_t getStartTime() {return startTime;}
};

#endif
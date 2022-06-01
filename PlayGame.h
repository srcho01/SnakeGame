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
    int mission[4][5] =  // ¹Ì¼Ç ´Þ¼ºÀ» À§ÇÑ ¸ö ÃÖ¼Ò ±æÀÌ, È¹µæÇØ¾ß ÇÒ Growth Item ¼ö, È¹µæÇØ¾ß ÇÒ Poison Item ¼ö, Gate »ç¿ë È½¼ö
    {
        {7, 2, 1, 1,}, // stage 1
        {10, 3, 2, 3}, // stage 2
        {13, 5, 3, 4}, // stage 3
        {16, 6, 4, 6} // stage 4
    };
    int bodyLen = 3, growthNum = 0, poisonNum = 0, gateNum = 0;
    bool success[5] = {false, false, false, false, false};
    time_t startTime;
    int currStage;

    Snake *snake;
    Item *item;
    Gate *gate;
public:
    bool win;

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
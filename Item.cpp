#include "Item.h"
#include <cstdlib>
#include <ctime>

void Item::makeGrowth(int stage, const time_t &startTime) {
    if((time(NULL) - startTime) % 15 == 0 && growth.size() != 0) {
        for(int i=0; i<growth.size(); i+=2)
            gameMap->changeMap(growth[i], growth[i+1], 0);
        growth.clear();
    }
    int num = 2 - (stage-1) / 2; // 만들 growth item의 개수 : stage 1, 2 = 2, stage 3, 4 = 1
    while(growth.size() != num * 2) {
        srand(time(NULL));
        int x = rand() % 25;
        int y = rand() % 25;
        if(gameMap->getPosition(x, y) == 0) {
            gameMap->changeMap(x, y, 5);
            growth.push_back(x); growth.push_back(y);
        }
    }
}

void Item::makePoison(int stage, const time_t &startTime) {
    if((time(NULL) - startTime) % 15 == 1 && poison.size() != 0) {
        for(int i=0; i<poison.size(); i+=2)
            gameMap->changeMap(poison[i], poison[i+1], 0);
        poison.clear();
    }
    int num = (stage-1) / 2 + 1; // 만들 growth item의 개수 : stage 1, 2 = 1, stage 3, 4 = 2
    while(poison.size() != num * 2) {
        srand(time(NULL));
        int x = rand() % 25;
        int y = rand() % 25;
        if(gameMap->getPosition(x, y) == 0) {
            gameMap->changeMap(x, y, 6);
            poison.push_back(x); poison.push_back(y);
        }
    }
}
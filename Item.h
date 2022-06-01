#ifndef _ITEM_H_
#define _ITEM_H_

#include "map.h"
#include <vector>
extern Map *gameMap;

class Item {
private:
    std::vector<int> growth; // growth 위치
    std::vector<int> poison; // Poison 위치
public:
    void makeGrowth(int stage, const time_t &startTime);
    void makePoison(int stage, const time_t &startTime);
};

#endif
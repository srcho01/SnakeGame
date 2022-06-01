#ifndef _ITEM_H_
#define _ITEM_H_

#include "map.h"
#include <vector>
extern Map *gameMap;

class Item {
private:
    std::vector<int> growth; // growth ��ġ
    std::vector<int> poison; // Poison ��ġ
public:
    void makeGrowth(int stage, const time_t &startTime);
    void makePoison(int stage, const time_t &startTime);
};

#endif
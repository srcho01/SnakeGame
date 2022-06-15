#ifndef _MAP_H_
#define _MAP_H_

#include <string>
#include <vector>
#include "mapData.h"

class Map {
    std::string* map;
    
    int currentStage;
    
public:
    std::vector<int> wall;

    Map(int stage=4);
    void setMap(int stage=1);
    void setWall(int stage);
    int getPosition(int x, int y) {return map[x][y] - '0';}
    int getCurrentStage() {return currentStage;}
    void changeMap(int x, int y, int n) {map[x][y] = n + '0';}
};

#endif
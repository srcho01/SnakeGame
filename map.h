#ifndef _MAP_H_
#define _MAP_H_

#include <string>
#include "mapData.h"

class Map {
    std::string* map;
    int currentStage;
    void changeMap(int x, int y, int n) {map[x][y] = n + '0';}
    
public:
    Map(int stage=1);
    ~Map();
    void setMap(int stage=1);
    int getPosition(int x, int y); 
    int getCurrentStage() {return currentStage;}
    void makeFree(int x, int y);
    void makeHead(int x, int y);
    void makeBody(int x, int y);
    void makeGrowth(int x, int y);
    void makePoison(int x, int y);
    void makeGate(int x1, int y1, int x2, int y2);
};
#endif
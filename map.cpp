#include <string>
#include "mapData.h"
using namespace std;

class Map {
    string* map;

    void changeMap(int x, int y, int n) {map[x][y] = n + '0';}
    
public:
    Map(int stage=1) {
        if(stage == 1) map = stage1;
        else if(stage == 2) map = stage2;
        else if(stage == 3) map = stage3;
        else if(stage == 4) map = stage4;
    }

    void setMap(int stage=1) {
        if(stage == 1) map = stage1;
        else if(stage == 2) map = stage2;
        else if(stage == 3) map = stage3;
        else if(stage == 4) map = stage4;
    }

    int getPosition(int x, int y) {return map[x][y] - '0';}

    void makeGrowth(int x, int y) {
        if(getPosition(x, y) == 0) changeMap(x, y, 5);
    }

    void makePoison(int x, int y) {
        if(getPosition(x, y) == 0) changeMap(x, y, 6);
    }

    void makeGate(int x1, int y1, int x2, int y2) {
        if(getPosition(x1, y1) == 1) changeMap(x1, y1, 7); 
        if(getPosition(x2, y2) == 1) changeMap(x2, y2, 7);
    }
};
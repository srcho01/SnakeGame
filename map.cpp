#include "map.h"

Map::Map(int stage) {
    if(stage == 1) map = stage1;
    else if(stage == 2) map = stage2;
    else if(stage == 3) map = stage3;
    else if(stage == 4) map = stage4;
}

void Map::setMap(int stage) {
    if(stage == 1) map = stage1;
    else if(stage == 2) map = stage2;
    else if(stage == 3) map = stage3;
    else if(stage == 4) map = stage4;
}

int Map::getPosition(int x, int y) {return map[x][y] - '0';} 

void Map::makeFree(int x, int y) {changeMap(x, y, 0);}

void Map::makeHead(int x, int y) {
    if(getPosition(x, y) == 0) changeMap(x, y, 3);
}

void Map::makeBody(int x, int y) {
    if(getPosition(x, y) == 0) changeMap(x, y, 4);
}

void Map::makeGrowth(int x, int y) {
    if(getPosition(x, y) == 0) changeMap(x, y, 5);
}

void Map::makePoison(int x, int y) {
    if(getPosition(x, y) == 0) changeMap(x, y, 6);
}

void Map::makeGate(int x1, int y1, int x2, int y2) {
    if(getPosition(x1, y1) == 1) changeMap(x1, y1, 7); 
    if(getPosition(x2, y2) == 1) changeMap(x2, y2, 7);
}
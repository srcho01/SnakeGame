#include "map.h"

Map::Map(int stage): currentStage(stage) {
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

    setWall(currentStage);
}

void Map::setWall(int stage) {
    for(int i=0; i<25; i++)
        for(int j=0; j<50; j++)
            if(getPosition(i,j) == 1) {
                wall.push_back(i);
                wall.push_back(j);
            }
}
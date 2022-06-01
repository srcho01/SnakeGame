#include "Gate.h"
#include <ctime>
#include <cstdlib>

void Gate::makeGate(int stage, const time_t &startTime) {
    if((time(NULL) - startTime) % 10 == 0 && currGate.size() != 0) {
        for(int i=0; i<currGate.size(); i+=2)
            gameMap->changeMap(currGate[i], currGate[i+1], 1);
        currGate.clear();
    }

    int pNum = gameMap->setWall(stage); // currGate로 만들 수 있는 위치의 좌표를 gameMap의 wall 2차원 벡터에 저장

    srand(time(NULL));
    int p[2] = {-1, -1};
    while(p[0] == p[1]) {
        p[0] = rand() % pNum;
        p[1] = rand() % pNum;
    }

    for(int i: p) {
        currGate.push_back(gameMap->wall[2*i]);
        currGate.push_back(gameMap->wall[2*i+1]);
    }

    for(int i=0; i<4 ; i+=2)
        gameMap->changeMap(currGate[i], currGate[i+1], 7);
}
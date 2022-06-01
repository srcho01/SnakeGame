#include "map.h"
Map *gameMap = new Map;

#include "gameUI.h"
#include "PlayGame.h"
#include <iostream>
using namespace std;

int main() {
    GameUI gameUI;
    PlayGame playgame;
    while(playgame.playing()) {
        gameUI.update(1000000); // ���� : microseconds (1s = 1000000ms)
    }
}
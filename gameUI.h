#ifndef _GAMEUI_H_
#define _GAMEUI_H_

#include "map.h"
extern Map *gameMap;

class GameUI {
public: 
    GameUI();
    ~GameUI();
    void initUI();
    void PrintScore();
    void PrintMission();
    void PrintGame();
    void update(unsigned time);
};
#endif
#ifndef _GAMEUI_H_
#define _GAMEUI_H_

#include "map.h"
#include "PlayGame.h"
extern Map *gameMap;

class GameUI {
public: 
    PlayGame *playgame;

    GameUI();
    ~GameUI();
    void initUI();
    void PrintScore();
    void PrintMission();
    void PrintGame();
    void PrintGameClear();
    void PrintGameOver();
    void update(unsigned time);
};
#endif
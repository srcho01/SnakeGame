#ifndef _GAMEUI_H_
#define _GAMEUI_H_

#include "map.h"
#include "snake.h"
static Map *gameMap;

class GameUI {
private:
    Snake *snake;
public: 
    GameUI();
    ~GameUI();
    void initUI();
    void PrintGame();
    void update(unsigned time);
};
#endif
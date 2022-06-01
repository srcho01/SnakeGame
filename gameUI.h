#include "map.h"

class GameUI {
private:
    Map *gameMap;
    Snake *snake;
public: 
    GameUI();
    ~GameUI();
    void initUI();
    void PrintGame();
    void update(unsigned time);
};
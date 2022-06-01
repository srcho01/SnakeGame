#include "map.h"

class GameUI {
private:
    Map *gameMap;
public: 
    GameUI();
    ~GameUI();
    void initUI();
    void PrintGame();
};
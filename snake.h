#ifndef _SNAKE_H_
#define _SNAKE_H_
#include "map.h"
#include <deque>
#include <algorithm>
using namespace std;
extern Map *gameMap;

class Snake {
private:
    int *head, *tail;
    deque<pair<int, int>> body;

public:
    int headDirection = 75; // left: 75, right: 77, up: 72, down: 80
    int prevHead;
    
    Snake();
    void mapUpdate(int x, int y);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void grow(int itemx, int itemy);
    void posion(int itemx, int itemy);
    void gate(int bodyDirection, int g2x, int g2y);
    int* getHeadPos();
    pair<int,int> getBodyPos(int num);
    int* getTailPos();
    int getBodyLen();
};
#endif
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
    int headDirection;// left: 1, right: 2, up: 3, down: 4
    int prevHead;
    //int gx, gy, gx2, gy2;
    bool check = false;
    
    Snake();
    void mapUpdate(int x, int y);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void grow();
    void posion();
    void gate(int g2x, int g2y, int g1x, int g1y);
    int* getHeadPos();
    pair<int,int> getBodyPos(int num);
    int* getTailPos();
    int getBodyLen();
    // void setGate(int x, int y, int x2, int y2){
    //     gx = x;
    //     gy = y;
    //     gx2 = x2;
    //     gy2 = y2;
    // }
};
#endif
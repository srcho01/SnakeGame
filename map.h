#include <string>
#include "mapData.h"
using namespace std;

class Map {
    string* map;
    void changeMap(int x, int y, int n) {map[x][y] = n + '0';}
    
public:
    Map(int stage=1);
    void setMap(int stage=1);
    int getPosition(int x, int y); 
    void makeFree(int x, int y);
    void makeHead(int x, int y);
    void makeBody(int x, int y);
    void makeGrowth(int x, int y);
    void makePoison(int x, int y);
    void makeGate(int x1, int y1, int x2, int y2);
};
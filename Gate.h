#ifndef _GATE_H_
#define _GATE_H_

#include "map.h"
#include <vector>
extern Map *gameMap;

class Gate {
public:
    std::vector<int> currGate; // ����Ʈ ��ġ

    Gate();
    void makeGate(int stage, const time_t &startTime);
};

#endif
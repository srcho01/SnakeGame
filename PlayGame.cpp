#include "PlayGame.h"

// Encoding : EUC-KR
PlayGame::PlayGame(): win(false) {
    currStage = gameMap->getCurrentStage();
    startTime = time(NULL);
    
    snake = new Snake;
    item = new Item;
    gate = new Gate;
}

bool PlayGame::playing() {
    // item ����
    item->makeGrowth(currStage, startTime); 
    item->makePoison(currStage, startTime);

    // gate ����
    if(gate->currGate.size() == 4) {
        int g1 = gameMap->getPosition(gate->currGate[0], gate->currGate[1]);
        int g2 = gameMap->getPosition(gate->currGate[2], gate->currGate[3]);
        if(g1 == 7 && g2 == 7) gate->makeGate(currStage, startTime); // ���� �������� ���� ���� gate ��ġ ���� X
    } else gate->makeGate(currStage, startTime);

    countPoint(); // ���� ������Ʈ

    playingStage(currStage); // �̼� ���� ���� ����

    // ���� ���з� ����
    int headPos = gameMap->getPosition(snake->getHeadPos()[0], snake->getHeadPos()[1]); // ���� �Ӹ� ��ġ
    if(headPos == 1 || headPos == 2 || headPos == 8) return false; // ������ũ�� ���� ����
    if(headPos == 4) return false; // �ڱ� ���� ���� (���� ����� �ݴ� �������� ���� ��� ����)
    if(snake->getBodyLen() < 1) return false; // �� ���� < 3

    // �̼� ����
    //// �̼� ���� ���� count
    int n = 0; 
    for(bool b: success) if(b) n++;
    
    if(n == 4 && currStage == 4) { // 4�ܰ���� ��� ����
        win = true;
        return false; // ���� ����
    } else if(n == 4) {
        gameMap->setMap(++currStage); // ���� �ܰ�� stage ����

        delete snake;
        snake = new Snake(); // ������ũ ��ü ������Ͽ� �ʱ�ȭ

        int bodyLen = 3, growthNum = 0, poisonNum = 0, gateNum = 0; // ���� ���� �ʱⰪ����
        for(auto &b: success) b = false; // �̼� ���� ���� üũ �迭 false�� �ʱ�ȭ
        startTime = time(NULL)-2; // ���� �ð� �缳��
    }
    
    return true; // ���� ���
}

void PlayGame::playingStage(int stage) {
    success[0] = (snake->getBodyLen() >= mission[stage-1][0]) ? true : false;
    success[1] = (growthNum >= mission[stage-1][1]) ? true : false;
    success[2] = (poisonNum >= mission[stage-1][2]) ? true : false;
    success[3] = (gateNum >= mission[stage-1][3]) ? true : false;
}

void PlayGame::countPoint() {
    int headPos = gameMap->getPosition(snake->getHeadPos()[0], snake->getHeadPos()[1]);
    int firstBodyPos = gameMap->getPosition(snake->getBodyPos(0)[0], snake->getBodyPos(0)[1]);
    if(headPos == 5) growthNum++;
    else if(headPos == 6) poisonNum++;
    else if(headPos == 7 && firstBodyPos == 7) gateNum++; // head�� gate ��� �� gate ������ �ߺ� ī��Ʈ���� �ʵ��� ��
}
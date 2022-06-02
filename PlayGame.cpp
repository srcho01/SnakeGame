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
    // item 생성
    item->makeGrowth(currStage, startTime); 
    item->makePoison(currStage, startTime);

    // gate 생성
    if(gate->currGate.size() == 4) {
        int g1 = gameMap->getPosition(gate->currGate[0], gate->currGate[1]);
        int g2 = gameMap->getPosition(gate->currGate[2], gate->currGate[3]);
        if(g1 == 7 && g2 == 7) gate->makeGate(currStage, startTime); // 뱀이 지나가는 중일 때는 gate 위치 변경 X
    } else gate->makeGate(currStage, startTime);

    countPoint(); // 점수 업데이트

    playingStage(currStage); // 미션 성공 여부 갱신

    // 게임 실패로 종료
    int headPos = gameMap->getPosition(snake->getHeadPos()[0], snake->getHeadPos()[1]); // 현재 머리 위치
    if(headPos == 1 || headPos == 2 || headPos == 8) return false; // 스네이크가 벽에 박음
    if(headPos == 4) return false; // 자기 몸에 박음 (진행 방향과 반대 방향으로 가는 경우 포함)
    if(snake->getBodyLen() < 3) return false; // 몸 길이 < 3

    // 미션 성공
    //// 미션 성공 개수 count
    int n = 0; 
    for(bool b: success) if(b) n++;
    
    if(n == 4 && currStage == 4) { // 4단계까지 모두 성공
        win = true;
        return false; // 게임 종료
    } else if(n == 4) {
        gameMap->setMap(++currStage); // 다음 단계로 stage 변경

        delete snake;
        snake = new Snake(); // 스네이크 객체 재생성하여 초기화

        int bodyLen = 3, growthNum = 0, poisonNum = 0, gateNum = 0; // 변수 전부 초기값으로
        for(auto &b: success) b = false; // 미션 성공 여부 체크 배열 false로 초기화
        startTime = time(NULL)-2; // 현재 시간 재설정
    }
    
    return true; // 게임 계속
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
    else if(headPos == 7 && firstBodyPos == 7) gateNum++; // head가 gate 통과 시 gate 점수가 중복 카운트되지 않도록 함
}
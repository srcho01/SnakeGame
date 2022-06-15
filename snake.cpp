#include <iostream>

#include "snake.h"

Snake::Snake()
{
    head = new int[2];
    tail = new int[2];
    head[0] = 2;  //head's y
    head[1] = 25; //head's x
    tail[0] = 2;  //tail's y
    tail[1] = 27; //tail's x
    pair<int,int> tmp = make_pair(2, 26);
    body.push_back(tmp);
    gameMap->changeMap(head[0], head[1], 3);
    gameMap->changeMap(body[0].first, body[0].second, 4);
    gameMap->changeMap(tail[0], tail[1], 4);
}

void Snake::mapUpdate() {
    int hx = this->getHeadPos()[1];
    int hy = this->getHeadPos()[0];
    gameMap->changeMap(hy, hx, 3);
    for(int i = 0; i < this->getBodyLen() - 2; i++){
        int mx = this->getBodyPos(i).second;
        int my = this->getBodyPos(i).first;
        gameMap->changeMap(my, mx, 4);
    }
    int tx = this->getTailPos()[1];
    int ty = this->getTailPos()[0];
    gameMap->changeMap(ty, tx, 4);

}

void Snake::move_left()
{
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[1] -= 1;
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  this->mapUpdate();
  prevHead = gameMap -> getPosition(tmp.first, tmp.second);
  }

void Snake::move_right()
{
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[1] += 1;
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  this->mapUpdate();
  prevHead = gameMap -> getPosition(tmp.first, tmp.second);

}

void Snake::move_up()
{
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[0] -= 1;
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  this->mapUpdate();
  prevHead = gameMap -> getPosition(tmp.first, tmp.second);

}

void Snake::move_down()
{
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[0] += 1;
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  this->mapUpdate();
  prevHead = gameMap -> getPosition(tmp.first, tmp.second);

}

void Snake::grow(int itemx, int itemy)
{
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[0] = itemy;
  head[1] = itemx;
  body.push_front(tmp);
}

void Snake::posion(int itemx, int itemy){
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  body.pop_back();  
}

void Snake::gate(int bodyDirection, int g2x, int g2y){
    if(bodyDirection == 75){
      head[0] = g2y;
      head[1] = g2x - 1;
    }
    else if(bodyDirection == 77){
      head[0] = g2y;
      head[1] = g2x + 1;
    }
    else if(bodyDirection == 72){
      head[0] = g2y - 1;
      head[1] = g2x;
    }
    else{
      head[0] = g2y + 1;
      head[1] = g2x;
    }
}

int* Snake::getHeadPos(){
    return head;
}

pair<int,int> Snake::getBodyPos(int num){
    return body[num];
}

int* Snake::getTailPos(){
    return tail;
}

int Snake::getBodyLen() {
    return body.size() + 2;
}
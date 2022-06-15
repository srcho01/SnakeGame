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

void Snake::mapUpdate(int x, int y) {
    int hx = this->getHeadPos()[1];
    int hy = this->getHeadPos()[0];
    gameMap->changeMap(hy, hx, 3);
    gameMap->changeMap(this->getBodyPos(0).first, this->getBodyPos(0).second, 4);
    gameMap->changeMap(y, x, 0);

}


void Snake::move_left()
{
  int x,y;
  x = tail[1];
  y = tail[0];
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[1] -= 1;
  prevHead = gameMap -> getPosition(head[0], head[1]);
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
  body.pop_back();

  this->mapUpdate(x,y);
  }

void Snake::move_right()
{
  int x,y;
  x = tail[1];
  y = tail[0];
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[1] += 1;
  prevHead = gameMap -> getPosition(head[0], head[1]);
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
    body.pop_back();

  this->mapUpdate(x,y);
}

void Snake::move_up()
{
    int x,y;
  x = tail[1];
  y = tail[0];
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[0] -= 1;
  prevHead = gameMap -> getPosition(head[0], head[1]);
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
    body.pop_back();

  this->mapUpdate(x,y);

}

void Snake::move_down()
{
    int x,y;
  x = tail[1];
  y = tail[0];
  pair<int,int> tmp = make_pair(head[0], head[1]);
  head[0] += 1;
  prevHead = gameMap -> getPosition(head[0], head[1]);
  body.push_front(tmp);
  tail[0] = body.back().first;
  tail[1] = body.back().second;
    body.pop_back();

  this->mapUpdate(x,y);

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
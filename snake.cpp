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
    headDirection = 1;  
}

void Snake::mapUpdate(int x, int y) {
    int hx = this->getHeadPos()[1];
    int hy = this->getHeadPos()[0];
    gameMap->changeMap(hy, hx, 3);

    for(int i =0; i < body.size(); i++){
      int mx = this->getBodyPos(i).second;
      int my = this->getBodyPos(i).first;
      gameMap->changeMap(my,mx,4);
    }

    int tx = this->getTailPos()[1];
    int ty = this->getTailPos()[0];
    gameMap->changeMap(ty,tx,4);
    gameMap->changeMap(y,x,0);

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

void Snake::grow()
{ 
  if(headDirection == 1){
    pair<int,int> tmp = make_pair(head[0], head[1]);
    head[1] -= 1;
    body.push_front(tmp);
  }
  else if(headDirection == 2){
    pair<int,int> tmp = make_pair(head[0], head[1]);
    head[1] += 1;
    body.push_front(tmp);
  }
   else if(headDirection == 3){
    pair<int,int> tmp = make_pair(head[0], head[1]);
    head[0] -= 1;
    body.push_front(tmp);
  }
  else if(headDirection == 4){
    pair<int,int> tmp = make_pair(head[0], head[1]);
    head[0] += 1;
    body.push_front(tmp);
  }
}

void Snake::posion(){
    int tx = body.back().second;
    int ty = body.back().first;
    gameMap->changeMap(tail[0], tail[1], 0);
    tail[0] = ty;
    tail[1] = tx;
    body.pop_back();
}

void Snake::gate(int g2x, int g2y){ //49, 24
    head[0] = g2y;
    head[1] = g2x ;
    if(g2x == 49){
      headDirection = 1;
    }
    else if(g2x == 0 ){;
      headDirection = 2;

    }
    else if(g2y == 24){
      headDirection = 3;
    }
    else if(g2y == 0){
      headDirection = 4;
    }
    else{
      if(headDirection == 1){
        if(gameMap->getPosition(g2y, g2x-1) == 0){
          headDirection = 1;
        }
        else if(gameMap->getPosition(g2y-1, g2x) == 0){
          headDirection = 3;
        }
        else if(gameMap->getPosition(g2y+1, g2x) == 0){
          headDirection = 4;
        }
        else{
          headDirection = 2;
        }
      }
      else if(headDirection == 2)
        if(gameMap->getPosition(g2y, g2x+1) == 0){
          headDirection = 2;
        }
        else if(gameMap->getPosition(g2y+1, g2x) == 0){
          headDirection = 4;
        }
        else if(gameMap->getPosition(g2y-1, g2x) == 0){
          headDirection = 3;
        }
        else{
          headDirection = 1;
        }
      else if (headDirection == 3)
        if(gameMap->getPosition(g2y-1, g2x) == 0){
          headDirection = 3;
        }
        else if(gameMap->getPosition(g2y, g2x+1) == 0){
          headDirection = 2;
        }
        else if(gameMap->getPosition(g2y, g2x-1) == 0){
          headDirection = 1;
        }
        else{
          headDirection = 4;
        }
      else if(headDirection == 4)
        if(gameMap->getPosition(g2y+1, g2x) == 0){
          headDirection = 4;
        }
        else if(gameMap->getPosition(g2y, g2x-1) == 0){
          headDirection = 1;
        }
        else if(gameMap->getPosition(g2y, g2x-1) == 0){
          headDirection = 2;
        }
        else{
          headDirection = 3;
        }
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
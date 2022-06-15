#include <iostream>
#include "snake.h"
using namespace std;

Snake::Snake()
{
    head = new int[2];
    tail = new int[2];
    body = new int *[100]();
    for (int i = 0; i < 8; i++)
    {
      body[i] = new int[2];
    }
    head[0] = 2;  //head's y
    head[1] = 12; //head's x
    tail[0] = 2;  //tail's y
    tail[1] = 14; //tail's x
    body[0][0] = 2;
    body[0][1] = 13;
    gameMap->changeMap(2, 12, 3);
    gameMap->changeMap(2, 13, 4);
    gameMap->changeMap(2, 14, 4);
}

void Snake::mapUpdate() {
    int hx = this->getHeadPos()[1];
    int hy = this->getHeadPos()[0];
    gameMap->changeMap(hy, hx, 3);
    for(int i = 0; i < this->getBodyLen(); i++){
        int mx = this->getBodyPos(i)[1];
        int my = this->getBodyPos(i)[0];
        gameMap->changeMap(my, mx, 4);
    }
    int tx = this->getTailPos()[1];
    int ty = this->getTailPos()[0];
    gameMap->changeMap(ty, tx, 4);
}

void Snake::move_left()
{
    int tmp_head[2] = {head[0], head[1]};
    head[1] -= 1;
    int tmp_bodyy;
    int tmp_bodyx;
    for (int i = 0; i < 8; i++)
    {
      if (body[i] != NULL)
      {
        tmp_bodyy = body[i][0];
        tmp_bodyx = body[i][1];
        body[i][0] = tmp_head[0];
        body[i][1] = tmp_head[1];
        tmp_head[0] = tmp_bodyy;
        tmp_head[1] = tmp_bodyx;
      }
    }
    tail[0] = tmp_head[0];
    tail[1] = tmp_head[1];
    this->mapUpdate();
}

void Snake::move_right()
{
    int tmp_head[2] = {head[0], head[1]};
    head[1] += 1;
    int tmp_bodyy;
    int tmp_bodyx;
    for (int i = 0; i < 8; i++)
    {
      if (body[i] != 0)
      {
        tmp_bodyy = body[i][0];
        tmp_bodyx = body[i][1];
        body[i][0] = tmp_head[0];
        body[i][1] = tmp_head[1];
        tmp_head[0] = tmp_bodyy;
        tmp_head[1] = tmp_bodyx;
      }
    }
    tail[0] = tmp_head[0];
    tail[1] = tmp_head[1];
    this->mapUpdate();
}

void Snake::move_up()
{
    int tmp_head[2] = {head[0], head[1]};
    head[0] -= 1;
    int tmp_bodyy;
    int tmp_bodyx;
    for (int i = 0; i < 8; i++)
    {
      if (body[i] != NULL)
      {
        tmp_bodyy = body[i][0];
        tmp_bodyx = body[i][1];
        body[i][0] = tmp_head[0];
        body[i][1] = tmp_head[1];
        tmp_head[0] = tmp_bodyy;
        tmp_head[1] = tmp_bodyx;
      }
    }
    tail[0] = tmp_head[0];
    tail[1] = tmp_head[1];
    this->mapUpdate();
}

void Snake::move_down()
{
    int tmp_head[2] = {head[0], head[1]};
    head[0] += 1;
    int tmp_bodyy;
    int tmp_bodyx;
    for (int i = 0; i < 8; i++)
    {
      if (body[i] != NULL)
      {
        tmp_bodyy = body[i][0];
        tmp_bodyx = body[i][1];
        body[i][0] = tmp_head[0];
        body[i][1] = tmp_head[1];
        tmp_head[0] = tmp_bodyy;
        tmp_head[1] = tmp_bodyx;
      }
    }
    tail[0] = tmp_head[0];
    tail[1] = tmp_head[1];
    this->mapUpdate();
}

void Snake::grow(int itemx, int itemy)
{
    int tmp_body[8][2];
    for (int i = 0; i < 8; i++)
    {
      if (body[i] != NULL)
      {
        tmp_body[i + 1][0] = body[i][0];
        tmp_body[i + 1][1] = body[i][1];
      }
    }
    tmp_body[0][0] = head[0];
    tmp_body[0][1] = head[1];
    head[0] = itemy;
    head[1] = itemx;

    for (int i = 0; i < 8; i++)
    {
      body[i][0] = tmp_body[i][0];
      body[i][1] = tmp_body[i][1];
    }
}

void Snake::posion(int itemx, int itemy){
    for(int i = 0; i < 8; i++){
      if(body[i] == NULL){
        tail[0] = body[i-1][0];
        tail[1] = body[i-1][1];
        body[i-1] = NULL;
        break;
      }
    }
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

int* Snake::getBodyPos(int num){
    return body[num];
}

int* Snake::getTailPos(){
    return tail;
}

int Snake::getBodyLen() {
    int len = 0;
    for(int i = 0; i < 100; i++){
      if(body[i][0] != 0) len++;
      else return len + 2;
    }
    return len +2 ;
}
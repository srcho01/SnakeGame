#include <ncurses.h>
#include <string>
#include <clocale>
#include <unistd.h>
#include "gameUI.h"

GameUI::GameUI() {
    // gameMap = new Map;
    initUI();
}

void GameUI::initUI() { // 배경화면 생성
    setlocale(LC_ALL, "");
    initscr();
    start_color();    
    init_pair(1, COLOR_BLACK,  COLOR_CYAN); 
    init_pair(2, COLOR_RED,   COLOR_GREEN);
    bkgd(COLOR_PAIR(1));  
    attron(COLOR_PAIR(1));
    mvprintw( 1, 11, "<Snake Game>");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); 
    attroff(COLOR_PAIR(2));
    refresh();
}

GameUI::~GameUI() {
    // 창 종료
    endwin();
}

void GameUI::PrintGame() {
    for (int i=0; i<25; i++) {
        for (int j=0; j<25; j++) {
            switch (gameMap->getPosition(i, j)) {
                case 0:
                    mvprintw(i+2, j+4, " ");
                    break;
                case 1:
                    mvprintw(i+2, j+4, "-");
                    break;
                case 2:
                    mvprintw(i+2, j+4, "X");
                    break;
                case 3:
                    mvprintw(i+2, j+4, "@");
                    break;
                case 4:
                    mvprintw(i+2, j+4, "w");
                    break;
                case 5:
                    mvprintw(i+2, j+4, "\u2665");
                    break;
                case 6:
                    mvprintw(i+2, j+4, "\u2605");
                    break;
                case 7:
                    mvprintw(i+2, j+4, "#");
                    break;
                case 8:
                    mvprintw(i+2, j+4, "-");
                    break;
            }
        }
    }
    refresh();
}

void GameUI::update(unsigned time) {
    PrintGame();
    usleep(time);
}
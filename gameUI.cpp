#include <ncurses.h>
#include <string>
#include <clocale>
#include <unistd.h>
#include "gameUI.h"

GameUI::GameUI() {
    initUI();
}

void GameUI::initUI() { // 배경화면 생성
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();    
    init_pair(1, COLOR_BLACK,  COLOR_WHITE); 
    init_pair(2, COLOR_RED,   COLOR_GREEN);
    bkgd(COLOR_PAIR(1));  
    attron(COLOR_PAIR(1));
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); 
    attroff(COLOR_PAIR(2));
    mvprintw(10, 20, "If you want to start a game,");
    mvprintw(13 , 25,  "Press any key");
    getch();
    PrintScore();
    PrintMission();
    refresh();
}

GameUI::~GameUI() {
    // 창 종료
    endwin();
}
// score 화면
void GameUI::PrintScore() {
    mvprintw(2, 80, "< Score >");
    mvprintw(3, 75, "--------------------");
    mvprintw(5, 70, "B : ");
    mvprintw(6, 70, "+ : ");
    mvprintw(7, 70, "- : ");
    mvprintw(8, 70, "G : ");
    
}
// mission 화면
void GameUI::PrintMission() {
    mvprintw(15, 80, "< Mission >");
    mvprintw(16, 75, "--------------------");
    mvprintw(18, 70, "B : ");
    mvprintw(19, 70, "+ : ");
    mvprintw(20, 70, "- : ");
    mvprintw(21, 70, "G : ");
}

// main 화면
void GameUI::PrintGame() {
    mvprintw( 0, 40, "< SNAKE GAME >");
    for (int i=0; i<25; i++) {
        for (int j=0; j<50; j++) {
            switch (gameMap->getPosition(i, j)) {
                case 0:
                    mvprintw(i+2, j+4, " ");
                    break;
                case 1:
                    mvprintw(i+2, j+4, "\u25A0");
                    break;
                case 2:
                    mvprintw(i+2, j+4, "\u25CF");
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
                    mvprintw(i+2, j+4, "\u25A1");
                    break;
            }
        }
    }
    refresh();
}

void GameUI::PrintGameClear() {
    mvprintw( 8, 1, "  _____   _                       _");
    mvprintw( 9, 1 ," /  __ | | |                     | |");
    mvprintw( 10, 2, "| | |_| | |   ___   __ _  _ __  | |");
    mvprintw( 11, 2, "| |  _  | | /  _ | / _` || '__| | |");
    mvprintw( 12, 2, "| |_| | | | | ___/| (_| || |    |_|");
    mvprintw( 13, 2, "|_____/ |_| |____| |__,_||_|    (_)");
}

void GameUI::PrintGameOver() {
    mvprintw( 15, 2, "______         _   _   _");
    mvprintw( 16, 2 ,"|  ___|       (_) | | | |");
    mvprintw( 17, 2, "| |_    __ _   _  | | | |");
    mvprintw( 18, 2, "|  _|  / _` | | | | | | |");
    mvprintw( 19, 2, "| |   | (_| | | | | | |_|");
    mvprintw( 20, 2, "|_|   |___,_| |_| |_| (_))"); 
}

void GameUI::update(unsigned time) {
    PrintGame();
    usleep(time);
}
#include <ncurses.h>
#include <string>
#include <clocale>
#include <unistd.h>
#include "gameUI.h"

GameUI::GameUI() {
    playgame = new PlayGame;
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
    mvprintw(13 , 25,  "Press Enter");
    int tmp = getch();
    PrintScore();
    PrintMission();
    refresh();
    
        //if (playgame->isWin()) {
        //PrintGameClear();
        //getch();
    
}

GameUI::~GameUI() {
    // 창 종료
    if(playgame->isWin())
        PrintGameClear();
    else
        PrintGameOver();
    getch();
    endwin();
}

// score 화면
void GameUI::PrintScore() {
    mvprintw(2, 80, "< Score >");
    mvprintw(3, 75, "--------------------");
    mvprintw(5, 70, "B : "); mvprintw(5, 75, std::to_string(playgame->getBodyNum()).c_str());
    mvprintw(6, 70, "+ : "); mvprintw(6, 75, std::to_string(playgame->getGrowthNum()).c_str());
    mvprintw(7, 70, "- : "); mvprintw(7, 75, std::to_string(playgame->getPoisonNum()).c_str());
    mvprintw(8, 70, "G : "); mvprintw(8, 75, std::to_string(playgame->getGateNum()).c_str());
}

// mission 화면
void GameUI::PrintMission() {
    mvprintw(15, 80, "< Mission >");
    mvprintw(16, 75, "--------------------");
    mvprintw(18, 70, "B : ");
    mvprintw(18, 75, std::to_string(playgame->getMission(playgame->currStage, 0)).c_str());
    mvprintw(19, 70, "+ : ");
    mvprintw(19, 75, std::to_string(playgame->getMission(playgame->currStage, 1)).c_str());
    mvprintw(20, 70, "- : ");
    mvprintw(20, 75, std::to_string(playgame->getMission(playgame->currStage, 2)).c_str());
    mvprintw(21, 70, "G : ");
    mvprintw(21, 75, std::to_string(playgame->getMission(playgame->currStage, 3)).c_str());
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
    mvprintw( 8, 10, " _____   _                       _");
    mvprintw( 9, 10, "/  __ | | |                     | |");
    mvprintw( 10, 10, "| | |_| | |   ___   __ _  _ __  | |");
    mvprintw( 11, 10, "| |  _  | | /  _ | / _` || '__| | |");
    mvprintw( 12, 10, "| |_| | | | | ___/| (_| || |    |_|");
    mvprintw( 13, 10, "|_____/ |_| |____| |__,_||_|    (_)");
    refresh();
    usleep(40000);
}

void GameUI::PrintGameOver() {
    mvprintw( 15, 10, "______         _   _   _");
    mvprintw( 16, 10 ,"|  ___|       (_) | | | |");
    mvprintw( 17, 10, "| |_    __ _   _  | | | |");
    mvprintw( 18, 10, "|  _|  / _` | | | | | | |");
    mvprintw( 19, 10, "| |   | (_| | | | | | |_|");
    mvprintw( 20, 10, "|_|   |___,_| |_| |_| (_))"); 
}

void GameUI::update(unsigned time) {
    PrintGame();
    usleep(time);
}

void GameUI::updateScore(unsigned time) {
    PrintScore();
    usleep(time);
}

void GameUI::updateMission(unsigned time) {
    PrintMission();
    usleep(time);
}
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
    mvprintw(18, 75, std::to_string(playgame->getMission(gameMap->getCurrentStage()-1, 0)).c_str());
    if(playgame->success[0]) mvprintw(18, 78, "( V )"); else mvprintw(18, 78, "(   )");
    mvprintw(19, 70, "+ : ");
    mvprintw(19, 75, std::to_string(playgame->getMission(gameMap->getCurrentStage()-1, 1)).c_str());
    if(playgame->success[1]) mvprintw(19, 78, "( V )"); else mvprintw(19, 78, "(   )");
    mvprintw(20, 70, "- : ");
    mvprintw(20, 75, std::to_string(playgame->getMission(gameMap->getCurrentStage()-1, 2)).c_str());
    if(playgame->success[2]) mvprintw(20, 78, "( V )"); else mvprintw(20, 78, "(   )");
    mvprintw(21, 70, "G : ");
    mvprintw(21, 75, std::to_string(playgame->getMission(gameMap->getCurrentStage()-1, 3)).c_str());
    if(playgame->success[3]) mvprintw(21, 78, "( V )"); else mvprintw(21, 78, "(   )");
}

// main 화면
void GameUI::PrintGame() {
    mvprintw( 0, 50, "< SNAKE GAME >");
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
    mvprintw( 8, 17, " _____   _                       _");
    mvprintw( 9, 17, "/  __ | | |                     | |");
    mvprintw( 10, 17, "| | |_| | |   ___   __ _  _ __  | |");
    mvprintw( 11, 17, "| |  _  | | /  _ | / _` || '__| | |");
    mvprintw( 12, 17, "| |_| | | | | ___/| (_| || |    |_|");
    mvprintw( 13, 17, "|_____/ |_| |____| |__,_||_|    (_)");
    refresh();
    usleep(40000);
}

void GameUI::PrintGameOver() {
    mvprintw( 10, 17, "______         _   _   _");
    mvprintw( 11, 17 ,"|  ___|       (_) | | | |");
    mvprintw( 12, 17, "| |_    __ _   _  | | | |");
    mvprintw( 13, 17, "|  _|  / _` | | | | | | |");
    mvprintw( 14, 17, "| |   | (_| | | | | | |_|");
    mvprintw( 15, 17, "|_|   |___,_| |_| |_| (_)"); 
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
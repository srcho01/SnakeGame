CC = g++
CCFLAGS = -g
NCURSESFLAG = -lncursesw
TARGET = SnakeGame.exe

# 헤더 파일 제외 작성한 cpp 파일만 공백으로 구분하여 작성
SOURCES = main.cpp gameUI.cpp map.cpp mapData.cpp snake.cpp PlayGame.cpp Item.cpp Gate.cpp kbhit.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CCFLAGS) -o $@ $^ $(NCURSESFLAG)
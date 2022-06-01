CC = g++
CCFLAGS = -g
NCURSESFLAG = -lncursesw
TARGET = SnakeGame.exe

# 컴파일에 필요한 소스 파일을 아래에 추가해주세요 (공백으로 구분, 헤더 파일 X)
SOURCES = gameUI.cpp map.cpp mapData.cpp snake.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CCFLAGS) -o $@ $^ $(NCURSESFLAG)
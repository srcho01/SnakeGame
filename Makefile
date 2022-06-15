CC = g++
CCFLAGS = -g
NCURSESFLAG = -lncursesw
TARGET = SnakeGame.exe

# �����Ͽ� �ʿ��� �ҽ� ������ �Ʒ��� �߰����ּ��� (�������� ����, ��� ���� X)
SOURCES = main.cpp gameUI.cpp map.cpp mapData.cpp snake.cpp PlayGame.cpp Item.cpp Gate.cpp kbhit.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CCFLAGS) -o $@ $^ $(NCURSESFLAG)
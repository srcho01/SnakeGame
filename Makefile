CC = g++
CCFLAGS = -g
NCURSESFLAG = -lncursesw
TARGET = SnakeGame.exe

# �����Ͽ� �ʿ��� �ҽ� ������ �Ʒ��� �߰����ּ��� (�������� ����, ��� ���� X)
SOURCES = gameUI.cpp map.cpp mapData.cpp snake.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CCFLAGS) -o $@ $^ $(NCURSESFLAG)
class Snake {
private:
    int *head, *tail;
    int **body;
    int headDirection = 75; // left: 75, right: 77, up: 72, down: 80

public:
    Snake();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void grow(int itemx, int itemy);
    void posion(int itemx, int itemy);
    void gate(int bodyDirection, int g2x, int g2y);
    int* getHeadPos();
    int* getBodyPos(int num);
    int* getTailPos();
};
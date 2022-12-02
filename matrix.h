#ifndef matrix_h
#define matrix_h

enum Color {
    CASE_WHITE,
    CASE_RED,
    CASE_ORANGE,
    CASE_BLUE,
    CASE_STAR
};
// if you're on CASE_WHITE, you lose
// if you're on CASE_STAR, you win

extern char matrix[12][10];
void resetMatrix();
void initMatrix();

enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

struct Coords {
    unsigned char x;
    unsigned char y;
};
// careful, the position is at matrix[y][x]

extern struct Coords coords;
extern enum Direction direction;

void printCoords();

void printMatrix(char matrix[12][10]);

void move();
void turnRight();
void turnLeft();
char isRed();
char isOrange();
char isBlue();
char isStar();
void paintRed();
void paintBlue();
void paintOrange();
char gameLost();
char gameWon();
void declareGameTerminated();
char gameTerminated();
void declareWasPainted();
char wasPainted();



#endif
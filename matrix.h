#ifndef matrix_h
#define matrix_h

enum Color {
    CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_BLUE, CASE_STAR
};
//if you're on CASE_WHITE, you lose
//if you're on CASE_STAR, you win

extern char matrix[12][10];
void resetMatrix();

enum Direction {
    RIGHT, DOWN, LEFT, UP
};

struct Coords {
    unsigned char x;
    unsigned char y;
};
//careful, the position is at matrix[y][x]

extern struct Coords coords;
extern enum Direction direction;

void printCoords();

void move();
void turnRight();
void turnLeft();
char isRed();
char isOrange();
char isBlue();
void paintRed();
void paintBlue();
char gameLost();
char gameWon();

#endif
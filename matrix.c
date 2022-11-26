#include <stdio.h>
#include "matrix.h"

char matrixBase[12][10] = {
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_STAR, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_RED, CASE_RED, CASE_RED, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE},
    {CASE_WHITE, CASE_RED, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_ORANGE, CASE_RED, CASE_ORANGE, CASE_RED, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE}
};

char matrix[12][10];


struct Coords coords = {5, 10};
enum Direction direction = RIGHT;
char _gameTerminated = 0;

void printCoords() {
    if (coords.x == 5 && coords.y == 10) {
        return;
    }
    printf("x : %d; y : %d\n", coords.x, coords.y);
}

void move() {
    switch (direction) {
        case UP:
            coords.y--;
            break;
        case DOWN:
            coords.y++;
            break;
        case LEFT:
            coords.x--;
            break;
        case RIGHT:
            coords.x++;
            break;
    }
}

void turnRight() {
    direction = (direction + 1) % 4;
}

void turnLeft() {
    direction = (direction + 3) % 4;
}

char isRed() {
    if (matrix[coords.y][coords.x] == CASE_RED) {
        printCoords();
        printf("%d", matrix[coords.y][coords.x]);
        return 1;
    }
    return 0;
}

char isOrange() {
    if (matrix[coords.y][coords.x] == CASE_ORANGE) {
        return 1;
    }
    return 0;
}

char isBlue() {
    if (matrix[coords.y][coords.x] == CASE_BLUE) {
        return 1;
    }
    return 0;
}

void paintRed() {
    matrix[coords.y][coords.x] = CASE_RED;
}

void paintBlue() {
    matrix[coords.y][coords.x] = CASE_BLUE;
}

char gameLost() {
    if (matrix[coords.y][coords.x] == CASE_WHITE) {
        return 1;
    }
    return 0;
}

char gameWon() {
    if (matrix[coords.y][coords.x] == CASE_STAR) {
        return 1;
    }
    return 0;
}

void declareGameTerminated() {
    _gameTerminated = 1;
}

char gameTerminated() {
    if (!_gameTerminated) {
        return 0;
    }
    _gameTerminated = 0;
    return 1;
}

void resetMatrix() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = matrixBase[i][j];
        }
    }
}
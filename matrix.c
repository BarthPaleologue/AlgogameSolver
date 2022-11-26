#include "matrix.h"

#include <stdio.h>

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
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE}};

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

void printMatrix(char matrix[12][10]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == coords.y && j == coords.x) {
                printf("X");
                continue;
            }
            switch (matrix[i][j]) {
                case CASE_WHITE:
                    printf(" ");
                    break;
                case CASE_RED:
                    printf("R");
                    break;
                case CASE_ORANGE:
                    printf("O");
                    break;
                case CASE_BLUE:
                    printf("B");
                    break;
                case CASE_STAR:
                    printf("*");
                    break;
                default:
                    printf("?");  // should never happen
            }
        }
        printf("\n");
    }
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
    return matrix[coords.y][coords.x] == CASE_RED;
}

char isOrange() {
    return matrix[coords.y][coords.x] == CASE_ORANGE;
}

char isBlue() {
    return matrix[coords.y][coords.x] == CASE_BLUE;
}

void paintRed() {
    matrix[coords.y][coords.x] = CASE_RED;
}

void paintBlue() {
    matrix[coords.y][coords.x] = CASE_BLUE;
}

char gameLost() {
    return matrix[coords.y][coords.x] == CASE_WHITE;
}

char gameWon() {
    return matrix[coords.y][coords.x] == CASE_STAR;
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
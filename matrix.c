#include "matrix.h"

char matrix[12][10] = {
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


struct Coords coords = {5, 10};
enum Direction direction = RIGHT;

void printCoords() {
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
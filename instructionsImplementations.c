#include "matrix.h"
#include "instructionsImplementations.h"

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

void paintOrange() {
    matrix[coords.y][coords.x] = CASE_ORANGE;
}
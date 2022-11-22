#include <stdio.h>
#include "matrix.h"
#include "algos.h"

enum Direction {
    RIGHT, DOWN, LEFT, UP
};

struct Coords {
    unsigned char x;
    unsigned char y;
};
//careful, the position is at matrix[y][x]

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

char gameWon() {
    if (matrix[coords.y][coords.x] == CASE_STAR) {
        return 1;
    }
    return 0;
}

void doAction(enum Action action, unsigned char * programCasePointer) {
    switch (action) {
        case FORWARD:
            move();
            *programCasePointer = *programCasePointer + 1;
            break;
        case TURN_LEFT:
            turnLeft();
            *programCasePointer = *programCasePointer + 1;
            break;
        case TURN_RIGHT:
            turnRight();
            *programCasePointer = *programCasePointer + 1;
            break;
        case PAINT_RED:
            paintRed();
            *programCasePointer = *programCasePointer + 1;
            break;
        case PAINT_BLUE:
            paintBlue();
            *programCasePointer = *programCasePointer + 1;
            break;
        case F1:
            *programCasePointer = 0;
            break;
        case F2:
            *programCasePointer = 3;
            break;
    }

}


int main() {

    printCoords();
    for (int i = 0 ; i < 10 ; i++) {

        Program program = generateNextProgram();
        unsigned char programCase = 0;

        coords.x = 5 ;
        coords.y = 10;
        direction = RIGHT;

        while (!gameLost() && !gameWon()) {

            struct Instruction instruction = program[programCase];
            printCoords();

            switch(instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action, &programCase);
                    break;
                case CD_RED:
                    if (isRed()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
                case CD_ORANGE:
                    if (isOrange()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
                case CD_BLUE:
                    if (isBlue()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
            }


        
        }

        if (gameWon()) {
            printf("this program succeeded:\n");
            printProgram(program);
        }

        if (gameLost()) {
            printf("this program failed:\n");
            printProgram(program);
        }
    }
    return 0;
}
#include <stdio.h>
#include "matrix.h"
#include "algos.h"

enum Direction {
    RIGHT, DOWN, LEFT, UP
};

struct Coords {
    int x;
    int y;
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

int gameLost() {
    if (matrix[coords.y][coords.x] == CASE_WHITE) {
        return 1;
    }
    return 0;
}

int isRed() {
    if (matrix[coords.y][coords.x] == CASE_RED) {
        return 1;
    }
    return 0;
}

int isOrange() {
    if (matrix[coords.y][coords.x] == CASE_ORANGE) {
        return 1;
    }
    return 0;
}

int isBlue() {
    if (matrix[coords.y][coords.x] == CASE_BLUE) {
        return 1;
    }
    return 0;
}

int gameWon() {
    if (matrix[coords.y][coords.x] == CASE_STAR) {
        return 1;
    }
    return 0;
}

void doAction(enum Action action, int * programCasePointer) {
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
        int programCase = 0;

        while (!gameLost() && !gameWon()) {

            struct Instruction instruction = program[programCase];
            printCoords();

            switch(instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action, &programCase);
                    break;
                case CASE_RED:
                    if (isRed()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
                case CASE_ORANGE:
                    if (isOrange()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
                case CASE_BLUE:
                    if (isBlue()) {
                        doAction(instruction.action, &programCase);
                    }
                    break;
            }


        
        }

        if (gameWon()) {
            printf("this program succeeded : ");
            printProgram(program);
        }

        if (gameLost()) {
            printf("this program failed : ");
            printProgram(program);
        }
    }
    

    

    return 0;
}
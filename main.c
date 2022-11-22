#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "algos.h"

typedef struct node {
    struct node * oldNode;
    unsigned char programCase;
} node_t;

node_t firstNode = {NULL, 0};

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

void doAction(enum Action action) {
    switch (action) {
        case FORWARD:
            move();
            break;
        case TURN_LEFT:
            turnLeft();
            break;
        case TURN_RIGHT:
            turnRight();
            break;
        case PAINT_RED:
            paintRed();
            break;
        case PAINT_BLUE:
            paintBlue();
            break;
        case F1:
            
            break;
        case F2:
            //TODO
            break;
    }

}


int main() {

    for (int i = 0 ; i < 10 ; i++) {

        Program program = generateNextProgram();
        printProgram(program);
        unsigned char programCase = 0;

        coords.x = 5 ;
        coords.y = 10;
        direction = RIGHT;

        while (!gameLost() && !gameWon()) {

            struct Instruction instruction;
            if (programCase < PROGRAM_LENGTH - 1){
                instruction = program[programCase];
                programCase = programCase + 1;
            } else {
                //TODO (remonter à la fonction appelante, ou arreter)
            }

            switch(instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed()) {
                        doAction(instruction.action);
                    }
                    break;
                case CD_ORANGE:
                    if (isOrange()) {
                        doAction(instruction.action);
                    }
                    break;
                case CD_BLUE:
                    if (isBlue()) {
                        doAction(instruction.action);
                    }
                    break;
            }

            printCoords();

        }

        if (gameWon()) {
            printf("this program succeeded\n\n\n");
        }

        if (gameLost()) {
            printf("this program failed\n\n\n");
        }
    }
    return 0;
}
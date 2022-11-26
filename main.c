#include <stdio.h>
#include <stdlib.h>

#include "algos.h"
#include "matrix.h"
#include "stack.h"

unsigned char programCase;
char hasJumped;

char doAction(enum Action action) {
    switch (action) {
        case FORWARD:
            move();
            return 0;
        case TURN_LEFT:
            turnLeft();
            return 0;
        case TURN_RIGHT:
            turnRight();
            return 0;
        case PAINT_RED:
            paintRed();
            return 0;
        case PAINT_BLUE:
            paintBlue();
            return 0;
        case F1:
            lastNode = jumpInProgram(0, &programCase);
            return 1;
        case F2:
            lastNode = jumpInProgram(3, &programCase);
            return 1;
    }
    return 0;
}

void updateProgramCase(char hasJumped) {
    if (hasJumped) {
        return;
    }
    if (programCase == PROGRAM_LENGTH - 1 || programCase == 2) {
        // 2 correspond a F1_LENGTH - 1
        if (lastNode == NULL) {
            // printf("t");
            // printProgram(program);
            declareGameTerminated();
        } else {
            jumpBack(&programCase);
        }
    } else {
        programCase = programCase + 1;
    }
}

void resetStatus() {
    coords.x = 5;
    coords.y = 10;
    direction = RIGHT;
    resetMatrix();  // pas necessaire a chaque fois...
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    while (lastNode != NULL) {
        jumpBack(&programCase);  // permet de free tous les nodes
    }
    programCase = 0;
}

int main() {
    /*char programArray[7][2] = {
        {FORWARD, CD_NONE},
        {F1, CD_RED},
        {F2, CD_NONE},
        {TURN_LEFT, CD_NONE},
        {FORWARD, CD_NONE},
        {PAINT_BLUE, CD_NONE},
        {F1, CD_NONE}};*/

    char programArray[7][2] = {
        {FORWARD, CD_RED},
        {F2, CD_NONE},
        {F1, CD_NONE},
        {TURN_LEFT, CD_ORANGE},
        {FORWARD, CD_NONE},
        {F2, CD_RED},
        {TURN_LEFT, CD_NONE}};

    Program p = getProgramFromVerboseArray(programArray);

    printProgramVerbose(p);

    resetStatus();

    printMatrix(matrix);

    unsigned long long n = 28ll * 28ll * 28ll * 28ll * 28ll * 28ll * 28ll;
    for (unsigned long long i = 0; i < 1; i++) {
        printf("Tested programs: %llu\r", i);
        resetStatus();
        Program program = p;  // generateNextProgram();

        for (int step = 0; step < 100 && !gameLost() && !gameWon() && !gameTerminated(); step++) {
            struct Instruction instruction = program[programCase];

            switch (instruction.condition) {
                case CD_NONE:
                    hasJumped = doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed() != 0) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
                case CD_ORANGE:
                    if (isOrange()) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
                case CD_BLUE:
                    if (isBlue()) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
            }
            updateProgramCase(hasJumped);

            printf("\n");
            printCoords();
            printf("\n%d\n\n", direction);
        }

        if (gameWon()) {
            printf("this program succeeded\n\n\n");
            printProgramVerbose(program);
        } else if (gameLost()) {
            // printf("this program failed\n\n\n");
            // printf("f-");
        } else {
            // printf("this program terminated without finding the star\n\n\n");
            // printf("i-");
        }
        // printf("\n");

        free(program);
    }
    return 0;
}
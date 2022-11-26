#include <stdio.h>
#include <stdlib.h>

#include "algos.h"
#include "matrix.h"
#include "stack.h"

unsigned char programCase;

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
            lastNode = jumpInProgram(0, &programCase);
            break;
        case F2:
            lastNode = jumpInProgram(3, &programCase);
            break;
    }
}

void resetStatus() {
    coords.x = 5;
    coords.y = 10;
    direction = RIGHT;
    resetMatrix();  // pas necessaire a chaque fois...
    while (lastNode != NULL) {
        jumpBack(&programCase);  // permet de free tous les nodes
    }
    programCase = 0;
}

int main() {
    char programArray[7][2] = {
        {FORWARD, CD_NONE},
        {F1, CD_RED},
        {F2, CD_NONE},
        {TURN_LEFT, CD_NONE},
        {FORWARD, CD_NONE},
        {PAINT_BLUE, CD_NONE},
        {F1, CD_NONE}};

    Program p = getProgramFromVerboseArray(programArray);

    printProgramVerbose(p);

    resetStatus();

    printMatrix(matrix);

    unsigned long long n = 28ll * 28ll * 28ll * 28ll * 28ll * 28ll * 28ll;
    for (unsigned long long i = 0; i < n; i++) {
        printf("Tested programs: %llu\r", i);
        resetStatus();
        Program program = generateNextProgram();

        for (int step = 0; step < 100 && !gameLost() && !gameWon(); step++) {
            struct Instruction instruction = program[programCase];

            switch (instruction.condition) {
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
            if (programCase == PROGRAM_LENGTH - 1 || programCase == 2) {
                // 2 correspond a F1_LENGTH - 1
                if (lastNode == NULL) {
                    // printf("t");
                    // printProgram(program);
                    break;
                } else {
                    jumpBack(&programCase);
                }
            } else {
                programCase = programCase + 1;
            }
            // printCoords();
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
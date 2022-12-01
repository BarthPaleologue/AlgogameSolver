#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "generator.h"

#define NB_PROGRAMS 1

int main() {
    char programsToTest[NB_PROGRAMS][7][2] = {
        {{F2, CD_NONE},
         {PAINT_BLUE, CD_NONE},
         {F1, CD_NONE},
         {FORWARD, CD_RED},
         {PAINT_RED, CD_BLUE},
         {F2, CD_RED},
         {TURN_LEFT, CD_NONE}}};

    initPath();
    initMatrix();
    resetMatrix();
    printf("\n\n\n");

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < NB_PROGRAMS; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        printProgramVerbose(program);

        resetStatus();

        for (int step = 0; step < 120 && !gameLost() && !gameTerminated() && !gameWon(); step++) {
            struct Instruction instruction = program[programCase];

            updateProgramCase();

            if (isStar()) {
                numberOfStars--;
            }

            switch (instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed() != 0) {
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
            while (programCase == -1) {
                if (lastNode == NULL) {
                    // printf("t");
                    // printProgram(program);
                    declareGameTerminated();
                    break;
                }
                jumpBack(&programCase);
            }
        }

        if (gameWon()) {
            printf("Tests passed: %d/%d\r", i + 1, NB_PROGRAMS);
        } else {
            successful = 0;
        }
        free(program);
    }

    printf("\n\n\n");

    if (successful) {
        printf("The tests were successful\n");
        return EXIT_SUCCESS;
    } else {
        printf("The tests failed\n");
        return EXIT_FAILURE;
    }
}

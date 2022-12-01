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

        executeProgram(program);

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

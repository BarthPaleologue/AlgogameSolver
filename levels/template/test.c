#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "executeProgram.h"
#include "game.h"
#include "generator.h"
#include "matrix.h"
#include "paths.h"

#define NB_PROGRAMS 0

int main() {
    char programsToTest[NB_PROGRAMS][4][2] = {};

    initPath(LEVEL);
    initGlobals();
    resetMatrix();
    printf(BOLDCYAN "\n---------------------TESTING---------------------\n\n" RESET);

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < NB_PROGRAMS; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        // printProgramVerbose(program);

        executeProgram(program);

        free(program);

        if (gameWon()) {
            printf(GREEN "Tests passed: %d/%d\n" RESET, i + 1, NB_PROGRAMS);
        } else {
            successful = 0;
            printf(RED "\nERROR: Test n°%d failed\n" RESET, i + 1);
            break;
        }
    }

    printf("\n");

    if (successful) {
        printf(BOLDGREEN "The tests were successful\n" RESET);
        printf(BOLDCYAN "\n-----------------END OF TESTING------------------\n" RESET);
        return EXIT_SUCCESS;
    } else {
        printf(BOLDRED "The tests failed\n" RESET);
        printf(BOLDCYAN "\n-----------------END OF TESTING------------------\n" RESET);
        return EXIT_FAILURE;
    }
}
#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "executeProgram.h"
#include "game.h"
#include "generator.h"
#include "matrix.h"
#include "paths.h"

#define NB_PROGRAMS 12

int main() {
    char programsToTest[NB_PROGRAMS][7][2] = {
        {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},
        {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},
        {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},

        {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},
        {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},
        {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}},

        {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}},
        {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}},
        {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}},

        {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}},
        {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}},
        {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}}};

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

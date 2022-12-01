#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "generator.h"

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

    initPath();
    initMatrix();
    resetMatrix();
    printf("\n---------------------TESTING---------------------\n\n");

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < NB_PROGRAMS; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        // printProgramVerbose(program);

        resetStatus();

        executeProgram(program);

        free(program);

        if (gameWon()) {
            printf("Tests passed: %d/%d\n", i + 1, NB_PROGRAMS);
        } else {
            successful = 0;
            printf("\nERROR: Test n°%d failed\n", i + 1);
            break;
        }
    }

    printf("\n");

    if (successful) {
        printf("The tests were successful\n");
        printf("\n-----------------END OF TESTING------------------\n");
        return EXIT_SUCCESS;
    } else {
        printf("The tests failed\n");
        printf("\n-----------------END OF TESTING------------------\n");
        return EXIT_FAILURE;
    }
}

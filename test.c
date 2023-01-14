#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "executeProgram.h"
#include "game.h"
#include "generator.h"
#include "matrix.h"
#include "paths.h"

int main() {
#if LEVEL == 38
    int nbPrograms = 12;
    char programsToTest[12][7][2] = {
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
            {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}}
    };
#elif LEVEL == 12
    int nbPrograms = 7;
    char programsToTest[7][4][2] = {
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_NONE}, {F1, CD_NONE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_RED}, {F1, CD_NONE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_NONE}, {F1, CD_NONE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_RED}, {F1, CD_NONE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_NONE}, {F1, CD_ORANGE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_RED}, {F1, CD_ORANGE}},
            {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_NONE}, {F1, CD_BLUE}}
    };
#else
    printf(ORANGE "There are no tests for level %d!\n" RESET, LEVEL);
    return EXIT_FAILURE;
#endif


    initPath(LEVEL);
    initGlobals();
    resetMatrix();
    printf(BOLDCYAN "\n------------------TESTING-LVL%d------------------\n\n" RESET, LEVEL);

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < nbPrograms; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        // printProgramVerbose(program);

        executeProgram(program);

        free(program);

        if (gameWon()) printf(GREEN "Tests passed: %d/%d\n" RESET, i + 1, nbPrograms);
        else {
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

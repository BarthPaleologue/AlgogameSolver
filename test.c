#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "executeProgram.h"
#include "game.h"
#include "generator.h"
#include "matrix.h"
#include "paths.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf(BOLDRED "You need to specify the level number as an argument\n" RESET);
        return EXIT_FAILURE;
    }
    int level = atoi(argv[1]);

    char* programsToTest;
    int nbPrograms;

    if(level == 38) {
        nbPrograms = 12;
        programsToTest = malloc(nbPrograms * 7 * 2 * sizeof(char));

        programsToTest[0] = {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};
        programsToTest[1] = {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};
        programsToTest[2] = {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};

        programsToTest[3] = {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};
        programsToTest[4] = {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};
        programsToTest[5] = {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_NONE}};

        programsToTest[6] = {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};
        programsToTest[7] = {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};
        programsToTest[8] = {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_NONE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};

        programsToTest[9] = {{F2, CD_ORANGE}, {FORWARD, CD_RED}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};
        programsToTest[10] = {{FORWARD, CD_RED}, {F2, CD_NONE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};
        programsToTest[11] = {{FORWARD, CD_RED}, {F2, CD_ORANGE}, {F1, CD_ORANGE}, {TURN_LEFT, CD_ORANGE}, {FORWARD, CD_NONE}, {F2, CD_RED}, {TURN_LEFT, CD_ORANGE}};
    } else if (level == 12) {
        nbPrograms = 7;
        programsToTest = malloc(nbPrograms * 7 * 2 * sizeof(char));

        programsToTest[0] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_NONE}, {F1, CD_NONE}};
        programsToTest[1] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_RED}, {F1, CD_NONE}};
        programsToTest[2] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_NONE}, {F1, CD_NONE}};
        programsToTest[3] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_RED}, {F1, CD_NONE}};
        programsToTest[4] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_NONE}, {F1, CD_ORANGE}};
        programsToTest[5] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_ORANGE, CD_RED}, {F1, CD_ORANGE}};
        programsToTest[6] = {{FORWARD, CD_NONE}, {TURN_RIGHT, CD_RED}, {PAINT_BLUE, CD_NONE}, {F1, CD_BLUE}};
    } else {
        printf(ORANGE "There are no tests for level %d!\n" RESET, level);
        return EXIT_FAILURE;
    }

    initPath(LEVEL);
    initGlobals();
    resetMatrix();
    printf(BOLDCYAN "\n---------------------TESTING---------------------\n\n" RESET);

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < nbPrograms; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        // printProgramVerbose(program);

        executeProgram(program);

        free(program);

        if (gameWon()) printf(GREEN "Tests passed: %d/%d\n" RESET, i + 1, NB_PROGRAMS);
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

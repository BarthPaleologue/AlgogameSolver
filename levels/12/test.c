#include <stdio.h>
#include <stdlib.h>

#include "executeProgram.h"
#include "generator.h"
#include "matrix.h"

#define NB_PROGRAMS 7

int main() {
    char programsToTest[NB_PROGRAMS][4][2] = {
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_ORANGE,CD_NONE}, {F1,CD_NONE}}, 
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_ORANGE,CD_RED}, {F1,CD_NONE}}, 
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_BLUE,CD_NONE}, {F1,CD_NONE}}, 
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_BLUE,CD_RED}, {F1,CD_NONE}}, 
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_ORANGE,CD_NONE}, {F1,CD_ORANGE}}, 
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_ORANGE,CD_RED}, {F1,CD_ORANGE}},
    {{FORWARD,CD_NONE}, {TURN_RIGHT,CD_RED}, {PAINT_BLUE,CD_NONE}, {F1,CD_BLUE}}};

    initPath();
    initMatrix();
    resetMatrix();
    printf("\n---------------------TESTING---------------------\n\n");

    // printMatrix(matrix);

    char successful = 1;

    for (unsigned char i = 0; i < NB_PROGRAMS; i++) {
        Program program = getProgramFromVerboseArray(programsToTest[i]);
        // printProgramVerbose(program);

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

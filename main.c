#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "colors.h"
#include "debug.h"
#include "executeProgram.h"
#include "game.h"
#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"
#include "path.h"

/**
 * @brief Saves the generator state to a file when the program is killed
 *
 * @param signo the signal number
 */
void kill_handler(int signo) {
    if (signo == SIGINT) {
        printProgramState();
        writeProgramStateToFile(pathProgramState);
        exit(0);
    }
}

int main() {
    signal(SIGINT, kill_handler);

    initPath(LEVEL);
    printf("\n");

    // read from program_state.txt and update programState
    readProgramStateFromFile(pathProgramState);
    printf("\n");

    initGlobals();

    resetMatrix();

    printMatrix(matrix, matrixHeight, matrixWidth);

    printf(BOLDCYAN
           "\n"
           "-----------------------------------------------------------\n"
           "Algogame Solver will now begin searching for valid programs\n"
           "-----------------------------------------------------------\n\n" RESET);

    // printMatrix(matrix);

    unsigned long long n = 0;

    Program program = NULL;

    while ((program = generateNextProgram()) != NULL) {
        executeProgram(program);

        if (gameWon()) {
            printf(GREEN "\nThis program succeeded:\n" RESET);
            writeSolutionToFile(program, pathSolutions);
            printProgramVerbose(program);
        } /*else if (gameLost()) {
            printf("this program failed\n\n\n");
            printf("f-");
        } else if (gameTerminated()) {
            printf("this program terminated without finding the star\n\n\n");
            printf("i-");
        }*/

        printf("Tested programs: %llu\r", ++n);

        free(program);
    }
    printf(BOLDCYAN
           "\n"
           "-------------------------------------------\n"
           "Algogame Solver has found all the solutions\n"
           "-------------------------------------------\n\n" RESET);
    
    printf(BLUE "Erasing program_state.txt...\n");
    printf("All the solutions found were added to file solutions.txt\n\n" RESET);
    char command[36];
    sprintf(command, "rm -f ./levels/%d/program_state.txt", LEVEL);
    system(command);
    return 0;
}

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
#include "paths.h"

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

    printf("\n");

    // read from program_state.txt and update programState
    readProgramStateFromFile(pathProgramState);
    printf("\n");

    initGlobals();  // init global variables

    resetMatrix();  // reset matrix to initial state

    printMatrix(matrix, matrixHeight, matrixWidth);

    printf(BOLDCYAN
           "\n"
           "-----------------------------------------------------------\n"
           "Algogame Solver will now begin searching for valid programs\n"
           "-----------------------------------------------------------\n\n" RESET);

    unsigned long long nbTestedPrograms = 0;

    Program program = NULL;

    while ((program = generateNextProgram()) != NULL) {
        executeProgram(program);  // executes the program until game is won or lost

        if (gameWon()) {
            printf(GREEN "\nThis program succeeded:\n" RESET);
            printProgramVerbose(program);
            writeSolutionToFile(program, pathSolutions);
        }

        printf("Tested programs: %llu\r", ++nbTestedPrograms);

        free(program);
    }
    printf(BOLDCYAN
           "\n"
           "-------------------------------------------\n"
           "Algogame Solver has found all the solutions\n"
           "-------------------------------------------\n\n" RESET);

    // we don't need a program_state.txt file anymore
    printf(BLUE "Erasing program_state.txt...\n");
    printf("All the solutions found were added to file solutions.txt\n\n" RESET);
    char command[] = "rm -f ./levels/" xstr(LEVEL) "/program_state.txt";
    system(command);

    return 0;
}

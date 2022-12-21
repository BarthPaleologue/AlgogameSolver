#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "colors.h"
#include "executeProgram.h"
#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"

void kill_handler(int signo) {
    if (signo == SIGINT) {
        printProgramState();
        writeProgramStateToFile(pathProgramState);
        exit(0);
    }
}

int main() {
    signal(SIGINT, kill_handler);

    initPath();

    // read from program_state.txt and update programState
    readProgramStateFromFile(pathProgramState);

    initMatrix();
    resetMatrix();
    printf("\n\n\n");

    // printMatrix(matrix);

    unsigned long long n = 0;

    Program program = NULL;

    while ((program = generateNextProgram()) != NULL) {
        executeProgram(program);

        if (gameWon()) {
            printf(GREEN "\rThis program succeeded:\n" RESET);
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
    return 0;
}

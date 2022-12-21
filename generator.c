#include "generator.h"

#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "level_specifics.h"
#include "utils_struct.h"

const char NB_INSTRUCTIONS = NB_CONDITIONS * NB_ACTIONS;

char programState[PROGRAM_LENGTH];

void printProgramState() {
    printf("Program State: {");
    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        printf("%d", programState[i]);
        if (i < PROGRAM_LENGTH - 1)
            printf(", ");
    }
    printf("}\n");
}

void writeProgramStateToFile(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL)
        printf("Error opening file! Could not write the program state.\n");

    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        fprintf(file, "%d", programState[i]);
        if (i < PROGRAM_LENGTH - 1)
            fprintf(file, " ");
    }
    fprintf(file, "\nProgram State: {");
    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        fprintf(file, "%d", programState[i]);
        if (i < PROGRAM_LENGTH - 1)
            fprintf(file, ", ");
    }
    fprintf(file, "}\n");
    fclose(file);
}

void readProgramStateFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        for (int i = 0; i < PROGRAM_LENGTH; i++) {
            fscanf(file, "%hhd", &programState[i]);
        }
        fclose(file);
    } else {
        printf(YELLOW "Error while reading file %s\nThe generator will be initialized at 0\n" RESET, filename);
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            programState[i] = 0;
        }
    }
}

void printProgramVerbose(Program p) {
    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        char* actionStr;
        char* conditionStr;
        switch (p[i].action) {
            case FORWARD:
                actionStr = "FRWRD";
                break;
            case TURN_LEFT:
                actionStr = "TRN_LFT";
                break;
            case TURN_RIGHT:
                actionStr = "TRN_RGHT";
                break;
            case PAINT_RED:
                actionStr = RED "PNT_R" RESET;
                break;
            case PAINT_BLUE:
                actionStr = CYAN "PNT_B" RESET;
                break;
            case PAINT_ORANGE:
                actionStr = YELLOW "PNT_O" RESET;
                break;
            case F1:
                actionStr = "F1";
                break;
            case F2:
                actionStr = "F2";
                break;
            case F3:
                actionStr = "F3";
                break;
            case F4:
                actionStr = "F4";
                break;
        }
        switch (p[i].condition) {
            case CD_NONE:
                conditionStr = "_";
                break;
            case CD_RED:
                conditionStr = RED "R" RESET;
                break;
            case CD_ORANGE:
                conditionStr = YELLOW "O" RESET;
                break;
            case CD_BLUE:
                conditionStr = CYAN "B" RESET;
                break;
        }
        if (i == F2_START || i == F3_START || i == F4_START) printf("  ");
        printf("[%s;%s] ", actionStr, conditionStr);
    }
    printf("\n\n");
}

Program getProgramFromVerboseArray(char programArray[PROGRAM_LENGTH][2]) {
    Program p = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);
    for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
        p[i].action = programArray[i][0];
        p[i].condition = programArray[i][1];
    }
    return p;
}

Program generateNextProgram() {
    Program program = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);

    do {
        // generate program using the current state
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            program[i].action = possibleActions[programState[i] / NB_CONDITIONS];
            program[i].condition = possibleConditions[programState[i] % NB_CONDITIONS];
        }

        // increment state
        int checkSum = 0;
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            if (programState[i] != NB_INSTRUCTIONS - 1) {
                programState[i] += 1;
                checkSum += programState[i];
                break;
            }
            programState[i] = 0;
        }
        if (checkSum == 0) {
            free(program);
            return NULL;
        }
    } while (!isProgramWorthTesting(program));

    return program;
}
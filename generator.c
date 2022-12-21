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
        printf(GREEN "File %s read successfully\nThe generator will be initialized at the given value\n" RESET, filename);
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

void printProgramVerbose(Program p, char * filename) {
    FILE* file = fopen(filename, "a");
    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        char* actionStr;
        char* conditionStr;
        char* actionStr2;
        char* conditionStr2;
        switch (p[i].action) {
            case FORWARD:
                actionStr = "FRWRD";
                actionStr2 = "FRWRD";
                break;
            case TURN_LEFT:
                actionStr = "TRN_LFT";
                actionStr2 = "TRN_LFT";
                break;
            case TURN_RIGHT:
                actionStr = "TRN_RGHT";
                actionStr2 = "TRN_RGHT";
                break;
            case PAINT_RED:
                actionStr = RED "PNT_R" RESET;
                actionStr2 = "PNT_R";
                break;
            case PAINT_BLUE:
                actionStr = CYAN "PNT_B" RESET;
                actionStr2 = "PNT_B";
                break;
            case PAINT_ORANGE:
                actionStr = ORANGE "PNT_O" RESET;
                actionStr2 = "PNT_O";
                break;
            case F1:
                actionStr = "F1";
                actionStr2 = "F1";
                break;
            case F2:
                actionStr = "F2";
                actionStr2 = "F2";
                break;
            case F3:
                actionStr = "F3";
                actionStr2 = "F3";
                break;
            case F4:
                actionStr = "F4";
                actionStr2 = "F4";
                break;
        }
        switch (p[i].condition) {
            case CD_NONE:
                conditionStr = "_";
                conditionStr2 = "_";
                break;
            case CD_RED:
                conditionStr = RED "R" RESET;
                conditionStr2 = "R";
                break;
            case CD_ORANGE:
                conditionStr = ORANGE "O" RESET;
                conditionStr2 = "O";
                break;
            case CD_BLUE:
                conditionStr = CYAN "B" RESET;
                conditionStr2 = "B";
                break;
        }
        if (i == F2_START || i == F3_START || i == F4_START) printf("  ");
        printf("[%s;%s] ", actionStr, conditionStr);
        if (file) 
            fprintf(file, "[%s;%s] ", actionStr2, conditionStr2);
    }
    fprintf(file, "\n\n");
    fclose(file);
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
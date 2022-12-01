#include "generator.h"

#include <stdio.h>
#include <stdlib.h>

const char NB_INSTRUCTIONS = (sizeof(possibleConditions) / sizeof(possibleConditions[0]) * sizeof(possibleActions) / sizeof(possibleActions[0]));

char programState[PROGRAM_LENGTH];

/**
 * @brief print the state of the generator to stdout
 *
 */
void printProgramState() {
    printf("Program State: {");
    for (int i = 0; i < PROGRAM_LENGTH; i++) {
        printf("%d", programState[i]);
        if (i < PROGRAM_LENGTH - 1)
            printf(", ");
    }
    printf("}\n");
}

/**
 * @brief Write the state of the generator to a file
 *
 * @param filename The name of the file to write to
 */
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

/**
 * @brief Read the generation state from a file and init the generator. Will init to 0 if no file is found.
 *
 * @param filename The file to read from
 */
void readProgramStateFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        for (int i = 0; i < PROGRAM_LENGTH; i++) {
            fscanf(file, "%hhd", &programState[i]);
        }
    } else {
        printf("Error while reading file %s\nThe generator will be initialized at 0", filename);
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            programState[i] = 0;
        }
    }
}

void printProgram(Program p) {
    printf("Actions:    %d %d %d %d %d %d %d\n", p[0].action, p[1].action, p[2].action, p[3].action, p[4].action, p[5].action, p[6].action);
    printf("Conditions: %d %d %d %d %d %d %d\n\n", p[0].condition, p[1].condition, p[2].condition, p[3].condition, p[4].condition, p[5].condition, p[6].condition);
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
                actionStr = "PNT_R";
                break;
            case PAINT_BLUE:
                actionStr = "PNT_B";
                break;
            case F1:
                actionStr = "F1";
                break;
            case F2:
                actionStr = "F2";
                break;
        }
        switch (p[i].condition) {
            case CD_NONE:
                conditionStr = "_";
                break;
            case CD_RED:
                conditionStr = "R";
                break;
            case CD_ORANGE:
                conditionStr = "O";
                break;
            case CD_BLUE:
                conditionStr = "B";
                break;
        }
        if (i == 3) printf("  ");
        printf("[%s;%s] ", actionStr, conditionStr);
    }
    printf("\n\n");
}

/**
 * A ne pas tester: (évaluer la stratégie avant de la soumettre)
 * - Si y a pas avancer
 * - Si y a pas F1 & F2
 * - Si y a pas (tourner à droite || tourner à gauche)
 * - Si y a peindre en rouge sur rouge || peindre en bleu sur bleu
 */

/**
 * @brief Check if a program is worth testing according to arbitrary rules
 *
 * @param p The program to check
 * @return char 1 if the program is worth testing, 0 otherwise
 */
char isProgramWorthTesting(Program p) {
    char nbForwardActions = 0;
    char nbTurnActions = 0;
    char nbF1Calls = 0;
    char nbF2Calls = 0;

    if (p[0].action == F1) {
        return 0;
    }

    for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
        switch (p[i].action) {
            case FORWARD:
                nbForwardActions++;
                break;
            case TURN_RIGHT:
            case TURN_LEFT:
                nbTurnActions++;
                break;
            case F1:
                nbF1Calls++;
                break;
            case F2:
                if (i < 3) {
                    nbF2Calls++;
                }
                break;
            default:
                break;
        }
    }

    if (nbForwardActions == 0) return 0;
    if (nbTurnActions == 0) return 0;
    if (nbF1Calls == 0) return 0;
    if (nbF2Calls == 0) return 0;
    return 1;
}

/**
 * @brief Generate a program from an array of array2[action, condition]
 *
 * @param programArray
 * @return Program
 */
Program getProgramFromVerboseArray(char programArray[PROGRAM_LENGTH][2]) {
    Program p = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);
    for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
        p[i].action = programArray[i][0];
        p[i].condition = programArray[i][1];
    }
    return p;
}

/**
 * @brief Generate the next program worthy of testing
 *
 * @return Program The next program
 */
Program generateNextProgram() {
    Program program = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);

    do {
        // generate program using this state
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            program[i].action = possibleActions[programState[i] / NB_CONDITIONS];
            program[i].condition = possibleConditions[programState[i] % NB_CONDITIONS];
        }

        // increment state
        int checkSum = 0;
        for (unsigned char i = 0; i < NB_INSTRUCTIONS; i++) {
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
#include "algos.h"

#include <stdio.h>
#include <stdlib.h>

const char NB_ACTIONS = 7;

const char NB_CONDITIONS = 4;

const char NB_INSTRUCTIONS = NB_CONDITIONS * NB_ACTIONS;

const char PROGRAM_LENGTH = 7;

char programState[7] = {0, 0, 0, 0, 0, 0, 0};

void printProgramState() {
    printf("Program state: %d %d %d %d %d %d %d\n", programState[0], programState[1], programState[2], programState[3], programState[4], programState[5], programState[6]);
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

Program getProgramFromArray(char* array) {
    Program p = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);
    for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
        p[i].action = array[i] / NB_CONDITIONS;
        p[i].condition = array[i] % NB_CONDITIONS;
    }
    return p;
}

// Program program = generateNextProgram();
Program generateNextProgram() {
    Program program = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);

    do {
        // generate program using this state
        for (unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
            program[i].action = programState[i] / NB_CONDITIONS;
            program[i].condition = programState[i] % NB_CONDITIONS;
        }

        // printProgram(program);

        // increment state
        for (unsigned char i = 0; i < NB_INSTRUCTIONS; i++) {
            if (programState[i] != NB_INSTRUCTIONS - 1) {
                programState[i] += 1;
                break;
            }
            programState[i] = 0;
        }
    } while (!isProgramWorthTesting(program));

    // printProgramState();
    return program;
}
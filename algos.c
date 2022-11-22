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

/**
 * A ne pas tester: (évaluer la stratégie avant de la soumettre)
 * - Si y a pas avancer
 * - Si y a pas F1 & F2
 * - Si y a pas (tourner à droite || tourner à gauche)
 * - Si y a peindre en rouge sur rouge || peindre en bleu sur bleu
 */

// Program program = generateNextProgram();
Program generateNextProgram() {
    Program program = malloc(sizeof(struct Instruction) * PROGRAM_LENGTH);

    // generate program using this state
    for(unsigned char i = 0; i < PROGRAM_LENGTH; i++) {
        program[i].action = programState[i] / NB_CONDITIONS;
        program[i].condition = programState[i] % NB_CONDITIONS;
    }

    //printProgram(program);

    // increment state
    for(unsigned char i = 0; i < NB_INSTRUCTIONS; i++) {
        if(programState[i] != NB_INSTRUCTIONS - 1) {
            programState[i] += 1;
            break;
        }
        programState[i] = 0;
    }

    //printProgramState();
    return program;
}
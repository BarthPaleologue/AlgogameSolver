#ifndef GENERATOR_H
#define GENERATOR_H

#include "level_specifics.h"

extern char programState[PROGRAM_LENGTH];

struct Instruction {
    enum Action action;
    enum Condition condition;
};

typedef struct Instruction* Program;

Program generateNextProgram();

void printProgramState();

void writeProgramStateToFile(char* filename);

void readProgramStateFromFile(char* filename);

Program getProgramFromVerboseArray(char programArray[PROGRAM_LENGTH][2]);

char isProgramWorthTesting(Program p);

void printProgramVerbose(Program p);

#endif
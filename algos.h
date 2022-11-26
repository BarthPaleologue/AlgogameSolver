#ifndef GENERATOR_H
#define GENERATOR_H

#define PROGRAM_LENGTH 7

#define NB_ACTIONS 7

#define NB_CONDITIONS 4

#define F1_LENGTH 3

#define F2_LENGTH 4

enum Action {
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
    PAINT_RED,
    PAINT_BLUE,
    F1,
    F2
};

enum Condition {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE
};

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

Program getProgramFromArray(char* array);

char isProgramWorthTesting(Program p);

void printProgram(Program p);

void printProgramVerbose(Program p);

#endif
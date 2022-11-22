#ifndef ALGOS
#define ALGOS

enum Action {
    FORWARD,
    TURN_LEFT, TURN_RIGHT,
    PAINT_RED, PAINT_BLUE,
    F1, F2
};

const int NB_ACTIONS = 7;

enum Condition {
    CD_NONE, CD_RED, CD_ORANGE, CD_BLUE
};

const int NB_CONDITIONS = 4;

const int NB_INSTRUCTIONS = NB_CONDITIONS * NB_ACTIONS;

const int PROGRAM_LENGTH = 7;

struct Instruction {
    enum Action action;
    enum Condition condition;
};

typedef struct Instruction* Program;

Program generateNextProgram();

void printProgramState();

void printProgram(Program p);

#endif
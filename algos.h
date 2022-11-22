#ifndef ALGOS
#define ALGOS

enum Action {
    FORWARD,
    TURN_LEFT, TURN_RIGHT,
    PAINT_RED, PAINT_BLUE,
    F1, F2
};

extern const int NB_ACTIONS;

enum Condition {
    CD_NONE, CD_RED, CD_ORANGE, CD_BLUE
};

extern const int NB_CONDITIONS;

extern const int NB_INSTRUCTIONS;

extern const int PROGRAM_LENGTH;

struct Instruction {
    enum Action action;
    enum Condition condition;
};

typedef struct Instruction* Program;

Program generateNextProgram();

void printProgramState();

void printProgram(Program p);

#endif
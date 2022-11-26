#ifndef ALGOS
#define ALGOS

enum Action {
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
    PAINT_RED,
    PAINT_BLUE,
    F1,
    F2
};

extern const char NB_ACTIONS;

enum Condition {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE
};

extern char programState[7];

extern const char NB_CONDITIONS;

extern const char NB_INSTRUCTIONS;

extern const char PROGRAM_LENGTH;

struct Instruction {
    enum Action action;
    enum Condition condition;
};

typedef struct Instruction* Program;

Program generateNextProgram();

void printProgramState();

void writeProgramStateToFile(char* filename);

Program getProgramFromVerboseArray(char programArray[7][2]);

Program getProgramFromArray(char* array);

char isProgramWorthTesting(Program p);

void printProgram(Program p);

void printProgramVerbose(Program p);

#endif
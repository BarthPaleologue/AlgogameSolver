#ifndef UTILS_STRUCT
#define UTILS_STRUCT

enum Action {
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
    PAINT_RED,
    PAINT_BLUE,
    PAINT_ORANGE,
    F1,
    F2,
    F3,
    F4
};

enum Condition {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE
};

struct Instruction {
    enum Action action;
    enum Condition condition;
};

/**
 * @brief An array of instructions is called a program
 */
typedef struct Instruction* Program;

#endif
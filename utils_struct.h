#ifndef UTILS_STRUCT
#define UTILS_STRUCT

/**
 * @brief Direction in the map.
 */
enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

/**
 * @brief Coordinates on the map.
 * Careful, the position is at matrix[y][x].
 */
struct Coords {
    unsigned char x;
    unsigned char y;
};

/**
 * @brief Possible actions of an instruction.
 */
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

/**
 * @brief Possible conditions of an instruction.
 */
enum Condition {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE
};

/**
 * @brief An instruction is composed of an action and a condition.
 */
struct Instruction {
    enum Action action;
    enum Condition condition;
};

/**
 * @brief An array of instructions is called a program
 */
typedef struct Instruction* Program;

#endif
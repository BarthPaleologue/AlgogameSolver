#ifndef LEVEL_SPECIFICS_H
#define LEVEL_SPECIFICS_H

#define PROGRAM_LENGTH 7

#define F1_LENGTH 3

#define F2_LENGTH 4

#define F3_LENGTH 0

#define F4_LENGTH 0

#define MAX_EXECUTION_ITERATIONS 120

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

#define NB_ACTIONS 7
extern const enum Action possibleActions[NB_ACTIONS];

#define NB_CONDITIONS 4
extern const enum Condition possibleConditions[NB_CONDITIONS];

extern int levelNumber;

extern char pathStarsMap[22];

extern char pathMap[17];

void initPath();

#endif
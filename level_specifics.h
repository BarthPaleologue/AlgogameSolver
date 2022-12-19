#ifndef LEVEL_SPECIFICS_H
#define LEVEL_SPECIFICS_H

#define PROGRAM_LENGTH 7

#define F2_START 3

#define F3_START 8 //this length is never obtained !
//we need to use a value that is impossible so the Solver doesn't misleadingly tells us F3 is reached

#define F4_START 8 //this length is never obtained ! same comment as above

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
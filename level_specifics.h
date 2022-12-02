#ifndef LEVEL_SPECIFICS_H
#define LEVEL_SPECIFICS_H

#define PROGRAM_LENGTH 7

#define F1_START 0
#define F2_START 3
#define F3_START -1
#define F4_START -1

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

extern int numberOfStars;

extern int levelNumber;

extern char pathStarsMap[22];

extern char pathMap[17];

void initPath();

#endif
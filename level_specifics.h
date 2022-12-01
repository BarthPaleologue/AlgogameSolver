#ifndef LEVEL_SPECIFICS_H
#define LEVEL_SPECIFICS_H

#define PROGRAM_LENGTH 7

#define NB_ACTIONS 7

#define NB_CONDITIONS 4

#define F1_LENGTH 3

#define F2_LENGTH 4

#define MAX_EXECUTION_ITERATIONS 120

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

extern const enum Action possibleActions[NB_ACTIONS];

extern const enum Condition possibleConditions[NB_CONDITIONS];

extern int numberOfStars;

extern int levelNumber;

extern char pathStarsMap[22];

extern char pathMap[17];

void initPath();

#endif
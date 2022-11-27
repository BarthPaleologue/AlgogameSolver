#include "level_specifics.h"

const enum Action possibleActions[NB_ACTIONS] = {
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
    PAINT_RED,
    PAINT_BLUE,
    F1,
    F2,
};

const enum Condition possibleConditions[NB_CONDITIONS] = {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE,
};
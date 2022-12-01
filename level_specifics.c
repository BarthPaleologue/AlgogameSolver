#include <stdio.h>
#include <stdlib.h>
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

int numberOfStars;

int levelNumber = 38;

//creation of paths 
char pathStarsMap[22];
char pathMap[17];

void initPath() {
    char starsMap[] = "./level%dstarsMap.txt";
    char map[] = "./level%dmap.txt";

    sprintf(pathStarsMap, starsMap, levelNumber);
    sprintf(pathMap, map, levelNumber);

    printf("pathStarsMap: %s", pathStarsMap);
    printf("pathMap: %s", pathMap);
}
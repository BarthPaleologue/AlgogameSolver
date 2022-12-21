#include "path.h"

#include <stdio.h>

// creation of paths
char pathStarsMap[30];  // 30 is for two digits in levelNumber
char pathMap[25];       // same
char pathProgramState[30];

void initPath(int level) {
    char starsMap[] = "./levels/%d/levelStarsMap.txt";
    char map[] = "./levels/%d/levelMap.txt";
    char programState[] = "./levels/%d/program_state.txt";

    sprintf(pathStarsMap, starsMap, level);
    sprintf(pathMap, map, level);
    sprintf(pathProgramState, programState, level);

    printf("pathStarsMap: %s\n", pathStarsMap);
    printf("pathMap: %s\n", pathMap);
    printf("pathProgramState: %s\n", pathProgramState);
}
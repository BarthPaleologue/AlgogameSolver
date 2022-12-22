#include "paths.h"

#include <stdio.h>

// creation of paths
char pathStarsMap[30];  // 30 is for two digits in levelNumber
char pathMap[25];       // same
char pathProgramState[30];
char pathSolutions[26];

void initPath(int level) {
    char starsMap[] = "./levels/%d/levelStarsMap.txt";
    char map[] = "./levels/%d/levelMap.txt";
    char programState[] = "./levels/%d/program_state.txt";
    char solutions[] = "./levels/%d/solutions.txt";

    sprintf(pathStarsMap, starsMap, level);
    sprintf(pathMap, map, level);
    sprintf(pathProgramState, programState, level);
    sprintf(pathSolutions, solutions, level);

    printf("pathStarsMap: %s\n", pathStarsMap);
    printf("pathMap: %s\n", pathMap);
    printf("pathProgramState: %s\n", pathProgramState);
    printf("pathSolutions: %s\n", pathSolutions);
}
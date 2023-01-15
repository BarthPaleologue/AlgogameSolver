#include <stdio.h>
#include "paths.h"
#include "level_specifics.h"

// creation of paths
/*char pathStarsMap[30];  // 30 is for two digits in levelNumber
char pathMap[25];       // same
char pathProgramState[30];
char pathSolutions[26];*/

char pathStarsMap[] = "./levels/" xstr(LEVEL) "/levelStarsMap.txt";
char pathMap[] = "./levels/" xstr(LEVEL) "/levelMap.txt";
char pathProgramState[] = "./levels/" xstr(LEVEL) "/program_state.txt";
char pathSolutions[] = "./levels/" xstr(LEVEL) "/solutions.txt";

    /*sprintf(pathStarsMap, starsMap, level);
    sprintf(pathMap, map, level);
    sprintf(pathProgramState, programState, level);
    sprintf(pathSolutions, solutions, level);*/

    /*printf("pathStarsMap: %s\n", pathStarsMap);
    printf("pathMap: %s\n", pathMap);
    printf("pathProgramState: %s\n", pathProgramState);
    printf("pathSolutions: %s\n", pathSolutions);*/
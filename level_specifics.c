#include <stdio.h>
#include <stdlib.h>
#include "level_specifics.h"
#include "matrix.h"

/*This file AND its header contain all the info that needs to be changed according to the level you're testing.

More precisely, you will need to :
- precise all the instructions that can be used to solve the level (this file : INSTRUCTIONS)
- precise the starting direction : RIGHT, DOWN, LEFT or UP (this file : START)
- create two maps conforming to the instructions given in this file (see MORE ON MAPS)
- precise the paths to these maps (this file : PATHS TO MAP FILES)
- precise the length of the program and of its functions (header file : NUMBER OF INSTRUCTIONS)
- precise the number of different instructions that can be used (header file : NUMBER OF INSTRUCTIONS)
*/



//INSTRUCTIONS

const enum Action possibleActions[NB_ACTIONS] = {
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
    PAINT_RED,
    PAINT_BLUE,
    F1,
    F2,
}; //check for PAINT_ORANGE and the number of functions

const enum Condition possibleConditions[NB_CONDITIONS] = {
    CD_NONE,
    CD_RED,
    CD_ORANGE,
    CD_BLUE,
};

//START

enum Direction startingDirection = RIGHT;

//MORE ON MAPS

/*In our code, we rely on two maps named levelxxmap.txt and levelxxstarsMap.txt.

The first map contains the shape of the map and all the cases' colours.
This is the map for level 38 :

__________
____R_____
____R_____
_ORRO_____
_RORRRRRO_
_RR_R___R_
_ORRORORR_
__ORR_R_R_
____ORRRO_
______R___
_____RO___
__________


_ : no case ; R : red case ; O : orange case ; B : blue case
Try only to use these 4 characters and '\n'. 
Make sure your map is rectangular and IMPORTANT : that's there's a padding of _ on each border.


The stars' map is a copy-paste of the first one, except you add all the stars, and an 'X' at the start position.
This is the stars' map for level 38 :

__________
____*_____
____R_____
_ORRO_____
_RORRRRRO_
_RR_R___R_
_ORRORORR_
__ORR_R_R_
____ORRRO_
______R___
_____XO___
__________

Try only to use the 5 above mentionned characters, plus '*' and 'X'. Careful it's a higher case X.*/



//PATHS TO MAP FILES

static int levelNumber = 38;
//the level number is only used when getting the map files right below 
//careful, we supposed that it was a number with two digits

//creation of paths 
char pathStarsMap[22]; //22 is for two digits in levelNumber
char pathMap[17]; //same

void initPath() {
    char starsMap[] = "./level%dstarsMap.txt";
    char map[] = "./level%dmap.txt";

    sprintf(pathStarsMap, starsMap, levelNumber);
    sprintf(pathMap, map, levelNumber);

    printf("pathStarsMap: %s\n", pathStarsMap);
    printf("pathMap: %s\n", pathMap);
}
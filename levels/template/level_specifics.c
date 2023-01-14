#include "level_specifics.h"

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"  //this file contains the definition of enum Direction
#include "utils_struct.h"

/*This file AND its header contain all the info that needs to be changed according to the level you're testing.

More precisely, you will need to :
- precise all the instructions that can be used to solve the level (this file : INSTRUCTIONS)
- precise the starting direction : RIGHT, DOWN, LEFT or UP (this file : START)
- create two maps conforming to the instructions given in this file (see MORE ON MAPS)
- precise the paths to these maps (this file : PATHS TO MAP FILES)
- precise the length of the program and of its functions (header file : NUMBER OF INSTRUCTIONS)
- precise the number of different instructions that can be used (header file : NUMBER OF INSTRUCTIONS)
*/

// INSTRUCTIONS
//TODO: remove actions that are not used
const enum Action possibleActions[NB_ACTIONS] = {
        FORWARD,
        TURN_LEFT,
        TURN_RIGHT,
        PAINT_RED,
        PAINT_ORANGE,
        PAINT_BLUE,
        F1,
        F2,
        F3,
        F4,
};
//TODO: remove conditions that are not used
const enum Condition possibleConditions[NB_CONDITIONS] = {
        CD_NONE,
        CD_RED,
        CD_ORANGE,
        CD_BLUE
};

// START
//TODO: change this to the starting direction
enum Direction startingDirection = RIGHT;

// MORE ON MAPS

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

// PATHS TO MAP FILES

//TODO: set the level number
int LEVEL = 0;  // careful, we supposed that it was a number with two digits

// TESTING

/**
 * @brief Check if a program is worth testing according to arbitrary rules
 *
 * @param p The program to check
 * @return char 1 if the program is worth testing, 0 otherwise
 */
char isProgramWorthTesting(Program p) {
    //TODO: add conditions to reduce the number of programs to test
    return 1;
}

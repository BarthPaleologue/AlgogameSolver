#ifndef LEVEL_SPECIFICS_H
#define LEVEL_SPECIFICS_H

#include "matrix.h"

//TODO : peut etre déplacer Action et Condition vu que ça devrait surtout pas etre changé par l'utilisateur ??
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


/*This file contains some info that need to be changed with each different level 
in the NUMBER OF INSTRUCTIONS section.
Please consult "levelspecifics.c" for all the details of adapting the code to different levels.*/



//NUMBER OF INSTRUCTIONS

 ///@brief Total number of instructions in the program.
 ///
#define PROGRAM_LENGTH 7 


///
 ///@brief Position index of function F1 (always 0)
 ///
 ///
#define F1_START 0

 ///@brief Position index of function F2 (number of instructions in function F1).
 ///
#define F2_START 3


 ///@brief Position index of function F3 (number of instructions in functions F1 and F2).
 /// In case there's no F3, set it to PROGRAM_LENGTH.
 ///
#define F3_START 7


 ///@brief Position index of function F4 (number of instructions in functions F1, F2 and F3).
 /// In case there's no F4, set it to PROGRAM_LENGTH.
 ///
#define F4_START 7

/*Remarks about F3_START and F4_START :
Their value can be set to anything as long as it's not an index of an instruction in the program.
Any negative value or higher than PROGRAM_LENGTH is fine.*/


 ///@brief Number of executed instructions after which the solver should discard a program.
 /// The complexity of potential winning trajectory needs to be taken into account.
 ///
#define MAX_EXECUTION_ITERATIONS 120


 ///@brief Number of possible actions the instructions make.
 ///
 ///
#define NB_ACTIONS 7
extern const enum Action possibleActions[NB_ACTIONS];


 ///@brief Number of of possible conditions on instructions.
 ///
 ///
#define NB_CONDITIONS 4
extern const enum Condition possibleConditions[NB_CONDITIONS];




//EXPORTING GLOBAL VARIABLES AND FUNCTIONS

extern enum Direction startingDirection;

extern char pathStarsMap[22];

extern char pathMap[17];

void initPath();

#endif
#ifndef GENERATOR_H
#define GENERATOR_H

#include "level_specifics.h"

extern char programState[PROGRAM_LENGTH];

struct Instruction {
    enum Action action;
    enum Condition condition;
};

/**
 * @brief An array of instructions is called a program
 *
 */
typedef struct Instruction* Program;

/**
 * @brief Generate the next program worthy of testing
 *
 * @return Program The next program
 */
Program generateNextProgram();

/**
 * @brief print the state of the generator to stdout
 *
 */
void printProgramState();

/**
 * @brief Write the state of the generator to a file
 *
 * @param filename The name of the file to write to
 */
void writeProgramStateToFile(char* filename);

/**
 * @brief Read the generation state from a file and init the generator. Will init to 0 if no file is found.
 *
 * @param filename The file to read from
 */
void readProgramStateFromFile(char* filename);

/**
 * @brief Generate a program from an array of array2[action, condition]
 *
 * @param programArray
 * @return Program
 */
Program getProgramFromVerboseArray(char programArray[PROGRAM_LENGTH][2]);

/**
 * @brief Check if a program is worth testing according to arbitrary rules
 *
 * @param p The program to check
 * @return char 1 if the program is worth testing, 0 otherwise
 */
char isProgramWorthTesting(Program p);

/**
 * @brief prints the given program as a sequence of readable instructions [Action;Condition]
 *
 * @param p the program to print
 */
void printProgramVerbose(Program p);

#endif
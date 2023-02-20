#ifndef GENERATOR_H
#define GENERATOR_H

#include "level_specifics.h"
#include "utils_struct.h"

/**
 * @brief The state of the program generator
 *
 */
extern char generatorState[PROGRAM_LENGTH];

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
void printGeneratorState();

/**
 * @brief Write the state of the generator to a file
 *
 * @param filename The name of the file to write to
 */
void writeGeneratorStateToFile(char* filename);

/**
 * @brief Read the generation state from a file and init the generator. Will init to 0 if no file is found.
 *
 * @param filename The file to read from
 */
void readGeneratorStateFromFile(char* filename);

/**
 * @brief Generate a program from an array of array2[action, condition]
 *
 * @param programArray
 * @return Program
 */
Program getProgramFromVerboseArray(char programArray[PROGRAM_LENGTH][2]);

/**
 * @brief prints the given program as a sequence of readable instructions [Action;Condition]
 *
 * @param p the program to print
 */
void printProgramVerbose(Program p);

/**
 * @brief prints the given program to a file
 *
 * @param p program
 *
 * @param filename path to the file
 */
void writeSolutionToFile(Program p, char* filename);

#endif
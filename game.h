#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

extern int programCase;

void doInstruction(enum Action action, enum Condition condition);

void updateProgramCase();

void resetStatus();

void executeProgram(Program program);

#endif
# AlgogameSolver

[![C/C++ CI](https://github.com/BarthPaleologue/AlgogameSolver/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/BarthPaleologue/AlgogameSolver/actions/workflows/c-cpp.yml)

Algogame is a puzzle game centered around algorithmic concepts such as functions and recursion. It can be some kind of a hassle sometimes so it appeared necessary to create a solution capable of breaking any level of the game. The game is available on the google playstore at <a href="https://play.google.com/store/apps/details?id=com.evrardnil.algo_game&hl=fr&gl=US&pli=1">https://play.google.com/store/apps/details?id=com.evrardnil.algo_game&hl=fr&gl=US&pli=1</a>

## Installation

### Cloning

First you need to clone the repository on your computer.

```sh
git clone https://github.com/BarthPaleologue/AlgogameSolver.git
```

You will need to have installed two other tools to make the solver work.

### GCC

You will need gcc to compile the code for your computer's hardware. There are many tutorials online for you available if you are on Windows. Linux users should already have gcc installed on their machine.
### MAKE

The second tool is Make. As for GCC, there are many tutorials online on how to install Make on your machine so that we can use `make` later.

## Breaking a specific level

You need to copy paste a folder from `./levels` and follow the instructions given in `./levels/*/level_specifics.c`.

In short, you need to provide sufficient information about the level (a map of the level, the instructions provided, how many instructions are in the program, etc.). You can also provide informations to reduce the number of tests : a successful program must have at least one TURN_RIGHT intruction or one PAINT_RED...


## Run it!

When you have completed all the above steps, you should be able to run the program by entering the command `make anew` in your terminal in the directory of the solver. If you made no mistake, the solver will start brute forcing the level.
You might have to wait for a few hours depending on the complexity of the level (ie the number of instructions in the program) and the effectiveness of your constraints.
The program will output all the solutions in the console as you run it.
You can stop at anytime with ^C and start back where you left it thanks to the program's autosave system.

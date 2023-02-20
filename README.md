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

All the instructions are given in `./levels/template/level_specifics.c`.
Once you've completed all the info, you can run your code. But make sure that the Makefile is building the right executive : set the `LEVEL` variable to the name of the folder you used (ex : template) in the first line of the Makefile.
Ex : LEVEL='template'

#### How does it work ?
In `./levels/template` are all the files you need to modify so that the program will be adapted to a particular level. You will need to provide sufficient information about the level (a map of the level, the instructions provided, how many instructions are in the program, etc.). 

#### Breaking different levels
You can copy paste the template folder to `./levels` to break different levels. You can rename it as you want, any folder in `./levels` is treated the same, but you have to respect these two conditions :
- the variable LEVEL defined in level_specifics has to be set to the name of the folder it is in <br> Ex : #define LEVEL template
- don't forget to specify the folder to the Makefile using LEVEL=template in the Makefile or in command-line



#### Speeding up AlgoGame
Note that can probably provide informations to reduce the number of tests : a successful program might need at least one TURN_RIGHT intruction or one PAINT_RED... In any case it always needs at least one FORWARD. The function to be modified is `isProgramWorthTesting` in `level_specifics.c`. Testing can take less than a second or over an hour depending on the level, the speed of your machine and also your restrictions, so don't hesitate.


## Run it!

When you have completed all the above steps, you should be able to run the program by entering the command `make` in your terminal in the directory of the solver (or eventually `make LEVEL=template` if you haven't set the LEVEL variable directly in the Makefile). If you followed the instructions, the solver will start brute forcing the level. 

If you made any changes to the code except in the `./levels` folder, you should run `make run-build` instead of `make` so that the code undergoes some fucntionning checks.
You might have to wait for a few hours depending on the complexity of the level (ie the number of instructions in the program) and the effectiveness of your constraints.
The program will output all the solutions in the console as you run it.
You can stop at anytime with ^C and start back where you left it thanks to the program's autosave system.
# AlgogameSolver

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
### CMAKE

The second tool is CMake. As for GCC, there are many tutorials online on how to install CMake on your machine.

## Breaking a specific level

First, you need to procure a map of the level (see level38.txt for the color conventions). 

Note that it's important for the solver's functionment that you add a padding of "white cases" on each border.


## Run it!

When you have completed all the above steps, you should be able to run the program by entering the command `make` in your terminal in the directory of the solver. If you made no mistake, all tests will pass and the solver will start brute forcing the level.
You might have to wait for a few hours depending on the complexity of the level and the effectiveness of your constraints.
The program will output all the solutions in the console as you run it.
You can stop at anytime and start back where you left it thanks to the program's autosave system.
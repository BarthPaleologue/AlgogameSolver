#ifndef PATH_H
#define PATH_H

#define xstr(s) str(s)
#define str(s) #s

/**
 * @brief Path to the file containing the starmap (the map containing the star positions).
 *
 */
extern char pathStarsMap[];

/**
 * @brief Path to the file containing the map (the map without the stars).
 *
 */
extern char pathMap[];

/**
 * @brief Path to the file containing the generator state backup (to start the execution where you left it).
 *
 */
extern char pathGeneratorState[];

/**
 * @brief Path to the file containing the solutions found.
 *
 */
extern char pathSolutions[];

#endif
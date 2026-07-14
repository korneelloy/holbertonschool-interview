#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/**
 * slide_line - reproduce the 2048 game mechanics on a single horizontal line
 *
 * @array: Pointer to the array of integer
 * @size: Number of elements in @array
 * @direction: The direction de @array should slide in
 *
 * Return : 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */

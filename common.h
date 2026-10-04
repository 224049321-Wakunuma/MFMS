#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Clear the input buffer after scanf */
void clearBuffer(void);

/* Safely read a line of text into str (removes trailing newline) */
void readString(char *str, int size);

/* Return 1 if string is empty or only whitespace, otherwise 0 */
int isEmpty(const char *str);

#endif

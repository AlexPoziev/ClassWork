#pragma once

#include <stdbool.h>

typedef struct List List;

// create list, return pointer to allocated memory for list
List* createList(void);

// addValue value to list and save sorting. Returns 1 if get problems with memory
int addValue(List *list, int value);

// delete list
void deleteList(List **list);

// build list with data from file
int getListFromFile(char *fileName, List *list);

// return true if list symmetric
// return false if list not symmetric
bool isSymmetric(List *list);
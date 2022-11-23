#pragma once
#include <stdbool.h>

typedef struct Tree Tree;

// create dictionary, need to check for NULL
Tree* createTree(void);

// add value to tree
int addValue(Tree *tree, int value);

// sort array by creating tree
// return 1 if not enough memory
// return -1 if array or tree are NULL
// return -2 if arraySize less or equal zero
// return 0 if all is ok
int sortArrayByTree(int *array, unsigned int arraySize, Tree *tree);

// deallocate dictionary's memory
void deleteTree(Tree **dictionary);
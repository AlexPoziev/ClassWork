#pragma once
#include <stdbool.h>

typedef struct Tree Tree;

// create dictionary, need to check for NULL
Tree* createTree(void);

// add value to tree
int addValue(Tree *tree, int value);

// get data from file and put in into binary tree
int buildTreeFromArray(int* array, Tree *tree);

// put (sorted) data from tree to array
int putTreeToArray(int* array, Tree *tree);

// deallocate dictionary's memory
void deleteTree(Tree **dictionary);